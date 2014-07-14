#include "buffer.hpp"

#include <algorithm>
#include <fstream>

using namespace std;

namespace editor
{

    string slurp(const string &filename)
    {
        ifstream ifs{filename, ios::in | ios::binary | ios::ate};
        if (ifs) {
            string str;

            ifs.seekg(0, ios::end);
            str.resize(ifs.tellg());
            ifs.seekg(0, ios::beg);

            ifs.read(&str.front(), str.size());

            return str;
        }
        throw;
    }

    Buffer::Buffer(const string &filename)
    {
        m_text = slurp(filename);
    }

    void Buffer::addChar(char ch, int y, int x)
    {
        int count = 0;
        // Find the yth new line character in the buffer's text.  This will sort of be the Y position of the cursor,
        // or the row of the buffer.
        auto iter = find_if(m_text.begin(), m_text.end(), [&](const char& value) {
                return (value == '\n' && ++count == y);
            });
        if (iter != m_text.end()) {
            // string::insert puts the input character before given position, so we need to increment the iter by one to
            // insert at the cursor,
            // then we increment the position again to the X coordinate of the cursor.
            auto pos = iter + 1 + x;
            m_text.insert(pos, ch);
        }
    }

    const string& Buffer::text() const
    {
        return m_text;
    }

} // namespace editor
