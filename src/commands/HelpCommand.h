#pragma once
#include "../Uci.h"
#include "CommandBase.h"

class HelpCommand : public CommandBase
{
public:
    HelpCommand(Uci* uci_client);
    ~HelpCommand();
    void Execute(const std::vector<std::string> args) override;
};