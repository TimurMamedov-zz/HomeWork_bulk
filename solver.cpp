#include "solver.h"
#include "commands_storage.h"

Solver::Solver(CommandsStorage& commStor)
    :commandStorage(commStor)
{

}

Solver::~Solver()
{

}

SaveSolver::SaveSolver(CommandsStorage &commStor)
    :Solver(commStor)
{

}

void SaveSolver::solve()
{
    if(commandStorage.commandsSize() >= commandStorage.bulkSize())
    {
        commandStorage.print();
        commandStorage.save();
    }
}
