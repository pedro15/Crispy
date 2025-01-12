#include <string>
#include <vector>
#include <iostream>
#include "tests_defs.h"
#include "../Notation.h"
#include "../BoardPosition.h"

namespace tests_notation
{
    static bool IsFENGenerationCorrect()
    {
        BoardPosition pos;
        std::string generated_fen;
        for (int i = 0; i < fen_suite.size(); i++)
        {
            pos = notation::ParseFEN(fen_suite[i]);
            generated_fen = notation::GetFENFromPosition(&pos);
            if (generated_fen != fen_suite[i])
            {
                std::cout  << "[ERROR] fen does not match at index: " << i << " = " << std::endl << " ref: " << fen_suite[i] << std::endl << " gen: " << generated_fen << std::endl;
                return false;
            }
        }
        std::cout << "[SUCCESS] test suite completed!" << std::endl;
        return true;
    }
}