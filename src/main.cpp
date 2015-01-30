#include <iostream>

#include "editor.hpp"

using namespace std;
using namespace eli;

int main(int argc, char *argv[])
{
    Editor editor;
    if (argc > 1) {
        editor.open(argv[1]);
    }
    else {
        cout << argv[0] << " <file>" << endl;
    }
    return 0;
}
