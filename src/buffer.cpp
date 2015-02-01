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
Buffer::update(int ch)
{
    // Better safe than sorry
    if (m_cur.y >= m_lines.size()) return;

    switch (ch) {
    case KEY_UP:
        if (m_cur.y != 0)
            m_cur.y--;
        break;
    case KEY_DOWN:
        if (m_cur.y != m_lines.size() - 1)
            m_cur.y++;
        break;
    case KEY_RIGHT:
        if (m_cur.x != m_lines[m_cur.y].length())
            m_cur.x++;
        else if (m_cur.y != m_lines.size() - 1) {
            m_cur.y++;
            m_cur.x = 0;
        }
        break;
    case KEY_LEFT:
        if (m_cur.x != 0)
            m_cur.x--;
        else if (m_cur.y != 0)
            m_cur.x = m_lines[--m_cur.y].length();
        break;
    case KEY_HOME:
        begofline();
        break;
    case KEY_END:
        m_cur.x = m_lines[m_cur.y].length();
        break;
    case KEY_BACKSPACE:
        if (m_cur.x != 0)
            m_lines[m_cur.y].erase(--m_cur.x, 1);
        else if (m_cur.y != 0) {
            string old_line = m_lines[m_cur.y];
            m_lines.erase(m_lines.begin() + m_cur.y);
            m_cur.x = m_lines[--m_cur.y].length();
            m_lines[m_cur.y] += old_line;
        }
        break;
    case '\n':
    case '\r':
    {
        string new_line = m_lines[m_cur.y].substr(m_cur.x);
        m_lines[m_cur.y++].erase(m_cur.x);

        m_lines.insert(m_lines.begin() + m_cur.y, new_line);
        m_cur.x = 0;
        break;
    }
    default:
        m_lines[m_cur.y].insert(m_cur.x++, 1, ch);
    }
    // Correct column value
    if (m_cur.x > m_lines[m_cur.y].length()) {
        m_cur.x = m_lines[m_cur.y].length();
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
    move(m_cur.y, m_cur.x);
    refresh();
}

void
Buffer::begofline()
{
    m_cur.x = 0;
}

} // namespace eli
