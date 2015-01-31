#include "editor.hpp"

#include "file_io.hpp"
#include "window.hpp"

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
    unsigned cur_y = 0, cur_x = 0;

    while (true) {
        m_buffer.display();

        move(cur_y, cur_x);
        ch = getch();
        if (ch == KEY_F(12)) {
            return;
        }
        else {
            m_buffer.update(ch, cur_y, cur_x);
        }
    }
}

} // namespace eli
