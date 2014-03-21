#include <iostream>

#include "buffer.hpp"
#include "editor.hpp"

using namespace std;
using namespace editor;

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        string name = argv[1];
        string text = slurp(name);

        Buffer buffer{name, text};

        cout << buffer.text() << endl;
    }
    else
    {
        cout << argv[0] << " <file>" << endl;
    }
    return 0;
}
