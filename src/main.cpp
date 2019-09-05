#include <iostream>
#include "Objects\baseobject.h"


 // https://www.40tude.fr/blog/compile-cpp-code-with-vscode-cmake-nmake/

int main() 
{
    std::cout << "Hello World\n";

    base_object* obj = new base_object();

    obj->print();

    delete obj;

    getchar();
}