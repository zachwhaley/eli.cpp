#ifndef _ELI_BUFFER_HPP_
#define _ELI_BUFFER_HPP_

#include <ncurses.h>

#include <string>
#include <vector>

namespace eli {

struct Cursor {
    unsigned int y = 0;
    unsigned int x = 0;
};

struct Window {
    WINDOW *win = nullptr;
    size_t lines = 0;
    size_t cols = 0;
    ~Window() { if (win) delwin(win); }
};

class Buffer
{
public:
    Buffer();
    void read(const char *filename);
    void write();
    int getchar() const;
    std::string getinput(const std::string &msg) const;
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
    Window m_text;
    Window m_title;
};

} // namespace eli

#endif /* _ELI_BUFFER_HPP_ */
