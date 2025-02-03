#pragma once
#include <map>
#include <memory>
#include <vector>
#include <functional>
#include "lib/strutil.h"
#include "commands/CommandBase.h"

class UciClient : public std::enable_shared_from_this<UciClient>
{
private:
    bool m_is_running;
    bool m_abort_requested;
    std::map<const std::string,COMMAND_FN> m_commands;
    void AddCommand(const std::string _cmd, COMMAND_FN _command);
public:
    UciClient();
    ~UciClient();
    void Init();
    void Run();
    void Stop();
    void AbortCurrentTask();
    bool IsAbortRequqested(); 
};