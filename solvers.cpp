#include "solvers.h"
#include "commands_storage.h"

PrintSolver::PrintSolver(CommandsStorage &commStor)
    :Solver(commStor)
{
}

ForcingPrintSolver::ForcingPrintSolver(CommandsStorage &commStor)
    :Solver(commStor)
{
}

void PrintSolver::solve()
{
    if((commandStorage.commandsSize() >= commandStorage.bulkSize()) && !commandStorage.bracketSize())
    {
        Solver::print();
    }
}

void ForcingPrintSolver::solve()
{
    if(!commandStorage.bracketSize() && commandStorage.commandsSize())
    {
        Solver::print();
    }
}
