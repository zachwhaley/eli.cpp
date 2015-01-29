#ifndef _EDITOR_EDITOR_HPP_
#define _EDITOR_EDITOR_HPP_

#include <string>

namespace editor
{

    int start_editing(const std::string &filename);

    class Editor
    {
    public:
        /* Constructor */
        Editor();
        /* Destructor */
        ~Editor();
    };

} // namespace editor

#endif /* _EDITOR_EDITOR_HPP_ */
