#pragma once
#include "../UciClient.h"
#include "CommandBase.h"

class HelpCommand : public CommandBase
{
public:
    HelpCommand(UciClient* a_uci_client);
    ~HelpCommand();
    void Execute(const std::vector<std::string> a_params) override;
};