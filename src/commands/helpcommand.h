#pragma once
#include "../uci.h"
#include "commandbase.h"

class helpcommand : commandbase
{
private:

public:
    helpcommand(uci &uci_client);
    ~helpcommand();
    void Execute(const std::vector<std::string> args) override;
};