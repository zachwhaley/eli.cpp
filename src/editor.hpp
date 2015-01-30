#ifndef _EDITOR_EDITOR_HPP_
#define _EDITOR_EDITOR_HPP_

#include <string>

namespace editor {

class Editor
{
public:
    /* Constructor */
    Editor();
    /* Destructor */
    ~Editor();

    /* Open the contents from filename to be edited */
    void open(const std::string &filename);
};

} // namespace editor

#endif /* _EDITOR_EDITOR_HPP_ */
