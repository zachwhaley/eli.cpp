#include <iostream>

#include <curses.h>
#include <unistd.h>

#include "buffer.hpp"
#include "editor.hpp"

using namespace std;
using namespace editor;

int main(int argc, char *argv[])
{
    WINDOW *mainwin = initscr();
    if (mainwin == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (argc > 1)
    {
        string name = argv[1];
        string text = slurp(name);

        Buffer buffer{name, text};

        mvaddstr(0, 0, buffer.text().c_str());
        refresh();
        sleep(3);
    }
    else
    {
        cout << argv[0] << " <file>" << endl;
    }

    delwin(mainwin);
    endwin();
    refresh();
    return 0;
}
