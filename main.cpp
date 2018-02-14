#include <iostream>
#include <string>
#include "commands_storage.h"
int main(int argc, char *argv[])
{
    CommandsStorage cmdStorage(5);
    for (std::string line; std::getline(std::cin, line);)
    {
        std::cout << line << std::endl << std::endl;
    }
    return 0;
}
