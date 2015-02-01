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
        else if (cur->y != m_lines.size() - 1) {
            cur->y++;
            cur->x = 0;
        }
        break;
    case KEY_LEFT:
        if (cur->x != 0)
            cur->x--;
        else if (cur->y != 0)
            cur->x = m_lines[--cur->y].length();
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
    case '\n':
    case '\r':
    {
        string new_line = m_lines[cur->y].substr(cur->x);
        m_lines[cur->y++].erase(cur->x);

        m_lines.insert(m_lines.begin() + cur->y, new_line);
        cur->x = 0;
        break;
    }
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
    const unsigned cols = COLS, lines = LINES;
    for (unsigned line = 0; line < lines; line++) {
        move(line, 0);
        for (unsigned col = 0; col < cols; col++) {
            if (line < m_lines.size() && col < m_lines[line].length())
                addch(m_lines[line][col]);
            else
                addch(' ');
        }
    }
    refresh();
}

} // namespace eli
