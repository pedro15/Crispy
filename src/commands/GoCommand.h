#include "CommandBase.h"
#include "../lib/threadpool.h"

class GoCommand : public CommandBase
{
private:
    void Run();
public:
    GoCommand(UciClient* uci_client);
    ~GoCommand();
    void Execute(std::vector<std::string> args) override;
    
};