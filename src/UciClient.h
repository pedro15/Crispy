#pragma once
#include <memory>
#include <vector>
#include <map>
#include "commands/CommandBase.h"

class CommandBase;
class UciClient : public std::enable_shared_from_this<UciClient>
{
private:
    bool m_is_running;
    bool m_abort_requested;
    std::map<std::string,std::unique_ptr<CommandBase>> m_commands;
    void AddCommand(std::string _cmd, std::unique_ptr<CommandBase> _command);
public:
    UciClient();
    ~UciClient();
    void Init();
    void Run();
    void Stop();
    void AbortTask(bool _abort);
    bool IsAbortRequqested(); 
};