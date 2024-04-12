#pragma once
#include "CommandBase.h"

class StopCommand : public CommandBase
{
private:
public:
    StopCommand(std::shared_ptr<UciClient> uci_client);
    ~StopCommand();
    void Execute(std::vector<std::string> args) override;
};