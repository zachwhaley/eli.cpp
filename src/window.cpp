#include "window.hpp"

using namespace std;

namespace editor
{

    Window::Window(int height, int width, int start_y, int start_x)
    {
        m_window = newwin(height, width, start_y, start_x);
        if (!m_window) {
            throw;
        }
        box(m_window, 0, 0);
        wrefresh(m_window);
    }

    Window::~Window()
    {
        /* The parameters taken are
         * 1. win: the window on which to operate
         * 2. ls: character to be used for the left side of the window
         * 3. rs: character to be used for the right side of the window
         * 4. ts: character to be used for the top side of the window
         * 5. bs: character to be used for the bottom side of the window
         * 6. tl: character to be used for the top left corner of the window
         * 7. tr: character to be used for the top right corner of the window
         * 8. bl: character to be used for the bottom left corner of the window
         * 9. br: character to be used for the bottom right corner of the window
         */
        wborder(m_window, ' ', ' ', ' ',' ',' ',' ',' ',' ');
        wrefresh(m_window);
        delwin(m_window);
    }

} // namespace editor
