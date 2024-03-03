#include "uci.h"
#include <string>
class ucicommand
{
private:
    uci &uci_client;
public:
    ucicommand(uci &uci_client_);
    ~ucicommand();
    virtual void Execute(const std::string args[]);
};