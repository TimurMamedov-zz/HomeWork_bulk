/*!
\file
\brief
*/
#pragma once

#include "commands_storage.h"
class CommandsStorage;

class Solver
{
public:
    explicit Solver(CommandsStorage& commStor);
    virtual void solve() = 0;
    virtual ~Solver();

protected:
    CommandsStorage& commandStorage;
};

class SaveSolver : public Solver
{
public:
    explicit SaveSolver(CommandsStorage& commStor);
    void solve() override;
};
