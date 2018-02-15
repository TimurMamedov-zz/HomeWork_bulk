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

#include "solver.h"

class CommandsStorage
{
public:
    explicit CommandsStorage(std::size_t bulkSize);
    ~CommandsStorage();

    void addString(const std::string& str);

    void save();
    void clear();
    void print() const;

    bool bracketEmpty() const;
    std::size_t commandsSize() const;
    std::size_t bulkSize() const;
    std::string getCurrentString() const;

    void addCommand(const std::string& command);

    void addBracket(const std::string& bracket);

private:
    std::stack<std::string> bracketStack;
    std::string currentString;
    std::vector<std::string> commandsVector;
    std::chrono::system_clock::time_point firstBulkTime;
    const std::size_t bulkSize_;
    std::vector<std::shared_ptr<Solver> > solvers;

    std::string bulkCommandString() const;
};
