#ifndef _WINDOW_HPP__
#define _WINDOW_HPP__

#include <string>

#include <curses.h>

namespace editor
{

    void display(int x, int y, const std::string &text);

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
        Window();
        /* Destructor */
        ~Window();

    private:
        WINDOW *m_window;
    };

} // namespace editor

#endif /* _WINDOW_HPP__ */
