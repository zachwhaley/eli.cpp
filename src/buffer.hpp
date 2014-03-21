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
        Buffer(const Buffer &) = default;
        Buffer(Buffer &&) = default;
        Buffer & operator=(const Buffer &) & = default;
        Buffer & operator=(Buffer &&) & = default;
        virtual ~Buffer() {}

        Buffer(const std::string &name, const std::string &text);

        const std::string & text() const;
    };

} // namespace editor

#endif /* _BUFFER_HPP__ */
