#include <iostream>
#include "commands_storage.h"

int main(int argc, char *argv[])
{
    try
    {
        CommandsStorage cmdStorage(5);
        for (std::string line; std::getline(std::cin, line);)
        {
            cmdStorage.addString(line);
        }
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
