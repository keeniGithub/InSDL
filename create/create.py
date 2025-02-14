import argparse
from create.project import create, delete

def main():
    parser = argparse.ArgumentParser(description="Команда для создания проекта на InSDL")
    parser.add_argument('command', choices=['create', 'del'], help='Команда для выполнения')
    parser.add_argument('folder_name', type=str, help='Название папки для проекта')
    parser.add_argument('-vsc', action='store_true', help='Добавить папку .vscode')

    args = parser.parse_args()

    if args.command == 'create':
        create(args.folder_name, keep_vscode=args.vsc)
    elif args.command == 'del':
        delete(args.folder_name)
