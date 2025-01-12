#pragma once
#include "CommandBase.h"

class VersionCommand : public CommandBase
{
public:
    VersionCommand(std::shared_ptr<UciClient> _uci_client);
    ~VersionCommand();
    void Execute(const std::vector<std::string> _params) override;
};