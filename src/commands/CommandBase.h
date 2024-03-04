#pragma once
#include <string>
#include <vector>
#include "../Uci.h"

class Uci;
class CommandBase
{
protected:
    Uci* uci_client;
public:
    CommandBase(Uci* uciClient);
    ~CommandBase();
    virtual void Execute(const std::vector<std::string> args);
};