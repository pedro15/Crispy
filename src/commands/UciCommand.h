#pragma once
#include "CommandBase.h"

class UciCommand : public CommandBase
{
public:
    UciCommand(std::shared_ptr<UciClient> _uci_client);
    ~UciCommand();
    void Execute(const std::vector<std::string> _params) override;
};