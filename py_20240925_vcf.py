import re
from pypinyin import lazy_pinyin

order = [
    "N",
    "FN",
    "TEL;TYPE=mobile",
    "TEL;TYPE=WORK",
    "EMAIL;TYPE=HOME",
    "EMAIL;TYPE=WORK",
    "ADR;TYPE=HOME",
    "ADR;TYPE=WORK",
    "NICKNAME",
    "X-QQ",
    "URL",
    "NOTE",
]


def mysorted(item):
    lines = item.splitlines()[2:-1]  # 去掉 BEGIN:VCARD 和 END:VCARD 以及 VERSION:3.0

    ordered_lines = []
    remaining_lines = []

    for line in lines:
        key = line.split(":")[0]
        if key in order:
            ordered_lines.append(
                (order.index(key), line)
            )  # 使用字段在 order 中的索引作为排序依据
        else:
            remaining_lines.append(line)  # 未出现的字段

    ordered_lines.sort(key=lambda x: x[0])

    if len(remaining_lines) > 0:
        print(remaining_lines)
    sorted_lines = [line for _, line in ordered_lines] + remaining_lines

    return "BEGIN:VCARD\nVERSION:3.0\n" + "\n".join(sorted_lines) + "\nEND:VCARD"


def extract_and_sort_vcards_by_pinyin(matches):
    vcard_list = []

    for mm in matches:
        fn_match = re.search(r"FN:(.+)", mm)
        fn = fn_match.group(1) if fn_match else ""

        vcard_list.append({"vcard": mm, "fn": fn})

    sorted_vcards = sorted(vcard_list, key=lambda x: lazy_pinyin(x["fn"]))
    return [v["vcard"] for v in sorted_vcards]


with open("./111.vcf", "r", encoding="utf-8") as f:
    content = f.read()
matches = re.findall(r"BEGIN:VCARD[\s\S]+?END:VCARD", content)

# with open("./000.vcf", "w", encoding="utf-8") as f:
#     for item in matches:
#         f.write(mysorted(item) + "\n\n")

res = extract_and_sort_vcards_by_pinyin(matches)
with open("./222.vcf", "w", encoding="utf-8") as f:
    for vcard in res:
        f.write(vcard + "\n\n")
