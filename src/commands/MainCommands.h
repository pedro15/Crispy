#include <chrono>
#include <thread>
#include <iostream>
#include "CommandBase.h"
#include "../Types.h"
#include "../Info.h"
#include "../UciClient.h"
#include "../lib/threadpool.h"
#include "../Notation.h"

ThreadPool bg_thread(1);

static COMMAND_FN command_version = [](const std::vector<std::string> m_args , std::shared_ptr<UciClient> m_client)
{
    std::cout << ENGINE_VERSION << std::endl;
};

static COMMAND_FN command_help = [](const std::vector<std::string> m_args , std::shared_ptr<UciClient> m_client)
{
    std::cout << " Crispy is meant to be used with a graphical user interface (GUI) \n and implements the Universal Chess Interface (UCI) protocol to communicate with a GUI, etc.." << std::endl;
    std::cout << " please refer to HomePage (" << HOMEPAGE << ") for more details about available commands." << std::endl;
};

static COMMAND_FN command_quit = [](const std::vector<std::string> m_args, std::shared_ptr<UciClient> m_client)
{
    m_client->Stop();
};

static COMMAND_FN command_uci = [](const std::vector<std::string> m_args, std::shared_ptr<UciClient> m_client)
{
    std::cout << "id name " << ENGINE_NAME << " " << ENGINE_VERSION << std::endl;
    std::cout << "id author " << ENGINE_AUTHOR << std::endl;
    std::cout << "uciok" << std::endl;
};

static COMMAND_FN command_isReady = [](const std::vector<std::string> m_args, std::shared_ptr<UciClient> m_client)
{
    std::cout << "readyok" << std::endl;
};

static COMMAND_FN command_position = [](const std::vector<std::string> m_args, std::shared_ptr<UciClient> m_client) 
{
    if(HasParam("fen", m_args) || HasParam("startpos", m_args) || HasParam("kiwipete", m_args))
    {
        std::string fen = notation::GetFENFromArgs(m_args);
        std::cout << "fen is: '" << fen << "'" << std::endl;
        BoardPosition pos = notation::ParseFEN(fen);
        std::cout << "pieces" << std::endl;
        
        std::cout << "pawn" << std::endl;
        std::cout << notation::PrintBitboard(pos.pieces[Piece::Pawn]) << std::endl;
        std::cout << "knight" << std::endl;
        std::cout << notation::PrintBitboard(pos.pieces[Piece::Knight]) << std::endl;
        std::cout << "bishop" << std::endl;
        std::cout << notation::PrintBitboard(pos.pieces[Piece::Bishop]) << std::endl;
        std::cout << "rook" << std::endl;
        std::cout << notation::PrintBitboard(pos.pieces[Piece::Rook]) << std::endl;
        std::cout << "queen" << std::endl;
        std::cout << notation::PrintBitboard(pos.pieces[Piece::Queen]) << std::endl;
        std::cout << "king" << std::endl;
        std::cout << notation::PrintBitboard(pos.pieces[Piece::King]) << std::endl;
        std::cout << "black" << std::endl;
        std::cout << notation::PrintBitboard(pos.colors[Color::Black]) << std::endl;
        std::cout << "white" << std::endl;
        std::cout << notation::PrintBitboard(pos.colors[Color::White]) << std::endl;
        std::cout << std::endl;
        std::cout << "position:" << std::endl;
        std::cout << notation::PrintPosition(&pos) << std::endl;
    }else 
    {
        std::cout << "Invalid arguments" << std::endl;
    }
};

static COMMAND_FN command_go = [](const std::vector<std::string> m_args , std::shared_ptr<UciClient> m_client)
{
    bg_thread.enqueue([m_args,m_client]
    { 
        // Placeholder function for now to test command abort
        int counter = 2000;
        while (counter > 0)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            counter--;

            if (m_client->IsAbortRequqested()) break;
        }
        std::cout << "bestmove d2d4" << std::endl;
    }); 
};

static COMMAND_FN command_stop = [](const std::vector<std::string> m_args, std::shared_ptr<UciClient> m_client)
{
    m_client->AbortCurrentTask();
};