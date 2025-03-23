# InSDL

### Небольшой фреймворк для SDL

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white) ![Python](https://img.shields.io/badge/python-3670A0?style=for-the-badge&logo=python&logoColor=ffdd54)

## Создание проекта

### Настройка путей в `main.py`

Перед началом работы отредактируйте пути в файле `main.py`:

```python
from_path = ''  # Путь к папке, откуда будут копироваться файлы
to_path = ''    # Путь к папке, куда будут создаваться проекты
```

### Команды для создания проекта

Чтобы создать новый проект, выполните одну из следующих команд:

```sh
$ insdl create PROJECT_NAME -flag  # Запустите файл из папки create с insdl.bat
```

или 

```sh
$ .\create.bat
```

или 

```sh
$ python main.py create PROJECT_NAME -flag
```

- `-h` — выводит список всех доступных команд.
- `-vsc` — добавляет папку `.vscode` с уже настроенным **g++**.
- `-bat` — добавлять файл `compile.bat` к вам в проект

### Удаление проекта

Чтобы удалить проект, используйте одну из следующих команд:

```sh
$ insdl del PROJECT_NAME  # Запустите файл из папки create с insdl.bat
```

или 

```sh
$ python main.py del PROJECT_NAME
```

### Компиляция проекта

Для компиляции проекта выполните одну из следующих команд:

```sh
$ insdl compile PROJECT_NAME  # Запустите файл из папки create с insdl.bat
```

или 

```sh
$ python main.py compile PROJECT_NAME
```

или запустите `compiler.bat`.

---

# Документация

## Основные классы

### Класс `app`
Класс `app` отвечает за создание окна, обработку событий и управление графикой.

#### Члены класса
- **`SDL_Window *Window`**: Указатель на окно SDL.
- **`SDL_Surface *Surface`**: Указатель на поверхность окна.
- **`SDL_Renderer *Render`**: Указатель на рендерер.
- **`bool quit`**: Флаг для выхода из приложения.
- **`vector<keyBindStruct> keyBindings`**: Вектор для хранения привязок клавиш.
- **`vector<mouseBindStruct> mouseBindings`**: Вектор для хранения привязок кнопок мыши.
- **`vector<mouseMotionBindStruct> mouseMotionBindings`**: Вектор для хранения привязок движения мыши.
- **`colorStruct color`**: Структура для хранения цвета.
- **`windowStruct window`**: Структура для хранения параметров окна.

#### Методы
- **`void init(int width, int height, string name, bool render = false)`**: Инициализация окна.
- **`void fill(Uint8 r = -1, Uint8 g = -1, Uint8 b = -1)`**: Заполнение окна цветом.
- **`void update()`**: Обновление содержимого окна.
- **`void setIcon(texture icon) `**: Установить иконку окна.
- **`void change(int width, int height, string name)`**: Изменение размера и названия окна.
- **`void exit()`**: Закрытие приложения.
- **`template<typename Func> void bindKey(SDL_Scancode key, Func func)`**: Привязка функции к нажатию клавиши.
- **`template<typename Func> void bindMouseButton(Uint8 button, Func func)`**: Привязка функции к нажатию кнопки мыши.
- **`template<typename Func> void bindMouseMotion(Func func)`**: Привязка функции к движению мыши.

---

### Класс `text`
Класс `text` создает текст и позволяет управлять его содержимым, цветом и текстурой.

#### Конструктор
- **`text(SDL_Renderer *render, const string& text, string file, Uint8 r = 255, Uint8 g = 255, Uint8 b = 255)`**  
  Создает текст с заданным содержимым, шрифтом и цветом.  
  - `render`: Указатель на рендерер SDL.  
  - `text`: Текст для отображения.  
  - `file`: Путь к файлу шрифта.  
  - `r`, `g`, `b`: Цвет текста (по умолчанию белый).

#### Методы
- **`void destroy()`**  
  Уничтожает текстуру и поверхность текста.

- **`void setText(const string& newText)`**  
  Изменяет текст и обновляет текстуру.  
  - `newText`: Новый текст для отображения.

- **`void setColor(Uint8 r = -1, Uint8 g = -1, Uint8 b = -1)`**  
  Изменяет цвет текста и обновляет текстуру.  
  - `r`, `g`, `b`: Новый цвет текста (если не указан, используется текущий цвет).

- **`textData get()`**  
  Возвращает данные текста, включая текстуру, поверхность, шрифт и цвет.

---

### Класс `rect`
Класс `rect` представляет собой прямоугольник и позволяет управлять его размерами, положением и цветом.

#### Конструктор
- **`rect(int x = 0, int y = 0, int w = 0, int h = 0)`**  
  Создает прямоугольник с заданными координатами и размерами.  
  - `x`, `y`: Координаты верхнего левого угла.  
  - `w`, `h`: Ширина и высота прямоугольника.

#### Методы
- **`void setRect(int x, int y, int w, int h)`**  
  Устанавливает координаты и размеры прямоугольника.

- **`void setPosition(int x, int y)`**  
  Устанавливает позицию прямоугольника.

- **`void setSize(int w, int h)`**  
  Устанавливает размеры прямоугольника.

- **`void setX(int x)`**, **`void setY(int y)`**, **`void setWidth(int w)`**, **`void setHeight(int h)`**  
  Устанавливают соответствующие параметры прямоугольника.

- **`void addX(int x)`**, **`void addY(int y)`**, **`void addWidth(int w)`**, **`void addHeight(int h)`**  
  Увеличивают соответствующие параметры прямоугольника.

- **`void subX(int x)`**, **`void subY(int y)`**, **`void subWidth(int w)`**, **`void subHeight(int h)`**  
  Уменьшают соответствующие параметры прямоугольника.

- **`int getX()`**, **`int getY()`**, **`int getWidth()`**, **`int getHeight()`**  
  Возвращают соответствующие параметры прямоугольника.

- **`SDL_Rect get()`**  
  Возвращает структуру `SDL_Rect`.

- **`void fill(SDL_Surface *surface, Uint8 r = -1, Uint8 g = -1, Uint8 b = -1)`**  
  Заполняет прямоугольник цветом на указанной поверхности.

- **`void update(SDL_Surface *surface)`**  
  Обновляет прямоугольник на указанной поверхности.

---

### Класс `frect`
Класс `frect` представляет собой прямоугольник с плавающими координатами и позволяет управлять его размерами, положением и цветом.

#### Конструктор
- **`frect(int x = 0, int y = 0, int w = 0, int h = 0)`**  
  Создает прямоугольник с заданными координатами и размерами.  
  - `x`, `y`: Координаты верхнего левого угла.  
  - `w`, `h`: Ширина и высота прямоугольника.

#### Методы
- **`void setFrect(int x, int y, int w, int h)`**  
  Устанавливает координаты и размеры прямоугольника.

- **`void setPosition(int x, int y)`**  
  Устанавливает позицию прямоугольника.

- **`void setSize(int w, int h)`**  
  Устанавливает размеры прямоугольника.

- **`void setX(int x)`**, **`void setY(int y)`**, **`void setWidth(int w)`**, **`void setHeight(int h)`**  
  Устанавливают соответствующие параметры прямоугольника.

- **`void addX(int x)`**, **`void addY(int y)`**, **`void addWidth(int w)`**, **`void addHeight(int h)`**  
  Увеличивают соответствующие параметры прямоугольника.

- **`void subX(int x)`**, **`void subY(int y)`**, **`void subWidth(int w)`**, **`void subHeight(int h)`**  
  Уменьшают соответствующие параметры прямоугольника.

- **`int getX()`**, **`int getY()`**, **`int getWidth()`**, **`int getHeight()`**  
  Возвращают соответствующие параметры прямоугольника.

- **`SDL_FRect get()`**  
  Возвращает структуру `SDL_FRect`.

- **`void fill(SDL_Renderer *render, Uint8 r = -1, Uint8 g = -1, Uint8 b = -1, Uint8 alpha = -1)`**  
  Заполняет прямоугольник цветом на указанном рендерере.

- **`void fillTexture(SDL_Renderer *render, texture *texture)`**  
  Заполняет прямоугольник текстурой.

- **`void fillText(SDL_Renderer *render, text *text)`**  
  Заполняет прямоугольник текстом.

---

### Класс `texture`
Класс `texture` управляет текстурами, загружая их из файлов.

#### Конструктор
- **`texture(SDL_Renderer *render, const char *file)`**  
  Загружает текстуру из файла BMP.  
  - `render`: Указатель на рендерер SDL.  
  - `file`: Путь к файлу BMP.

#### Методы
- **`textureData get()`**  
  Возвращает данные текстуры.

- **`void destroy()`**  
  Уничтожает текстуру.


---

## Библиотека задержек
InSDL также включает простую [библиотеку](https://github.com/keenigithub/SimpleCppDelay) для создания задержек.

### Методы задержки
- **`void delayms(int msec)`**: Задержка в миллисекундах.
- **`void delaysc(int sec)`**: Задержка в секундах.
- **`void delaymn(int min)`**: Задержка в минутах.
- **`void delayhr(int hour)`**: Задержка в часах.

---

## Файл `event.hpp`

#### Функции

Используются только в начале основного цикла

Внутрь передается аргумент `app& app` — объект приложения.

- **`void exitEvent(app& app)`**: 
  Обрабатывает событие выхода из приложения.

- **`void handleEvent(app& app)`**: 
  Обрабатывает все события (клавиши, мышь и тд).

---

# Шаблон использования
```cpp
#include <InSDL.hpp>

int main()
{
    app myapp;
    myapp.init(700, 700, "My InSDL Window");

    while (!myapp.quit) {
        handleEvent(myapp);
        
        // code here

        myapp.update();
    }

    myapp.exit();
    return 0;
}
```