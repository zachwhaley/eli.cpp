#include "buffer.hpp"

using namespace std;

namespace editor
{

    Buffer::Buffer(const string &name, const string &text) :
        m_name(name),
        m_text(text)
    {
    }

    const string & Buffer::text() const
    {
        return m_text;
    }

} // namespace editor
