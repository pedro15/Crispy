#include <chrono>
#include <thread>
#include <iostream>
#include "CommandBase.h"
#include "../Types.h"
#include "../Info.h"
#include "../UciClient.h"
#include "../lib/threadpool.h"
#include "../Notation.h"

#include "../../tests/tests_notation.h"
#include "../../tests/tests_board_utils.h"

static COMMAND_FN command_runTests = [](const std::vector<std::string> m_args , std::shared_ptr<UciClient> m_client) 
{
    bool success = false;
    if (HasParam("fen", m_args))
    {
        success = tests_notation::IsFENGenerationCorrect();
    }else if (HasParam("board_utils", m_args))
    {
        success = tests_board_utils::IsDistancesValid();
    }else
    {
        std::cout << "Invalid arguments" << std::endl;
        return;
    }

    PrintTestsResults(success);
};