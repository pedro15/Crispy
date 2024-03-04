#pragma once
#include <vector>
#include "commands/commandbase.h"

class CommandBase;
class Uci
{
private:
    bool is_running;
    std::vector<CommandBase*> commands_;
public:
    Uci();
    ~Uci();
    void Run();
    void Stop();
};