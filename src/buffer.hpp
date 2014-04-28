#ifndef _BUFFER_HPP__
#define _BUFFER_HPP__

#include <string>

namespace editor
{

    class Buffer
    {
    private:
        std::string m_name;
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
        Buffer(const std::string &name, const std::string &text);

        const std::string& text() const;
    };

} // namespace editor

#endif /* _BUFFER_HPP__ */
