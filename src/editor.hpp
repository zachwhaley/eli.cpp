#ifndef _ELI_EDITOR_HPP_
#define _ELI_EDITOR_HPP_

#include <string>

#include "buffer.hpp"

namespace eli {

class Editor
{
public:
    Editor();
    ~Editor();
    /* Open the contents from filename to be edited */
    void open(const char *filename);
    void edit();

private:
    Buffer m_buffer;
};

} // namespace eli

#endif /* _ELI_EDITOR_HPP_ */
