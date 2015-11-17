#ifndef _ELI_EDITOR_HPP_
#define _ELI_EDITOR_HPP_
#define CTRL(c) ((c) & 037)
#include "buffer.hpp"

#include <string>

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
