#include "VersionCommand.h"
#include "../Info.h"

VersionCommand::VersionCommand(std::shared_ptr<UciClient> _uci_client) : CommandBase(_uci_client) { }

void VersionCommand::Execute(const std::vector<std::string> _params)
{
    std::cout << ENGINE_VERSION << std::endl;
}

VersionCommand::~VersionCommand() { }