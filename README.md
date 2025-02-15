# InSDL

### Моя мини оболочка для SDL

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white) ![Python](https://img.shields.io/badge/python-3670A0?style=for-the-badge&logo=python&logoColor=ffdd54)

## Создать проект

### Перед началось отредактируйте путь в `main.py`
```python
from_path = '' # что будет копироваться (путь к этой папке)
to_path = '' # в какую папку будут создаваться проекты
```

---

```sh
$ insdl create PROJECT_NAME -flag # способ работает запустить файл в папке create с insdl.bat 
```

или 

```sh
$ .\create.bat
```

или 

```sh
$ python main.py create PROJECT_NAME -flag
```

`-h` - список всех команд

`-vsc` - добавления папки `.vscode` с уже настроенным **g++**

### Удалить проект

```sh
$ insdl del PROJECT_NAME # способ работает запустить файл в папке create с insdl.bat 
```

или 

```sh
$ python main.py del PROJECT_NAME
```

### Скомпилировать

```sh
$ insdl compile PROJECT_NAME # способ работает запустить файл в папке create с insdl.bat 
```

или 

```sh
$ python main.py compile PROJECT_NAME
```

или запустите `compiler.bat`

# Документация

Потом буде