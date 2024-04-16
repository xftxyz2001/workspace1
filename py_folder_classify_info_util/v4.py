import os
import glob
import pandas as pd
from datetime import datetime


class FolderClassifyInfo:
    def __init__(self, folder_path, extension):
        self._folder_path = folder_path
        self._extension = extension
        self._classify_info_file = "classify_result.csv"
        self._result_file = os.path.join(folder_path, self._classify_info_file)
        self._df = self._refresh()

    def _refresh(self):
        # 构建文件路径匹配模式
        pattern = os.path.join(folder_path, extension)
        # 获取匹配的文件列表
        file_lists = glob.glob(pattern)

        # 检查结果文件是否存在
        if not os.path.exists(self._result_file):
            # 如果不存在，创建一个新的文件，并写入表头
            df = pd.DataFrame(
                columns=["文件名", "分类状态", "最后更新时间", "大小", "类别"]
            )
            df.to_csv(self._result_file, index=False)
        else:
            # 如果文件存在，直接读取
            df = pd.read_csv(self._result_file)

        # 创建一个字典来存储文件名和对应的索引
        file_index_dict = {row["文件名"]: idx for idx, row in df.iterrows()}
        new_files = []  # 用来存储新的文件信息

        for file in file_lists:
            # 获取文件名，最后更新时间，大小
            file_info = os.stat(file)
            file_name = os.path.basename(file)
            last_modified_time = datetime.fromtimestamp(file_info.st_mtime).strftime(
                "%Y-%m-%d %H:%M:%S"
            )
            file_size = f"{round(file_info.st_size / (2**20), 2)}MB"

            # 使用字典来查找文件信息
            idx = file_index_dict.get(file_name)
            if idx is not None:
                if (
                    df.loc[idx, "最后更新时间"] == last_modified_time
                    and df.loc[idx, "大小"] == file_size
                ):
                    continue  # 如果文件信息已经存在并且没有变化，跳过这个文件
                # 文件信息有变化
                df.loc[idx, "最后更新时间"] = last_modified_time
                df.loc[idx, "大小"] = file_size
                df.loc[idx, "分类状态"] = "未分类"
                df.loc[idx, "类别"] = ""
                continue

            # 文件信息不存在
            new_files.append(
                {
                    "文件名": file_name,
                    "分类状态": "未分类",
                    "最后更新时间": last_modified_time,
                    "大小": file_size,
                    "类别": "",
                }
            )

        # 一次性添加所有新的文件信息到DataFrame中
        df = pd.concat([df, pd.DataFrame(new_files)], ignore_index=True)

        # 获取所有文件名
        all_file_names = [os.path.basename(file) for file in file_lists]
        # 删除CSV文件中那些不在文件列表中的文件信息
        df = df[df["文件名"].isin(all_file_names)]

        # 保存结果到csv文件
        df.to_csv(self._result_file, index=False)

        return df

    def get(self):
        return self._df

    def save(self):
        self._df.to_csv(self._result_file, index=False)

    def classify(self, file_name, category):
        idx = self._df[self._df["文件名"] == file_name].index
        if len(idx) == 0:
            raise ValueError(f"文件 {file_name} 不存在")
        self._df.loc[idx, "分类状态"] = "已分类"
        self._df.loc[idx, "类别"] = category

    def unclassify(self, file_name):
        idx = self._df[self._df["文件名"] == file_name].index
        if len(idx) == 0:
            raise ValueError(f"文件 {file_name} 不存在")
        self._df.loc[idx, "分类状态"] = "未分类"
        self._df.loc[idx, "类别"] = ""

    def refresh(self):
        self._df = self._refresh()


if __name__ == "__main__":
    folder_path = "."
    extension = "*.py"
    fci = FolderClassifyInfo(folder_path, extension)
    print(fci.get())
    fci.save()
