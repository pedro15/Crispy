#pragma once
#include "../uci.h"
#include "commandbase.h"

class helpcommand : public commandbase
{
public:
    helpcommand(uci* uci_client);
    ~helpcommand();
    void Execute(const std::vector<std::string> args) override;
};