#include "StopCommand.h"

StopCommand::StopCommand(UciClient* uci_client) : CommandBase(uci_client){ }
StopCommand::~StopCommand(){ }

void StopCommand::Execute(std::vector<std::string> agrs)
{
    m_uci_client->AbortTask(true);
}