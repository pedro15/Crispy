#pragma once
#include <vector>
#include "commands/CommandBase.h"

class CommandBase;
class Uci
{
private:
    bool is_running;
    std::vector<CommandBase*> commands;
public:
    Uci();
    ~Uci();
    void Run();
    void Stop();
};