#include "editor.hpp"

#include <fstream>

#include <curses.h>

using namespace std;

namespace editor
{

    string slurp(const string &filename)
    {
        ifstream ifs{filename, ios::in | ios::binary | ios::ate};
        if (ifs)
        {
            string str;

            ifs.seekg(0, ios::end);
            str.resize(ifs.tellg());
            ifs.seekg(0, ios::beg);

            ifs.read(&str.front(), str.size());

            return str;
        }
        throw;
    }

    WINDOW* start_screen()
    {
        WINDOW *win = initscr();
        if (win)
        {
            return win;
        }
        throw;
    }

    void display(int x, int y, const string &text)
    {
        mvaddstr(x, y, text.c_str());
        refresh();
    }

    Editor::Editor(const string &filename)
    {
        m_window = start_screen();

        string name = filename;
        string text = slurp(filename);
        m_buffer = unique_ptr<Buffer>{new Buffer{name, text}};
        display(0, 0, m_buffer->text());
    }

    Editor::~Editor()
    {
        delwin(m_window);
        endwin();
        refresh();
    }

} // namespace editor
