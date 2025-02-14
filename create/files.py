import os
import shutil

def copy(source_folder, destination_folder, keep_vscode=False):
    for dirpath, dirnames, filenames in os.walk(source_folder):
        if 'create' in dirnames:
            dirnames.remove('create')
        if '.git' in dirnames:
            dirnames.remove('.git')
        if not keep_vscode and '.vscode' in dirnames:
            dirnames.remove('.vscode')

        relative_path = os.path.relpath(dirpath, source_folder)
        destination_path = os.path.join(destination_folder, relative_path)

        os.makedirs(destination_path, exist_ok=True)

        for filename in filenames:
            source_file = os.path.join(dirpath, filename)
            destination_file = os.path.join(destination_path, filename)
            shutil.copy2(source_file, destination_file)
