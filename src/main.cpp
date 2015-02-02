#include <iostream>

#include "editor.hpp"

using namespace eli;

int main(int argc, const char *argv[])
{
    Editor editor;

    if (argc > 1) {
        editor.open(argv[1]);
    }
    editor.edit();

    return 0;
}
