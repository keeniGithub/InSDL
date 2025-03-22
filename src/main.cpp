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