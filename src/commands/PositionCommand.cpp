#include "PositionCommand.h"
#include "../Notation.h"

PositionCommand::PositionCommand(std::shared_ptr<UciClient> _uci_client) : CommandBase(_uci_client) { }
PositionCommand::~PositionCommand() { }

void PositionCommand::Execute(const std::vector<std::string> _params)
{
    if(HasParam("fen", _params) || HasParam("startpos", _params) || HasParam("kiwipete", _params))
    {
        std::string fen = notation::GetFENFromArgs(_params);
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
}