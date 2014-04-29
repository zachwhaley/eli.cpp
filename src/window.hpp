#ifndef _WINDOW_HPP__
#define _WINDOW_HPP__

#include <ncurses.h>

namespace editor
{
    class Window
    {
    public:
        /* Copy Contructor */
        Window(const Window &) = delete;
        /* Move Contructor */
        Window(Window &&) = default;
        /* Copy Assignment Operator */
        Window& operator=(const Window &) = delete;
        /* Move Assignment Operator */
        Window& operator=(Window &&) = default;

        /* Constructor */
        Window(int height, int width, int start_y, int start_x);
        /* Destructor */
        ~Window();

    private:
        WINDOW *m_window;
    };

} // namespace editor

#endif /* _WINDOW_HPP__ */
