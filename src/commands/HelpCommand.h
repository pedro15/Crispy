#pragma once
#include "../Uci.h"
#include "CommandBase.h"

class HelpCommand : public CommandBase
{
public:
    HelpCommand(Uci* uciClient);
    ~HelpCommand();
    void Execute(const std::vector<std::string> args) override;
};