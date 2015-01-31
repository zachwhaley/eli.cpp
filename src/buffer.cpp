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
Buffer::insert(char ch, unsigned &row, unsigned &col)
{
    if (row <= m_lines.size()) {
        string &line = m_lines[row];
        if (col <= line.length()) {
            line.insert(col, 1, ch);
            col++;
        }
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
