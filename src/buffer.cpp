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
    switch (ch) {
    case KEY_UP:
        prevline();
        break;
    case KEY_DOWN:
        nextline();
        break;
    case KEY_RIGHT:
        nextchar();
        break;
    case KEY_LEFT:
        prevchar();
        break;
    case KEY_HOME:
        begofline();
        break;
    case KEY_END:
        endofline();
        break;
    case KEY_BACKSPACE:
        delchar();
        break;
    case '\n':
    case '\r':
        newline();
        break;
    default:
        addchar(ch);
    }
    // Correct column value
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
Buffer::nextline()
{
    if (m_cur.y != m_lines.size() - 1) {
        m_cur.y++;
    }
    if (m_cur.x > m_lines[m_cur.y].length()) {
        endofline();
    }
}

void
Buffer::prevline()
{
    if (m_cur.y != 0) {
        m_cur.y--;
    }
    if (m_cur.x > m_lines[m_cur.y].length()) {
        endofline();
    }
}

void
Buffer::nextchar()
{
    if (m_cur.x != m_lines[m_cur.y].length()) {
        m_cur.x++;
    }
    else if (m_cur.y != m_lines.size() - 1) {
        m_cur.y++;
        begofline();
    }
}

void
Buffer::prevchar()
{
    if (m_cur.x != 0) {
        m_cur.x--;
    }
    else if (m_cur.y != 0) {
        m_cur.y--;
        endofline();
    }
}

void
Buffer::begofline()
{
    m_cur.x = 0;
}

void
Buffer::endofline()
{
    m_cur.x = m_lines[m_cur.y].length();
}

void
Buffer::delchar()
{
    if (m_cur.x != 0) {
        m_lines[m_cur.y].erase(m_cur.x - 1, 1);
        prevchar();
    }
    else if (m_cur.y != 0) {
        string old_line = m_lines[m_cur.y];
        m_lines.erase(m_lines.begin() + m_cur.y);
        prevchar();
        // Append what was left of the erased line to the now current line
        m_lines[m_cur.y] += old_line;
    }
}

void
Buffer::newline()
{
    string new_line = m_lines[m_cur.y].substr(m_cur.x);
    m_lines[m_cur.y].erase(m_cur.x);
    auto new_pos = m_lines.begin() + m_cur.y + 1;
    m_lines.insert(new_pos, new_line);
    nextchar();
}

void
Buffer::addchar(char ch)
{
    m_lines[m_cur.y].insert(m_cur.x, 1, ch);
    nextchar();
}

} // namespace eli
