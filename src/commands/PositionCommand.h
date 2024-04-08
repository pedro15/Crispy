#pragma once
#include "CommandBase.h"

class PositionCommand : public CommandBase
{
public:
    PositionCommand(UciClient* uci_client);
    ~PositionCommand();
    void Execute(const std::vector<std::string> params) override;
};
