#pragma once
#include "CommandBase.h"

class PositionCommand : public CommandBase
{
public:
    PositionCommand(std::shared_ptr<UciClient> uci_client);
    ~PositionCommand();
    void Execute(const std::vector<std::string> params) override;
};
