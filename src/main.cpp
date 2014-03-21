#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string slurp(const string &filename)
{
    ifstream ifs{filename, ios::in | ios::binary | ios::ate};
    if (ifs)
    {
        string str;

        ifs.seekg(0, ios::end);
        str.resize(ifs.tellg());
        ifs.seekg(0, ios::beg);

        ifs.read(&str.front(), str.size());

        return str;
    }
    return "";
}

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        cout << slurp(argv[1]) << endl;
    }
    else
    {
        cout << argv[0] << " [file]" << endl;
    }
    return 0;
}
