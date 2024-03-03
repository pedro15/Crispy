#pragma once
#include "../uci.h"
#include <string>
#include <vector>

class commandbase
{
protected:
    uci &uci_client_;
public:
    commandbase(uci &uci_client);
    ~commandbase();
    virtual void Execute(const std::vector<std::string> args);
};