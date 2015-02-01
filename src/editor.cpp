#include "editor.hpp"

#include <ncurses.h>

using namespace std;

namespace eli {

Editor::Editor()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);
}

Editor::~Editor()
{
    endwin();
}

void
Editor::open(const char *filename)
{
    m_buffer.read(filename);
}

void
Editor::edit()
{
    int ch;

    while (true) {
        m_buffer.display();

        ch = getch();
        if (ch == KEY_F(12)) {
            return;
        }
        else if (ch == KEY_F(1)) {
            m_buffer.write();
        }
        else {
            m_buffer.update(ch);
        }
    }
}

} // namespace eli
