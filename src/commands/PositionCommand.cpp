#include "PositionCommand.h"
#include "../Notation.h"

PositionCommand::PositionCommand(std::shared_ptr<UciClient> uci_client) : CommandBase(uci_client) { }
PositionCommand::~PositionCommand() { }

void PositionCommand::Execute(const std::vector<std::string> params)
{
    auto begin = params.begin();
    auto end = params.end();

    if(std::find(begin, end, "fen") != end || std::find(begin,end, "startpos") != end || std::find(begin,end, "kiwipete") != end)
    {
        std::cout << "fen is: '" << notation::GetFENFromCMD(params) << "'" << std::endl;
    }else 
    {
        std::cout << "Invalid arguments" << std::endl;
    }
}