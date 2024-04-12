#include "QuitCommand.h"

QuitCommand::QuitCommand(std::shared_ptr<UciClient> uci_client) : CommandBase(uci_client) { }
QuitCommand::~QuitCommand(){ }

void QuitCommand::Execute(const std::vector<std::string> params)
{
    m_uci_client->Stop();
}

