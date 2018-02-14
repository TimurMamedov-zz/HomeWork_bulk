#include "commands_storage.h"
#include "solver.h"

CommandsStorage::CommandsStorage(std::size_t bulkSize) : bulkSize_(bulkSize)
{
    commandsVector.reserve(bulkSize_);
    solver = std::make_unique<SaveSolver>(*this);;
}

void CommandsStorage::addString(const std::string& str)
{
    if(str == "{" || str == "}")
        addBracket(str);
    else
        addCommand(str);

    solver->solve();
}

void CommandsStorage::save()
{
    if(bracketStack.empty() && !commandsVector.empty())
    {
        std::ofstream file;
        std::stringstream ss;
        ss << std::chrono::system_clock::to_time_t(firstBulkTime);
        file.open(ss.str() + "bulk.log");
        file << bulkCommandString();
        file.close();

        clear();
    }
}

void CommandsStorage::print() const
{
    if(bracketStack.empty() && !commandsVector.empty())
    {
        std::cout << bulkCommandString();
    }
}

bool CommandsStorage::bracketEmpty() const { return bracketStack.empty(); }
std::size_t CommandsStorage::commandsSize() const { return commandsVector.size(); }
std::size_t CommandsStorage::bulkSize() const { return bulkSize_; }

void CommandsStorage::addCommand(const std::string& command)
{
    if(commandsVector.empty())
        firstBulkTime = std::chrono::system_clock::now();

    commandsVector.push_back(command);
}

void CommandsStorage::addBracket(const std::string& bracket)
{
    if(bracket == "{")
    {
        if(bracketStack.empty())
        {
            save();
            print();
            clear();
        }
        else
        {
            if(!commandsVector.empty())
            {
                clear();
            }
        }
        bracketStack.push(bracket);
    }
    else
    {
        if(!bracketStack.empty())
            if(bracketStack.top() == "{")
                bracketStack.pop();
    }
}

std::string CommandsStorage::bulkCommandString() const
{
    std::stringstream ss;
    ss << "bulk: ";
    auto last = commandsVector.end();
    last--;
    for(auto it = commandsVector.begin(); it != last; it++)
    {
        ss << *it << ", ";
    }
    ss << *last;

    return ss.str();
}

void CommandsStorage::clear()
{
    commandsVector.clear();
    while (!bracketStack.empty())
    {
        bracketStack.pop();
    }
}
