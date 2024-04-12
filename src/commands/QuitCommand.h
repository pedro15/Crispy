#pragma once
#include "CommandBase.h"

class QuitCommand : public CommandBase
{
public:
    QuitCommand(std::shared_ptr<UciClient> uci_client);
    ~QuitCommand();
    void Execute(const std::vector<std::string> params) override;
};