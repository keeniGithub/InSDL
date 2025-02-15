import create.create as main
import create.disk as disk # получает букву диска где находится данный файл (не обязтаельно, можете изменить ниже)

from_path = f'{disk.disk_letter()}/cpp/engine' # что будет копироваться (путь к этой папке)
to_path = f'{disk.disk_letter()}/cpp' # в какую папку будут создаваться проекты

if __name__ == "__main__":
    main.main()