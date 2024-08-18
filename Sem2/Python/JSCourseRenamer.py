import os
import re

def rename_files_with_number(folder_path):
    
    files = os.listdir(folder_path)
    for filename in files:
        old_file_path = os.path.join(folder_path, filename)
        bracket_index = filename.find("(")
        underscore_index = filename.find("_", bracket_index - 4, bracket_index)
        finalname = filename[(underscore_index + 1):(bracket_index)]
        new_file_path = os.path.join(folder_path, finalname)
        new_file_path = new_file_path + ".mp4"
        os.rename(old_file_path, new_file_path)
        print(old_file_path)
        print(new_file_path)
        print(bracket_index)

if __name__ == "__main__":
    folder_path = "D:\SnapTube Video"  # Replace this with the actual path to your folder
    rename_files_with_number(folder_path)
