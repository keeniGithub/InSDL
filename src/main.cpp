#include <InSDL.hpp>

int main()
{
    app myapp;
    myapp.init(1000, 500, "My InSDL Window");

    while (!myapp.quit) {
        handleEvent(myapp);
        
        // code here

        myapp.update();
    }

    myapp.destroy();
    return 0;
}