#include "IsReadyCommand.h"

IsReadyCommand::IsReadyCommand(UciClient* uci_client) : CommandBase(uci_client) { }
IsReadyCommand::~IsReadyCommand() { }

void IsReadyCommand::Execute(std::vector<std::string> args) 
{
    std::cout << "readyok" << std::endl;
}