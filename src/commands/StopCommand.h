#pragma once
#include "CommandBase.h"

class StopCommand : public CommandBase
{
private:
public:
    StopCommand(std::shared_ptr<UciClient> _uci_client);
    ~StopCommand();
    void Execute(std::vector<std::string> _args) override;
};