#include "file_io.hpp"

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

} // namespace editor
