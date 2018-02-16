/*!
\file
\brief
*/
#pragma once

#include "solver.h"

class PrintSolver : public Solver
{
public:
    explicit PrintSolver(CommandsStorage& commStor);
    void solve() override;
};

class ForcingPrintSolver : public Solver
{
public:
    explicit ForcingPrintSolver(CommandsStorage& commStor);
    void solve() override;
};
