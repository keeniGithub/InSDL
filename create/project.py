import os
import shutil
from create.files import copy
from main import from_path, to_path

def create(folder_name, keep_vscode=False):
    source_folder = from_path
    destination_folder = f'{to_path}{folder_name}'

    os.makedirs(destination_folder, exist_ok=True)

    copy(source_folder, destination_folder, keep_vscode)

    print(f"Проект '{folder_name}' успешно создан!")

def delete(folder_name):
    destination_folder = f'{to_path}{folder_name}'

    if os.path.exists(destination_folder):
        shutil.rmtree(destination_folder)
        print(f"Проект '{folder_name}' успешно удален!")
    else:
        print(f"Проект '{folder_name}' не найден!")