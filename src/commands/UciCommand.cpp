#include "UciCommand.h"
#include "../Types.h"
#include "../Info.h"

UciCommand::UciCommand(std::shared_ptr<UciClient> _uci_client) : CommandBase(_uci_client) { }
UciCommand::~UciCommand() { }

void UciCommand::Execute(const std::vector<std::string> _params)
{
    std::cout << "id name " << ENGINE_NAME << " " << ENGINE_VERSION << std::endl;
    std::cout << "id author " << ENGINE_AUTHOR << std::endl;
    std::cout << "uciok" << std::endl;
}