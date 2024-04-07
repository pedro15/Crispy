#include "CommandBase.h"

class UciCommand : public CommandBase
{
public:
    UciCommand(UciClient* uci_client);
    ~UciCommand();
    void Execute(const std::vector<std::string> params) override;
};