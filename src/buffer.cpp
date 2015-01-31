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
Buffer::update(int ch, unsigned &row, unsigned &col)
{
    if (ch == KEY_UP) {
        if (row != 0)
            row--;
    }
    else if (ch == KEY_DOWN) {
        if (row != m_lines.size() - 1)
            row++;
    }
    else if (ch == KEY_RIGHT) {
        if (col != m_lines[row].length())
            col++;
    }
    else if (ch == KEY_LEFT) {
        if (col != 0)
            col--;
    }
    else if (row < m_lines.size()) {
        string &line = m_lines[row];
        if (col <= line.length()) {
            line.insert(col, 1, ch);
            col++;
        }
    }
    // Correct column value
    if (col > m_lines[row].length()) {
        col = m_lines[row].length();
    }
}

void
Buffer::display()
{
    int row = 0;
    for (string &line : m_lines) {
        mvaddstr(row++, 0, line.c_str());
    }
    refresh();
}

} // namespace eli
