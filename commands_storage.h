/*!
\file
\brief
*/
#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <chrono>
#include <ctime>
#include <fstream>
#include <sstream>
#include <memory>

//#include "solver.h"
class Solver;

class CommandsStorage
{
public:
    CommandsStorage(std::size_t bulkSize);

    void addString(const std::string& str);

    void save();


    void print() const;

    bool bracketEmpty() const;
    std::size_t commandsSize() const;
    std::size_t bulkSize() const;

private:
    std::stack<std::string> bracketStack;
    std::vector<std::string> commandsVector;
    std::chrono::system_clock::time_point firstBulkTime;
    std::size_t bulkSize_;
    std::shared_ptr<Solver> solver;

    void addCommand(const std::string& command);

    void addBracket(const std::string& bracket);

    std::string bulkCommandString() const;

    void clear();
};
