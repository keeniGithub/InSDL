# InSDL

### Моя мини оболочка для SDL

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white) ![Python](https://img.shields.io/badge/python-3670A0?style=for-the-badge&logo=python&logoColor=ffdd54)

## Создать проект

### Перед началось отредактируйте путь в `main.py`
```python
from_path = 'Z:/cpp/engine' # что будет копироваться (путь к этой папке)
to_path = 'Z:/cpp/' # в какую папку будут создаваться проекты
# ПУТЬ К to_path ОБЯЗАТЕЛЬНО УКАЗЫВАТЬ С / НА КОНЦЕ! либо отредактируйте create/project.py
```

---

```sh
$ insdl create PROJECT_NAME -flag # если переместить create/insdl.bat в папку с перменными среды, к примеру C:/Windows
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
$ insdl del PROJECT_NAME # если переместить create/insdl.bat в папку с перменными среды, к примеру C:/Windows
```

ну и все способы сверху

# Документация

Потом буде