#ifndef _ELI_WINDOW_HPP_
#define _ELI_WINDOW_HPP_

#include <string>

#include <ncurses.h>

namespace eli {

void display(const std::string &text, int y=0, int x=0);

class Window
{
public:
    /* Constructor */
    Window(int height, int width, int start_y, int start_x);
    /* Destructor */
    ~Window();

private:
    WINDOW *m_window;
};

} // namespace eli

#endif /* _ELI_WINDOW_HPP_ */
