#include "UciCommand.h"
#include "../Types.h"

UciCommand::UciCommand(UciClient* uci_client) : CommandBase(uci_client) { }
UciCommand::~UciCommand() { }

void UciCommand::Execute(const std::vector<std::string> params)
{
    std::cout << "id name Crispy " << ENGINE_VERSION << std::endl;
    std::cout << "id author Pedro Duran" << std::endl;
    std::cout << "uciok" << std::endl;
}