#include "editor.hpp"

#include <unistd.h>

#include "buffer.hpp"
#include "window.hpp"

using namespace std;

namespace editor
{

    int start_editing(const string &filename)
    {
        Window window;
        Buffer buffer{filename};
        display(0, 0, buffer.text());
        sleep(2);
    }

} // namespace editor
