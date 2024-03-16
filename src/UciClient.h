#pragma once
#include <vector>
#include "commands/CommandBase.h"

class CommandBase;
class UciClient
{
private:
    bool m_isRunning;
    std::vector<CommandBase*> m_commands;
public:
    UciClient();
    ~UciClient();
    void Run();
    void Stop();
};