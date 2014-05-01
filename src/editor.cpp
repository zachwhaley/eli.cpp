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
        int ch;
        while (true)
        {
            ch = getch();
            if (ch == KEY_F(12))
            {
                return 0;
            }
            else
            {
                int cur_y, cur_x;
                getyx(stdscr, cur_y, cur_x);
                switch(ch)
                {
                case KEY_UP:
                    cur_y--;
                    move(cur_y, cur_x);
                    break;
                case KEY_DOWN:
                    cur_y++;
                    move(cur_y, cur_x);
                    break;
                case KEY_RIGHT:
                    cur_x++;
                    move(cur_y, cur_x);
                    break;
                case KEY_LEFT:
                    cur_x--;
                    move(cur_y, cur_x);
                    break;
                default:
                    buffer.addChar(ch, cur_y, cur_x);
                    display(buffer.text());
                    move(cur_y, ++cur_x);
                    break;
                }
            }
        }
        return 0;
    }

    void display(const string &text, int y, int x)
    {
        mvprintw(y, x, text.c_str());
        refresh();
    }

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

} // namespace editor
