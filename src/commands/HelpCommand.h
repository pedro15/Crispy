#pragma once
#include "../UciClient.h"
#include "../Types.h"
#include "CommandBase.h"

class HelpCommand : public CommandBase
{
public:
    HelpCommand(UciClient* uci_client);
    ~HelpCommand();
    void Execute(const std::vector<std::string> params) override;
};