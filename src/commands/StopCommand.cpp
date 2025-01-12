#include "StopCommand.h"

StopCommand::StopCommand(std::shared_ptr<UciClient> _uci_client) : CommandBase(_uci_client){ }
StopCommand::~StopCommand(){ }

void StopCommand::Execute(std::vector<std::string> _agrs)
{
    m_uci_client->AbortTask(true);
}