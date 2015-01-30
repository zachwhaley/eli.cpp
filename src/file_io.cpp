#include "file_io.hpp"

#include <fstream>

using namespace std;

namespace eli {

string slurp(const string &filename)
{
    string str;
    ifstream ifs {filename, ios::in | ios::binary | ios::ate};
    if (ifs) {
        ifs.seekg(0, ios::end);
        str.resize(ifs.tellg());
        ifs.seekg(0, ios::beg);

        ifs.read(&str.front(), str.size());
    }
    return str;
}

} // namespace eli
