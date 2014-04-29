#include "editor.hpp"

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
        getch();
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
