#include "VersionCommand.h"
#include "../Types.h"

VersionCommand::VersionCommand(UciClient* uci_client) : CommandBase(uci_client) { }

void VersionCommand::Execute(const std::vector<std::string> params)
{
    std::cout << ENGINE_VERSION << std::endl;
}

VersionCommand::~VersionCommand() { }