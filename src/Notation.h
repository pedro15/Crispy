#pragma once
#include <string>
#include <iostream>

namespace notation
{
    const std::string FEN_STARTPOS = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    const std::string FEN_KIWIPETE = "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq -";

    static std::string GetFENFromCMD(const std::vector<std::string> cmd_args)
    {
        std::stringstream result;
        for (int i = 0; i < cmd_args.size(); i++)
        {
            if (cmd_args[i] == "fen" || cmd_args[i] == "position")
            {
                continue;
            }
            else if (cmd_args[i] == "startpos")
            {
                return FEN_STARTPOS;
            }
            else if (cmd_args[i] == "kiwipete")
            {
                return FEN_KIWIPETE;
            }
            else if (cmd_args[i] == "moves")
            {
                break;
            }

            result << cmd_args[i];
            if (i < cmd_args.size() - 1 && cmd_args[i + 1] != "moves")
                result << " ";
        }
        return result.str();
    }

}