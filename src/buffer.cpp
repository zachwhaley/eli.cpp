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
    if (cur->y >= m_lines.size()) return;

    switch (ch) {
    case KEY_UP:
        if (cur->y != 0)
            cur->y--;
        break;
    case KEY_DOWN:
        if (cur->y != m_lines.size() - 1)
            cur->y++;
        break;
    case KEY_RIGHT:
        if (cur->x != m_lines[cur->y].length())
            cur->x++;
        break;
    case KEY_LEFT:
        if (cur->x != 0)
            cur->x--;
        break;
    case KEY_HOME:
        cur->x = 0;
        break;
    case KEY_END:
        cur->x = m_lines[cur->y].length();
        break;
    case KEY_BACKSPACE:
        if (cur->x != 0)
            m_lines[cur->y].erase(--cur->x, 1);
        break;
    default:
        m_lines[cur->y].insert(cur->x++, 1, ch);
    }
    // Correct column value
    if (cur->x > m_lines[cur->y].length()) {
        cur->x = m_lines[cur->y].length();
    }
}

void
Buffer::display() const
{
    unsigned row = 0;
    const unsigned cols = COLS;
    for (string line : m_lines) {
        move(row++, 0);
        for (unsigned col = 0; col < cols; col++) {
            if (col < line.length())
                addch(line[col]);
            else
                addch(' ');
        }
    }
    refresh();
}

} // namespace eli
