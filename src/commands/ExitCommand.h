#include "CommandBase.h"

class ExitCommand : public CommandBase
{
public:
    ExitCommand(UciClient* uci_client);
    ~ExitCommand();
    void Execute(const std::vector<std::string> params) override;
};
