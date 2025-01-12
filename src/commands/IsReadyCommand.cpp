#include "IsReadyCommand.h"

IsReadyCommand::IsReadyCommand(std::shared_ptr<UciClient> _uci_client) : CommandBase(_uci_client) { }
IsReadyCommand::~IsReadyCommand() { }

void IsReadyCommand::Execute(std::vector<std::string> _args) 
{
    std::cout << "readyok" << std::endl;
}