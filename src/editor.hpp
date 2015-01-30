#ifndef _ELI_EDITOR_HPP_
#define _ELI_EDITOR_HPP_

#include <string>

namespace eli {

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

} // namespace eli

#endif /* _ELI_EDITOR_HPP_ */
