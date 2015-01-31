#include "buffer.hpp"

#include <fstream>

#include <ncurses.h>

using namespace std;

namespace eli {

void
Buffer::read(const char *filename)
{
    m_filename = filename;
    m_lines.clear();

    ifstream ifs {m_filename, ios::in};
    if (ifs) {
        string line;
        while (getline(ifs, line)) {
            m_lines.push_back(line);
        }
    }
}

void
Buffer::write() const
{
    ofstream ofs {m_filename, ios::out | ios::trunc};
    for (string line : m_lines) {
        ofs << line << endl;
    }
}

void
Buffer::update(int ch, Cursor *cur)
{
    // Better safe than sorry
    if (!cur) return;

    if (ch == KEY_UP) {
        if (cur->y != 0)
            cur->y--;
    }
    else if (ch == KEY_DOWN) {
        if (cur->y != m_lines.size() - 1)
            cur->y++;
    }
    else if (ch == KEY_RIGHT) {
        if (cur->x != m_lines[cur->y].length())
            cur->x++;
    }
    else if (ch == KEY_LEFT) {
        if (cur->x != 0)
            cur->x--;
    }
    else if (ch == KEY_HOME) {
        cur->x = 0;
    }
    else if (ch == KEY_END) {
        cur->x = m_lines[cur->y].length();
    }
    else {
        string &line = m_lines[cur->y];
        line.insert(cur->x, 1, ch);
        cur->x++;
    }
    // Correct column value
    if (cur->x > m_lines[cur->y].length()) {
        cur->x = m_lines[cur->y].length();
    }
}

void
Buffer::display() const
{
    int row = 0;
    for (string line : m_lines) {
        mvaddstr(row++, 0, line.c_str());
    }
    refresh();
}

} // namespace eli
