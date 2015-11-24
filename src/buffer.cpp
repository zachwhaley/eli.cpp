#include "buffer.hpp"

#include <fstream>
#include <sstream>

using namespace std;

namespace eli {

void
Buffer::read(const char *filename)
{
    m_filename = filename;
    m_lines.clear();

    ifstream ifs(m_filename, ios::in);
    if (ifs) {
        string line;
        while (getline(ifs, line)) {
            m_lines.push_back(line);
        }
    }
    else {
        m_lines.push_back(string());
    }
}

void
Buffer::write() const
{
    ofstream ofs(m_filename, ios::out | ios::trunc);
    for (string line : m_lines) {
        ofs << line << endl;
    }
}

int
Buffer::getchar() const
{
    return wgetch(m_text.win);
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
}

void
Buffer::display()
{
    initwindows();

    // Refresh title window
    string title = " " + m_filename + " " + to_string(m_cur.y) + "," + to_string(m_cur.x);
    mvwaddstr(m_title.win, 0, 0, title.c_str());
    for (size_t col = title.size(); col < m_title.cols; col++) {
        waddch(m_title.win, ' ');
    }
    wnoutrefresh(m_title.win);

    // Refresh text window
    for (size_t line = 0; line < m_text.lines - 1; line++) {
        wmove(m_text.win, line, 0);
        for (size_t col = 0; col < m_text.cols; col++) {
            if (line < m_lines.size() && col < m_lines[line].length())
                waddch(m_text.win, m_lines[line][col]);
            else
                waddch(m_text.win, ' ');
        }
    }
    wnoutrefresh(m_text.win);
    wmove(m_text.win, m_cur.y, m_cur.x);
    doupdate();
}

void
Buffer::initwindows()
{
    const size_t cols = COLS, lines = LINES;
    if (!m_title.win) {
        m_title.win = newwin(1, cols, lines - 1, 0);
        m_title.lines = 1;
        m_title.cols = cols;
        wattron(m_title.win, A_REVERSE);
    }
    if (!m_text.win) {
        m_text.win = newwin(lines - 1, cols, 0, 0);
        m_text.lines = lines - 1;
        m_text.cols = cols;
        keypad(m_text.win, true);
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
Buffer::addchar(char ch)
{
    m_lines[m_cur.y].insert(m_cur.x, 1, ch);
    nextchar();
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

} // namespace eli
