#pragma once
#include <string>
#include <vector>
#include "../Uci.h"

class Uci;
class CommandBase
{
protected:
    Uci* uciClient;
public:
    CommandBase(Uci* uci_client);
    ~CommandBase();
    virtual void Execute(const std::vector<std::string> args);
};