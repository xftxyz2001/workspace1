import re


def split_vcard_file(input_file_path, output_dir):
    with open(input_file_path, "r", encoding="utf-8") as file:
        content = file.read()

    # 按照vCard的分隔符分割内容
    vcard_blocks = content.split("END:VCARD")

    for block in vcard_blocks:
        if block.strip():  # 确保块不为空
            # 获取FN字段的值作为文件名
            lines = block.split("\n")
            fn_value = None
            nickname_value = None
            adr_values = []
            tel_values = []
            email_values = []
            url_values = []
            unknown_fields = []
            for line in lines:
                if line.startswith("FN:"):
                    fn_value = line.split(":")[1].strip()
                elif line.startswith("NICKNAME:"):
                    nickname_value = line.split(":")[1].strip()
                elif line.startswith("ADR;"):
                    adr_values.append(line.split(":")[1].strip().strip(";"))
                elif line.startswith("TEL;"):
                    tel_values.append(line.split(":")[1].strip())
                elif line.startswith("EMAIL;"):
                    email_values.append(line.split(":")[1].strip())
                elif line.startswith("URL:"):
                    url_values.append(line[4:-1])
                elif not line.startswith(("BEGIN:VCARD", "VERSION:3.0", "N:", "UID:")):
                    if len(line) > 0:
                        unknown_fields.append(line)

            if fn_value:
                # 构建输出文件路径
                output_file_path = f"{output_dir}/{fn_value}.md"

                # 构建新的vCard内容
                new_block = ""
                if fn_value:
                    new_block += f"- 姓名:{fn_value}\n"
                if nickname_value:
                    new_block += f"- 身份证:{nickname_value}\n"
                if tel_values:
                    for tel in tel_values:
                        new_block += f"- 手机:{tel}\n"
                if email_values:
                    for email in email_values:
                        new_block += f"- 邮箱:{email}\n"
                if url_values:
                    for url in url_values:
                        new_block += f"- 网址:{url}\n"
                if adr_values:
                    for adr in adr_values:
                        new_block += f"- 地址:{adr}\n"
                if unknown_fields:
                    new_block += "- 备注:\n"
                    for field in unknown_fields:
                        new_block += f"{field}\n"

                # 写入文件
                with open(output_file_path, "w", encoding="utf-8") as output_file:
                    output_file.write(re.sub(r"\n\s*\n", "\n", new_block))

                print(f"文件已生成：{output_file_path}")
            else:
                print("未找到FN字段，无法生成文件")
        else:
            print("空的vCard块，跳过")


# 使用示例
input_file_path = "contact.vcf"  # 输入文件路径
output_dir = "contact"  # 输出目录路径
split_vcard_file(input_file_path, output_dir)
