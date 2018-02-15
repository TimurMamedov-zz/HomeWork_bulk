/*!
\file
\brief
*/
#pragma once

#include "solver.h"

class AddingSolver : public Solver
{
public:
    explicit AddingSolver(CommandsStorage& commStor);
    void solve() override;
};

class PrintSolver : public Solver
{
public:
    explicit PrintSolver(CommandsStorage& commStor);
    void solve() override;
};

class LastSolver : public Solver
{
public:
    explicit LastSolver(CommandsStorage& commStor);
    void solve() override;
};
