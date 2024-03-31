#include "CommandBase.h"

class QuitCommand : public CommandBase
{
public:
    QuitCommand(UciClient* uci_client);
    ~QuitCommand();
    void Execute(const std::vector<std::string> params) override;
};