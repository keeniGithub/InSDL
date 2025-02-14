#include <iostream>
#include <InSDL.hpp>

void fun(int x){
    std::cout<<"wefwefewf";
}

int main()
{
    app myapp;
    myapp.init(1000, 500, "My InSDL Window");
    myapp.bindKey(SDL_SCANCODE_A, [&]() { fun(1); });

    while (!myapp.quit) {
        handleEvent(myapp);

        // code here
    }

    myapp.destroy();
    return 0;
}