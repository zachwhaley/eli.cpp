#ifndef _EDITOR_WINDOW_HPP_
#define _EDITOR_WINDOW_HPP_

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

#endif /* _EDITOR_WINDOW_HPP_ */
