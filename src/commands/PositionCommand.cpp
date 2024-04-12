#include "PositionCommand.h"

PositionCommand::PositionCommand(std::shared_ptr<UciClient> uci_client) : CommandBase(uci_client) { }
PositionCommand::~PositionCommand() { }

void PositionCommand::Execute(const std::vector<std::string> params)
{
    auto begin = params.begin();
    auto end = params.end();
    
    if(std::find(begin, end, "fen") != end)
    {
        std::cout << "fen is: '" << GetFEN(params) << "'" << std::endl;
    }else 
    {
        std::cout << "Invalid arguments" << std::endl;
    }
}

