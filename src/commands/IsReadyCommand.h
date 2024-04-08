#pragma once
#include "CommandBase.h"

class IsReadyCommand : public CommandBase
{
public:
    IsReadyCommand(UciClient* uci_client);
    ~IsReadyCommand();
    void Execute(std::vector<std::string> args) override;
};