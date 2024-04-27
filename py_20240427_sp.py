import os
import re
from datetime import datetime
import shutil

file_path = "/data/聊天记录/TREE(xxxxxx)/TREE.txt"

with open(file_path, "r", encoding="utf-8") as file:
    lines = file.readlines()

current_date = None
current_chat = []
for line in lines:
    match = re.match(r"(\d{4}-\d{2}-\d{2}) \d{2}:\d{2}:\d{2} \w+", line)
    if match:
        new_date = match.group(1)
        if current_date and new_date != current_date:
            with open(f"{current_date}.txt", "a", encoding="utf-8") as file:
                file.write("".join(current_chat))
            current_chat = []
        current_date = new_date
    current_chat.append(line)

if current_date:
    with open(f"{current_date}.txt", "a", encoding="utf-8") as file:
        file.write("".join(current_chat))


# 获取当前目录下的所有文件
files = os.listdir(".")

# 对于每个文件
for file in files:
    # 检查是否是.txt文件并且符合yyyy-mm-dd的格式
    if file.endswith(".txt") and re.match(r"\d{4}-\d{2}-\d{2}.txt", file):
        # 构建.md文件的路径
        md_file_path = os.path.join(file[:4], file[5:7], file.replace(".txt", ".md"))
        print(f"Checking {md_file_path}")
        # 检查.md文件是否存在
        if os.path.exists(md_file_path):
            # 如果存在，将.txt文件移动到exist文件夹
            if not os.path.exists("exist"):
                os.makedirs("exist")
            shutil.move(file, os.path.join("exist", file))
            print(f"{file} moved to exist")
