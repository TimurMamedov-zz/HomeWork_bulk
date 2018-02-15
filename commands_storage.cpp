#include "commands_storage.h"
#include "solvers.h"

CommandsStorage::CommandsStorage(std::size_t bulkSize) : bulkSize_(bulkSize)
{
    commandsVector.reserve(bulkSize_);
    solvers.reserve(3);
    solvers.emplace_back(std::make_unique<AddingSolver>(*this));
    solvers.emplace_back(std::make_unique<PrintSolver>(*this));
}

CommandsStorage::~CommandsStorage()
{
    LastSolver solver(*this);
    solver.solve();
}

void CommandsStorage::addString(const std::string& str)
{
    currentString = str;
    for(auto& solver: solvers)
    {
        solver->solve();
    }
}

void CommandsStorage::save()
{
    std::ofstream file;
    std::stringstream ss;
    ss << std::chrono::system_clock::to_time_t(firstBulkTime);
    file.open(ss.str() + "bulk.log");
    file << bulkCommandString();
    file.close();
}

void CommandsStorage::print() const
{
    std::cout << bulkCommandString() << std::endl;
}

bool CommandsStorage::bracketEmpty() const { return bracketStack.empty(); }
std::size_t CommandsStorage::commandsSize() const { return commandsVector.size(); }
std::size_t CommandsStorage::bulkSize() const { return bulkSize_; }

std::string CommandsStorage::getCurrentString() const
{
    return currentString;
}

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
        bracketStack.push(bracket);
    }
    else if(bracket == "}")
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
    bracketStack = std::stack<std::string>();
}
