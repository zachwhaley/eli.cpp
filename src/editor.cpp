#include "editor.hpp"

#include "file_io.hpp"
#include "window.hpp"

using namespace std;

namespace editor
{
    static int start_editing(const string &filename);

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

    static int start_editing(const string &filename)
    {
        Editor editor;
        Buffer buffer{filename};
        display(buffer.text(), 0, 0);
        int ch;
        while (true) {
            ch = getch();
            if (ch == KEY_F(12)) {
                return 0;
            }
            else {
                int cur_y, cur_x;
                getyx(stdscr, cur_y, cur_x);
                switch(ch) {
                    case KEY_UP:
                        move(--cur_y, cur_x);
                        break;
                    case KEY_DOWN:
                        move(++cur_y, cur_x);
                        break;
                    case KEY_RIGHT:
                        move(cur_y, ++cur_x);
                        break;
                    case KEY_LEFT:
                        move(cur_y, --cur_x);
                        break;
                    default:
                        insch(ch);
                        move(cur_y, ++cur_x);
                        break;
                }
            }
        }
        return 0;
    }

} // namespace editor
