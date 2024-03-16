#pragma once
#include <string>
#include <vector>
#include "../UciClient.h"

class UciClient;
class CommandBase
{
protected:
    UciClient* m_uciClient;
public:
    CommandBase(UciClient* uciClient);
    ~CommandBase();
    virtual void Execute(const std::vector<std::string> args);
};