#pragma once
#include <memory>
#include <vector>
#include <map>
#include "commands/CommandBase.h"

class CommandBase;
class UciClient
{
private:
    bool m_isRunning;
    bool m_abort_requested;
    std::map<std::string,std::unique_ptr<CommandBase>> m_commands;
    void AddCommand(std::string cmd, CommandBase* val);
public:
    UciClient();
    ~UciClient();
    void Run();
    void Stop();
    void AbortTask(bool abort);
    bool IsAbortRequqested(); 
};