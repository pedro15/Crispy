#include "ExitCommand.h"

ExitCommand::ExitCommand(UciClient* uci_client) : CommandBase(uci_client) { }

void ExitCommand::Execute(const std::vector<std::string> params)
{
    m_uci_client->Stop();
}

ExitCommand::~ExitCommand(){ }