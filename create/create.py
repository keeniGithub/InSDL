import argparse
import os
import main as main_file
from create.project import create, delete

path = main_file.to_path

def main():
    parser = argparse.ArgumentParser(description="Create InSDL project")
    parser.add_argument('command', choices=['create', 'compile', 'del'], help='Command')
    parser.add_argument('name', type=str, help='Project name')
    parser.add_argument('-vsc', action='store_true', help='add .vscode folder')
    parser.add_argument('-bat', action='store_true', help='add compile.bat file')

    args = parser.parse_args()

    if args.command == 'create':
        create(args.name, keep_vscode=args.vsc, keep_batch=args.bat)
    elif args.command == 'del':
        delete(args.name)
    elif args.command == 'compile':
        os.system(f"cd {path}/{args.name}")
        os.system(f".\compiler.bat")
