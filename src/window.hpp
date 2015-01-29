#ifndef _EDITOR_WINDOW_HPP_
#define _EDITOR_WINDOW_HPP_

#include <string>

#include <ncurses.h>

namespace editor
{
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

} // namespace editor

#endif /* _EDITOR_WINDOW_HPP_ */
