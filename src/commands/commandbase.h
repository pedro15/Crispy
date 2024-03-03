#pragma once
#include <string>
#include <vector>
#include "../uci.h"

class commandbase
{
protected:
    uci &uci_client_;
public:
    commandbase(uci &uci_client);
    ~commandbase();
    virtual void Execute(const std::vector<std::string> args);
};