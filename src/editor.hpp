#ifndef _EDITOR_HPP__
#define _EDITOR_HPP__

#include <memory>
#include <string>

#include <curses.h>

#include "buffer.hpp"

namespace editor
{

    class Editor
    {
    public:
        /* Copy Contructor */
        Editor(const Editor &) = default;
        /* Move Contructor */
        Editor(Editor &&) = default;
        /* Copy Assignment Operator */
        Editor& operator=(const Editor &) = default;
        /* Move Assignment Operator */
        Editor& operator=(Editor &&) = default;

        /* Constructor */
        Editor(const std::string &filename);
        /* Destructor */
        ~Editor();

    private:
        WINDOW *m_window;
        std::unique_ptr<Buffer> m_buffer;
    };

} // namespace editor

#endif /* _EDITOR_HPP__ */
