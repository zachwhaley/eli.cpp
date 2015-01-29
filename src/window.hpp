#ifndef _EDITOR_WINDOW_HPP_
#define _EDITOR_WINDOW_HPP_

#include <ncurses.h>

namespace editor
{
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
