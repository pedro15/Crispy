#pragma once
#include "CommandBase.h"

class PositionCommand : public CommandBase
{
public:
    PositionCommand(std::shared_ptr<UciClient> _uci_client);
    ~PositionCommand();
    void Execute(const std::vector<std::string> _params) override;
};
