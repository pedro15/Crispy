#include "QuitCommand.h"

QuitCommand::QuitCommand(std::shared_ptr<UciClient> _uci_client) : CommandBase(_uci_client) { }
QuitCommand::~QuitCommand(){ }

void QuitCommand::Execute(const std::vector<std::string> _params)
{
    m_uci_client->Stop();
}

