import os
import shutil

def copy(source_folder, destination_folder, keep_vscode=False, keep_batch=False):
    for dirpath, dirnames, filenames in os.walk(source_folder):
        if 'create' in dirnames:
            dirnames.remove('create')
        if '.git' in dirnames:
            dirnames.remove('.git')
        if '__pycache__' in dirnames:
            dirnames.remove('__pycache__')
        if not keep_vscode and '.vscode' in dirnames:
            dirnames.remove('.vscode')

        relative_path = os.path.relpath(dirpath, source_folder)
        destination_path = os.path.join(destination_folder, relative_path)

        os.makedirs(destination_path, exist_ok=True)

        for filename in filenames:
            if filename in ['main.py', 'create.bat', 'myCompile.bat', 'README.md', '.gitignore', 'main.exe', 'main_build.exe', 'test.cpp']:
                continue
            if filename == 'compile.bat' and not keep_batch:
                continue
            source_file = os.path.join(dirpath, filename)
            destination_file = os.path.join(destination_path, filename)
            shutil.copy2(source_file, destination_file)

    readme_path = os.path.join(destination_folder, 'README.md')
    gitignore_path = os.path.join(destination_folder, '.gitignore')
    os.system(f'type nul >{readme_path}')
    os.system(f'type nul >{gitignore_path}')
