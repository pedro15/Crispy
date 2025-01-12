#include "RunTestsCommand.h"

RunTestsCommand::RunTestsCommand(std::shared_ptr<UciClient> _uci_client) : CommandBase(_uci_client) { }
RunTestsCommand::~RunTestsCommand() { }

void RunTestsCommand::Execute(const std::vector<std::string> _params)
{
    bool success = false;
    if (HasParam("fen", _params))
    {
        success = tests_notation::IsFENGenerationCorrect();
    }else if (HasParam("board_utils", _params))
    {
        success = tests_board_utils::IsDistancesValid();
    }else
    {
        std::cout << "Invalid arguments" << std::endl;
        return;
    }
    
    PrintResults(success);
}