import os
import zipfile
import tempfile
import tkinter as tk
from tkinter import ttk, filedialog, messagebox


def make_zip_from_file_or_dir(input_path):
    temp_zip = tempfile.mktemp(suffix=".zip")
    with zipfile.ZipFile(temp_zip, "w", zipfile.ZIP_DEFLATED) as zipf:
        if os.path.isdir(input_path):
            for root, _, files in os.walk(input_path):
                for file in files:
                    full_path = os.path.join(root, file)
                    arcname = os.path.relpath(full_path, input_path)
                    zipf.write(full_path, arcname)
        else:
            zipf.write(input_path, os.path.basename(input_path))
    return temp_zip


def merge_files(img, target):
    is_zip = zipfile.is_zipfile(target)
    zip_to_merge = target if is_zip else make_zip_from_file_or_dir(target)

    base, ext = os.path.splitext(img)
    output = base + "_ex" + ext

    with open(img, "rb") as f_img, open(zip_to_merge, "rb") as f_zip, open(
        output, "wb"
    ) as f_out:
        f_out.write(f_img.read())
        f_out.write(f_zip.read())

    if not is_zip:
        os.remove(zip_to_merge)
    return output


def extract_embedded_zip(mixed_file):
    with open(mixed_file, "rb") as f:
        data = f.read()
        zip_header = b"PK\x03\x04"
        idx = data.find(zip_header)
        if idx == -1:
            raise ValueError("未找到 zip 数据头，文件可能未合并或已损坏。")
        zip_data = data[idx:]
        temp_zip = tempfile.mktemp(suffix=".zip")
        with open(temp_zip, "wb") as f_zip:
            f_zip.write(zip_data)

    out_dir = os.path.splitext(mixed_file)[0]
    os.makedirs(out_dir, exist_ok=True)
    with zipfile.ZipFile(temp_zip, "r") as zipf:
        zipf.extractall(out_dir)
    os.remove(temp_zip)
    return out_dir


# UI
def run_gui():
    root = tk.Tk()
    root.title("图片 + 文件 合并/提取工具")
    root.geometry("560x300")
    root.resizable(False, False)

    notebook = ttk.Notebook(root)
    notebook.pack(fill="both", expand=True)

    merge_tab = ttk.Frame(notebook)
    extract_tab = ttk.Frame(notebook)
    notebook.add(merge_tab, text="合并")
    notebook.add(extract_tab, text="提取")

    img_var = tk.StringVar()
    target_var = tk.StringVar()

    mixed_var = tk.StringVar()

    # 进度条
    progress = ttk.Progressbar(root, mode="determinate", maximum=100)
    progress.pack(fill="x", padx=10, pady=(0, 10))

    def choose_img():
        path = filedialog.askopenfilename(filetypes=[("Images", "*.jpg *.png *.jpeg")])
        if path:
            img_var.set(path)

    def choose_target():
        path = filedialog.askopenfilename(title="选择文件") or filedialog.askdirectory(
            title="选择文件夹"
        )
        if path:
            target_var.set(path)

    def do_merge_gui():
        try:
            if not img_var.get() or not target_var.get():
                raise ValueError("请填写所有路径")
            progress.start()
            output_path = merge_files(img_var.get(), target_var.get())
            progress.stop()
            progress["value"] = 100
            messagebox.showinfo("合并成功", f"文件已保存至：\n{output_path}")
        except Exception as e:
            progress.stop()
            messagebox.showerror("错误", str(e))
        finally:
            progress["value"] = 0

    def row(parent, label, var, browse_fn):
        f = tk.Frame(parent)
        f.pack(padx=10, pady=5, fill="x")
        tk.Label(f, text=label, width=12, anchor="w").pack(side="left")
        tk.Entry(f, textvariable=var, width=45).pack(side="left", padx=5)
        tk.Button(f, text="浏览", command=browse_fn).pack(side="left")

    row(merge_tab, "图片文件：", img_var, choose_img)
    row(merge_tab, "目标文件：", target_var, choose_target)
    tk.Button(
        merge_tab, text="开始合并", command=do_merge_gui, bg="#ccf", height=2
    ).pack(pady=15)

    def choose_mixed():
        path = filedialog.askopenfilename(filetypes=[("Images", "*.jpg *.jpeg *.png")])
        if path:
            mixed_var.set(path)

    def do_extract_gui():
        try:
            if not mixed_var.get():
                raise ValueError("请选择合并后的图片")
            progress.start()
            outdir = extract_embedded_zip(mixed_var.get())
            progress.stop()
            progress["value"] = 100
            messagebox.showinfo("提取成功", f"内容已提取到：\n{outdir}")
        except Exception as e:
            progress.stop()
            messagebox.showerror("错误", str(e))
        finally:
            progress["value"] = 0

    row(extract_tab, "合并图片：", mixed_var, choose_mixed)
    tk.Button(
        extract_tab, text="开始提取", command=do_extract_gui, bg="#cfc", height=2
    ).pack(pady=15)

    root.mainloop()


if __name__ == "__main__":
    run_gui()
