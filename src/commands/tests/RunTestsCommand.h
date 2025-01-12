#pragma once
#include "../CommandBase.h"
#include "../../tests/tests_notation.h"
#include "../../tests/tests_board_utils.h"

class RunTestsCommand : public CommandBase
{
private:

public:
    RunTestsCommand(std::shared_ptr<UciClient> _uci_client);
    ~RunTestsCommand();
    void Execute(std::vector<std::string> _args) override;
};

static void PrintResults(bool _success)
{
    if (_success)
    {
        std::cout << "[SUCCESS] test suite completed!" << std::endl;
    }else
    {
        std::cout << "[ERROR] test suite failed with errors" << std::endl;
    }
}