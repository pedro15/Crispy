#pragma once
#include <string>
#include <vector>
#include "../UciClient.h"

class UciClient;
class CommandBase
{
protected:
    UciClient* m_uci_client;
public:
    CommandBase(UciClient* a_uci_client);
    ~CommandBase();
    virtual void Execute(const std::vector<std::string> a_params);
};