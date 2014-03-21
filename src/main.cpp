#include <iostream>

#include "editor.hpp"

using namespace std;
using namespace editor;

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        cout << slurp(argv[1]) << endl;
    }
    else
    {
        cout << argv[0] << " <file>" << endl;
    }
    return 0;
}
