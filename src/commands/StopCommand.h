#pragma once
#include "CommandBase.h"

class StopCommand : public CommandBase
{
private:
public:
    StopCommand(UciClient* uci_client);
    ~StopCommand();
    void Execute(std::vector<std::string> args) override;
};