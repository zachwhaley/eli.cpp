#ifndef _ELI_BUFFER_HPP_
#define _ELI_BUFFER_HPP_

#include <string>
#include <vector>

namespace eli {

struct Cursor {
    unsigned int y = 0;
    unsigned int x = 0;
};

class Buffer
{
public:
    void read(const char *filename);
    void update(int ch, Cursor *cur);
    void display();

private:
    std::string m_filename;
    std::vector<std::string> m_lines;
};

} // namespace eli

#endif /* _ELI_BUFFER_HPP_ */
