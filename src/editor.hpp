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
        Editor(const Editor &) = default;
        Editor(Editor &&) = default;
        Editor& operator=(const Editor &) & = default;
        Editor& operator=(Editor &&) & = default;
        virtual ~Editor();

        Editor(const std::string &filename);

    private:
        WINDOW *m_window;
        std::unique_ptr<Buffer> m_buffer;
    };

} // namespace editor

#endif /* _EDITOR_HPP__ */
