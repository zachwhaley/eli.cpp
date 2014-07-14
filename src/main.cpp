#include <iostream>

#include "editor.hpp"

using namespace std;
using namespace editor;

int main(int argc, char *argv[])
{
    if (argc > 1) {
        start_editing(argv[1]);
    }
    else {
        cout << argv[0] << " <file>" << endl;
    }
    return 0;
}
