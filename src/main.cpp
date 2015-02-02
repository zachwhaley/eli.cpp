#include <iostream>

#include "editor.hpp"

int main(int argc, const char *argv[])
{
    eli::Editor editor;

    if (argc > 1) {
        editor.open(argv[1]);
    }
    editor.edit();

    return 0;
}
