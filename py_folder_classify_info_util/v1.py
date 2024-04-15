import os
import glob
import pandas as pd
from datetime import datetime


def generate_folder_classify_info(folder_path=".", extension="*.tif"):
    """更新指定目录下的文件信息

    Args:
        folder_path (str): 路径
        extension (str): 扩展名（eg: *.tif）
    """

    # 构建文件路径匹配模式
    pattern = os.path.join(folder_path, extension)
    # 获取匹配的文件列表
    file_lists = glob.glob(pattern)

    result_file = os.path.join(folder_path, "classify_result.csv")

    # 检查结果文件是否存在
    if not os.path.exists(result_file):
        # 如果不存在，创建一个新的文件，并写入表头
        df = pd.DataFrame(
            columns=["文件名", "分类状态", "最后更新时间", "大小", "类别"]
        )
        df.to_csv(result_file, index=False)
    else:
        # 如果文件存在，直接读取
        df = pd.read_csv(result_file)

    # 遍历文件列表，获取文件信息
    for file in file_lists:
        file_info = os.stat(file)
        # 获取文件名，最后更新时间，大小
        file_name = os.path.basename(file)
        last_modified_time = datetime.fromtimestamp(file_info.st_mtime).strftime(
            "%Y-%m-%d %H:%M:%S"
        )
        file_size = f"{round(file_info.st_size / (2**20), 2)}MB"

        # 检查文件是否已经存在于CSV文件中，并且没有发生变化
        existing_file = df[
            (df["文件名"] == file_name)
            & (df["最后更新时间"] == last_modified_time)
            & (df["大小"] == file_size)
        ]
        if existing_file.empty:
            # 如果文件信息不存在或者有变化，使用新的文件信息，并将分类状态设置为"未分类"
            new_file = pd.DataFrame(
                {
                    "文件名": [file_name],
                    "分类状态": ["未分类"],
                    "最后更新时间": [last_modified_time],
                    "大小": [file_size],
                    "类别": [""],
                }
            )
            df = pd.concat([df, new_file], ignore_index=True)

    # 获取所有文件名
    all_file_names = [os.path.basename(file) for file in file_lists]
    # 重置df的索引
    df = df.reset_index(drop=True)
    # 删除CSV文件中那些不在文件列表中的文件信息
    df = df[df["文件名"].isin(all_file_names)]

    # 保存结果到csv文件
    df.to_csv(result_file, index=False)


if __name__ == "__main__":
    generate_folder_classify_info()
