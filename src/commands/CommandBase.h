#pragma once
#include <string>
#include <vector>
#include "../uci.h"

class Uci;
class CommandBase
{
protected:
    Uci* uci_client_;
public:
    CommandBase(Uci* uci_client);
    ~CommandBase();
    virtual void Execute(const std::vector<std::string> args);
};