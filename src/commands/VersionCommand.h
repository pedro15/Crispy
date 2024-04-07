#include "CommandBase.h"

class VersionCommand : public CommandBase
{
public:
    VersionCommand(UciClient* uci_client);
    ~VersionCommand();
    void Execute(const std::vector<std::string> params) override;
};