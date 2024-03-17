import re

with open('车23混输站模型.wlkx.xml', 'r', encoding='utf-8') as file:
    content = file.read()

pattern = r'(<object[^>]*>(?:(?!<object).)*<object id="\d+"/>.*?</object>)'
matches = re.findall(pattern, content, re.DOTALL)

for match in matches:
    print(match)
    print('-------------------')

