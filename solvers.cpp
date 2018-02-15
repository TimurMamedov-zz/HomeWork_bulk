#include "solvers.h"
#include "commands_storage.h"

AddingSolver::AddingSolver(CommandsStorage &commStor)
    :Solver(commStor)
{
}

PrintSolver::PrintSolver(CommandsStorage &commStor)
    :Solver(commStor)
{
}

LastSolver::LastSolver(CommandsStorage &commStor)
    :Solver(commStor)
{
}

void PrintSolver::solve()
{
    if(commandStorage.commandsSize() >= commandStorage.bulkSize() && commandStorage.bracketEmpty())
    {
        commandStorage.save();
        commandStorage.print();
        commandStorage.clear();
    }
}

void AddingSolver::solve()
{
    auto currStr = commandStorage.getCurrentString();
    if(currStr == "{" || currStr == "}")
        commandStorage.addBracket(currStr);
    else
        commandStorage.addCommand(currStr);
}

void LastSolver::solve()
{
    if(commandStorage.bracketEmpty() && commandStorage.commandsSize())
    {
        commandStorage.save();
        commandStorage.print();
    }
}
