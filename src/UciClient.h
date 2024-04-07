#pragma once
#include <vector>
#include <map>
#include "commands/CommandBase.h"

class CommandBase;
class UciClient
{
private:
    bool m_isRunning;
    bool m_abort_requested;
    std::map<std::string,CommandBase*> m_commands;
public:
    UciClient();
    ~UciClient();
    void Run();
    void Stop();
    void AbortTask(bool abort);
    bool IsAbortRequqested(); 
};