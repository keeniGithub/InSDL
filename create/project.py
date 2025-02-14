import os
import shutil
from create.files import copy

def create(folder_name, keep_vscode=False):
    source_folder = 'Z:/cpp/engine'
    destination_folder = f'Z:/cpp/{folder_name}'

    os.makedirs(destination_folder, exist_ok=True)

    copy(source_folder, destination_folder, keep_vscode)

    print(f"Проект '{folder_name}' успешно создан!")

def delete(folder_name):
    destination_folder = f'Z:/cpp/{folder_name}'

    if os.path.exists(destination_folder):
        shutil.rmtree(destination_folder)
        print(f"Проект '{folder_name}' успешно удален!")
    else:
        print(f"Проект '{folder_name}' не найден!")