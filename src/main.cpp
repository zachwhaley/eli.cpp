#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        cout << argv[1] << endl;
    }
    else
    {
        cout << argv[0] << " [file]" << endl;
    }
    return 0;
}
