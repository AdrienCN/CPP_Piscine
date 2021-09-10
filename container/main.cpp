#include "main.hpp"
#include <string.h>

int main(int argc, char *argv[])
{
    char *ext = strrchr(argv[0], '.');
    std::string ext_str = ext ? (ext + 1): "";

    (void)argc;
    std::cout << ext_str << std::endl;
    if (ext_str == "stl")
        main_stl();
    else if (ext_str == "ft")
        main_ft();
    return (0);
}
