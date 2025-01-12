#pragma once
#include "../UciClient.h"
#include "../Types.h"
#include "CommandBase.h"

class HelpCommand : public CommandBase
{
public:
    HelpCommand(std::shared_ptr<UciClient> _uci_client);
    ~HelpCommand();
    void Execute(const std::vector<std::string> _params) override;
};