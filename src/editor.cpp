#include "editor.hpp"

#include <unistd.h>

#include "buffer.hpp"
#include "window.hpp"

using namespace std;

namespace editor
{

    int start_editing(const string &filename)
    {
        Editor editor;
        Buffer buffer{filename};
        display(buffer.text());
        sleep(2);
        return 0;
    }

    void display(const string &text, int y, int x)
    {
        printw(text.c_str(), y, x);
        refresh();
    }

    Editor::Editor()
    {
        initscr();
        cbreak();
        keypad(stdscr, true);
    }

    Editor::~Editor()
    {
        endwin();
    }

} // namespace editor
