#include "PositionCommand.h"

PositionCommand::PositionCommand(UciClient* uci_client) : CommandBase(uci_client) { }

void PositionCommand::Execute(const std::vector<std::string> params)
{
    if(std::find(params.begin(), params.end(), "fen") != params.end())
    {
        std::cout << "fen is: '" << GetFEN(params) << "'" << std::endl;
    }else 
    {
        std::cout << "Invalid arguments" << std::endl;
    }
}

PositionCommand::~PositionCommand() { }