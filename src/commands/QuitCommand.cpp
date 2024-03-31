#include "QuitCommand.h"

QuitCommand::QuitCommand(UciClient* uci_client) : CommandBase(uci_client) { }

void QuitCommand::Execute(const std::vector<std::string> params)
{
    m_uci_client->Stop();
}

QuitCommand::~QuitCommand(){ }