#include <iostream>

#include <unistd.h>

#include "editor.hpp"

using namespace std;
using namespace editor;

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        Editor editor{argv[1]};
        sleep(3);
    }
    else
    {
        cout << argv[0] << " <file>" << endl;
    }
    return 0;
}
