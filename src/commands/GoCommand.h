#pragma once
#include "CommandBase.h"
#include "../lib/threadpool.h"

class GoCommand : public CommandBase
{
private:
    void Run();
public:
    GoCommand(std::shared_ptr<UciClient> _uci_client);
    ~GoCommand();
    void Execute(std::vector<std::string> _args) override;
};