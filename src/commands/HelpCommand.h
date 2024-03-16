#pragma once
#include "../UciClient.h"
#include "CommandBase.h"

class HelpCommand : public CommandBase
{
public:
    HelpCommand(UciClient* uciClient);
    ~HelpCommand();
    void Execute(const std::vector<std::string> args) override;
};