#pragma once
#include "CommandBase.h"

class IsReadyCommand : public CommandBase
{
public:
    IsReadyCommand(std::shared_ptr<UciClient> _uci_client);
    ~IsReadyCommand();
    void Execute(std::vector<std::string> _args) override;
};