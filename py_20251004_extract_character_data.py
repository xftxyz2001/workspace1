from bs4 import BeautifulSoup
import re


def extract_character_data(html_file):
    """
    从HTML文件中提取角色数据
    """
    with open(html_file, "r", encoding="utf-8") as file:
        content = file.read()

    soup = BeautifulSoup(content, "html.parser")

    # 查找所有角色数据块（每个角色由rowspan="2"的td标识）
    character_rows = soup.find_all("td", attrs={"rowspan": "2"})

    results = []

    for row in character_rows:
        # 提取角色名称
        character_link = row.find("a")
        if not character_link:
            continue
        character_name = character_link.get("title", "")

        # 获取同一<tr>下的所有<td>元素（技能数据）
        parent_tr = row.parent
        all_tds = parent_tr.find_all("td")

        # 技能数据在角色名之后的td中
        skill_data = []
        for td in all_tds[1:]:  # 跳过第一个td（角色名）
            # 提取技能描述（冒号后到<span>标签前的内容）
            td_text = td.get_text(strip=True)
            # 使用正则表达式提取描述部分
            description_match = re.search(r"[^\n]*：(.+?)\s*经WIKI", td_text)
            if not description_match:
                # 尝试另一种方式提取
                description_match = re.search(r"：(.+)", td_text)

            description = (
                description_match.group(1).strip() if description_match else ""
            )

            # 提取上限数值
            highlighter_span = td.find("span", class_="smw-highlighter")
            if not highlighter_span:
                continue

            title_attr = highlighter_span.get("title", "")
            limit_match = re.search(r"单局上限为(\d+)", title_attr)
            limit_value = limit_match.group(1) if limit_match else ""

            if description and limit_value:
                skill_data.append(f"{description}{limit_value}")

        # 格式化输出
        if skill_data:
            result = f"{character_name}：" + "\t".join(skill_data)
            results.append(result)

    return results


def main():
    """
    主函数
    """
    html_file = "test.html"

    try:
        extracted_data = extract_character_data(html_file)

        # 输出结果
        for data in extracted_data:
            print(data)

        # 可选：保存到文件
        with open("extracted_data.txt", "w", encoding="utf-8") as output_file:
            for data in extracted_data:
                output_file.write(data + "\n")

        print(f"\n总共提取了 {len(extracted_data)} 个角色的数据")

    except FileNotFoundError:
        print(f"错误：找不到文件 {html_file}")
    except Exception as e:
        print(f"处理文件时出错：{e}")


if __name__ == "__main__":
    main()
