#include <iostream>
#include <InSDL.hpp>

int main()
{
    app myapp;
    myapp.init(1000, 500, "My InSDL Window");

    while (!myapp.quit) {
        exitEvent(myapp);

        // code here
    }

    myapp.destroy();
    return 0;
}