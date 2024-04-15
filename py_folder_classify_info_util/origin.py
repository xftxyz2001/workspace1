import os
import glob
import datetime
import pandas as pd


class Util:
    @classmethod
    def generate_folder_classify_info(folder_path, extension):
        """
        更新文件更新信息
        """

        # 构建文件路径匹配模式
        pattern = folder_path + "/" + extension
        # 获取匹配的文件列表2
        file_lists = glob.glob(pattern)

        result_file = os.path.join(folder_path, "classify_result.csv")
        # 检查文件是否存在
        if not os.path.exists(result_file):

            # 文件不存在
            file_name = []
            classify_state = []
            last_refesh_file_time = []
            file_size = []
            file_class = []

            for i, file in enumerate(file_lists):
                file_path = os.path.join(folder_path, file)
                file_name.append(file)
                classify_state.append("未分类")
                last_modified = datetime.datetime.fromtimestamp(
                    os.path.getmtime(file_path)
                )
                last_refesh_file_time.append(last_modified)
                file_size.append(f"{os.path.getsize(file_path) / 2 ** 20}MB")
                file_class.append("")
                pass

            data_dict = {
                "文件名": file_name,
                "分类状态": classify_state,
                "最后更新时间": last_refesh_file_time,
                "大小": file_size,
                "类别": file_class,
            }
            result_data = pd.DataFrame(data_dict)
            result_data.to_csv(result_file, index=False)
            print("生成文件夹分类信息")
        else:
            file_name = []
            classify_state = []
            last_refesh_file_time = []
            file_size = []
            file_class = []

            result_df = pd.read_csv(result_file)
            for i, file in file_lists:
                index = result_df["文件名"].eq(file).idxmax()
                if file in result_df["文件名"]:
                    file_name.append()
                    pass
                pass

            result_df.sort_values(by="文件名", ascending=True)
            file_lists.sort()

            # 如果有文件不在分类表格中，那么就新建一个这个的行
            for i, file in enumerate(file_lists):
                file_path = os.path.join(folder_path, file)
                last_modified = datetime.datetime.fromtimestamp(
                    os.path.getmtime(file_path)
                )
                if file != result_df["文件名"][i]:
                    new_row = {
                        "文件名": file,
                        "分类状态": "未分类",
                        "最后更新时间": last_modified,
                        "大小": f"{os.path.getsize(file_path) / 2 ** 20}MB",
                        "类别": "",
                    }
                    result_df = pd.concat(
                        [
                            result_df.loc[:i],
                            pd.DataFrame(new_row, index=[i]),
                            result_df.loc[i:],
                        ]
                    ).reset_index(drop=True)
                elif last_modified != result_df["最后更新时间"]:
                    result_df["最后更新时间"][i] = last_modified
                    result_df["大小"][i] = f"{os.path.getsize(file_path) / 2 ** 20}MB"
                    result_df["分类状态"][i] = "未分类"
                    result_df["类别"][i] = ""
                    pass
                pass
            result_data.to_csv(result_file, index=False)
            print("更新文件夹分类信息")
            pass
        pass

    pass
