#include "window.hpp"

using namespace std;

namespace editor
{

    void display(int x, int y, const string &text)
    {
        mvaddstr(x, y, text.c_str());
        refresh();
    }

    Window::Window()
    {
        m_window = initscr();
        if (!m_window)
        {
            throw;
        }
    }

    Window::~Window()
    {
        delwin(m_window);
        endwin();
        refresh();
    }

} // namespace editor
