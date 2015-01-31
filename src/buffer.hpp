#ifndef _ELI_BUFFER_HPP_
#define _ELI_BUFFER_HPP_

#include <string>
#include <vector>

namespace eli {

class Buffer
{
public:
    void read(const char *filename);
    void insert(char ch, unsigned &row, unsigned &col);
    void display();

private:
    std::string m_filename;
    std::vector<std::string> m_lines;
};

} // namespace eli

#endif /* _ELI_BUFFER_HPP_ */
