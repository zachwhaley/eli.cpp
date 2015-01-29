#ifndef _EDITOR_FILE_IO_HPP_
#define _EDITOR_FILE_IO_HPP_

#include <string>

namespace editor
{
    string slurp(const string &filename);

    class Buffer
    {
    private:
        std::string m_text;

    public:
        /* Copy Contructor */
        Buffer(const Buffer &) = default;
        /* Move Contructor */
        Buffer(Buffer &&) = default;
        /* Copy Assignment Operator */
        Buffer& operator=(const Buffer &) = default;
        /* Move Assignment Operator */
        Buffer& operator=(Buffer &&) = default;
        /* Destructor */
        ~Buffer() = default;

        /* Constructor */
        Buffer(const std::string &filename);

        const std::string& text() const;
    };

} // namespace editor

#endif /* _EDITOR_FILE_IO_HPP_ */
