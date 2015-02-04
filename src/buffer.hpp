#ifndef _ELI_BUFFER_HPP_
#define _ELI_BUFFER_HPP_

#include <string>
#include <vector>

#include <ncurses.h>

namespace eli {

struct Cursor {
    unsigned int y = 0;
    unsigned int x = 0;
};

class Buffer
{
public:
    ~Buffer();
    void read(const char *filename);
    void write() const;
    int getchar() const;
    void update(int ch);
    void display();

private:
    void initwindows();
    void begofline();
    void endofline();
    void nextline();
    void prevline();
    void nextchar();
    void prevchar();
    void addchar(char ch);
    void delchar();
    void newline();

private:
    Cursor m_cur;
    std::string m_filename;
    std::vector<std::string> m_lines;
    WINDOW *m_textwin = nullptr;
};

} // namespace eli

#endif /* _ELI_BUFFER_HPP_ */
