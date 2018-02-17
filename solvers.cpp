#include "solvers.h"
#include "commands_storage.h"

SaveSolver::SaveSolver(CommandsStorage &commStor)
    :Solver(commStor)
{
}

ForcingSaveSolver::ForcingSaveSolver(CommandsStorage &commStor)
    :Solver(commStor)
{
}

void SaveSolver::solve()
{
    if((commandStorage.commandsSize() >= commandStorage.bulkSize()) && !commandStorage.bracketSize())
    {
        Solver::print();
    }
}

void ForcingSaveSolver::solve()
{
    if(!commandStorage.bracketSize() && commandStorage.commandsSize())
    {
        Solver::print();
    }
}
