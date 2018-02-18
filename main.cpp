#include <iostream>
#include "commands_storage.h"
#include <boost/program_options.hpp>

namespace po = boost::program_options;

int main(int argc, char *argv[])
{
    try
    {
        po::options_description desc("Allowed options");
        desc.add_options()
                ("help,h", "produce help message");

        po::variables_map vm;
        po::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);

        if (vm.count("help"))
        {
            std::cout << desc << std::endl;
        }
        else
        {
            std::size_t size;
            if(argc > 1)
            {
                std::istringstream ss(argv[1]);
                if (!(ss >> size))
                    size = 4;
            }
            else
                size = 4;
            CommandsStorage cmdStorage(size);
            for(std::string line; std::getline(std::cin, line);)
            {
                cmdStorage.addString(line);
            }
        }
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
