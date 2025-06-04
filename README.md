<img src="logo.png" width="300px">

# InSDL — фреймворк для SDL3

![C++](https://camo.githubusercontent.com/88e1b21c4e11afd4f06cfb2b510dbb3690dbd300fb1a6d4676fd553a70bafa82/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f632b2b2d2532333030353939432e7376673f7374796c653d666f722d7468652d6261646765266c6f676f3d63253242253242266c6f676f436f6c6f723d7768697465)

Скачать для добавление в проект можно во вкладке [Релизов](https://github.com/keeniGithub/InSDL/releases)

Для удобной работы с проектами используйте [InSDL Create](https://github.com/Qualsu/InSDL_create)


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