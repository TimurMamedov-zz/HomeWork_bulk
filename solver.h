/*!
\file
\brief
*/
#pragma once

class CommandsStorage;

class Solver
{
public:
    explicit Solver(CommandsStorage& commStor) :commandStorage(commStor){}
    virtual void solve() = 0;
    virtual ~Solver(){}

protected:
    CommandsStorage& commandStorage;
};

