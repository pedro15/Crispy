#pragma once
#include <string>
#include <iostream>
#include <cctype>
#include "lib/strutil.h"
#include "BoardPosition.h"

namespace notation
{
    const std::string FEN_STARTPOS = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    const std::string FEN_KIWIPETE = "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq -";
    
    static std::string GetFENFromArgs(const std::vector<std::string> _args)
    {
        std::stringstream result;
        for (int i = 0; i < _args.size(); i++)
        {
            if (_args[i] == "fen" || _args[i] == "position")
            {
                continue;
            }
            else if (_args[i] == "startpos")
            {
                return FEN_STARTPOS;
            }
            else if (_args[i] == "kiwipete")
            {
                return FEN_KIWIPETE;
            }
            else if (_args[i] == "moves")
            {
                break;
            }

            result << _args[i];
            if (i < _args.size() - 1 && _args[i + 1] != "moves")
                result << " ";
        }
        return result.str();
    }

    static std::string GetFENFromPosition(const BoardPosition* _pos)
    {
        const std::string pieces_fen_b = "pnbrqk*";
        const std::string pieces_fen_w = "PNBRQK*";
        std::stringstream ss;
        Bitboard mask_pc, occ = (_pos->colors[Color::Black] | _pos->colors[Color::White]);
        Color target_color;
        int rank,file,pc,color, steps = 0;
        Square sq;

        // Piece placement
        for (rank = 7; rank >= 0; rank--)
        {
            for (file = 0; file < 8; file++)
            {
                sq = Square(file, rank);

                if (occ.Contains(sq))
                {
                    if (steps > 0)
                    {
                        ss << steps;
                        steps = 0;
                    }
                    
                    target_color = _pos->colors[Color::Black].Contains(sq) ? Color::Black : Color::White;
                    for (pc = Piece::Pawn; pc <= Piece::King; pc++)
                    {
                        mask_pc = _pos->pieces[pc] & _pos->colors[target_color];
                        if (mask_pc.Contains(sq))
                        {
                            if (target_color == Color::Black)
                                ss << pieces_fen_b[pc];
                            else 
                                ss << pieces_fen_w[pc];
                            break;
                        }
                    }
                }else
                {
                    steps++;
                }

                if (file == 7)
                {
                    if (steps > 0)
                    {
                        ss << steps;
                        steps = 0;
                    }

                    if (rank > 0)
                        ss << "/";
                }
            }
        }
        // side to move
        ss << " " << ((_pos->side == Color::White) ? "w" : "b");
        // castle
        ss << " " << _pos->castle_rights.Str();
        // en-passant
        if (_pos->en_passant > Square::a1)
        {
            ss << " " << _pos->en_passant.Str();
        }else 
        {
            ss << " " << "-";
        }

        if (_pos->half_moves > 0 || _pos->full_moves > 0)
        {
            // half move clock
            ss << " " << (int)_pos->half_moves;
            // full move counter
            ss << " " << (int)_pos->full_moves;
        }
        return ss.str();
    }
    
    static BoardPosition ParseFEN(const std::string _fen)
    {
        enum FEN_STATE : int { Piece_Placement = 0, Side_To_Move = 1, Castling = 2, 
                               En_Passant = 3, Halfmove_clock = 4, Fullmove_counter = 5 };
        
        BoardPosition result = BoardPosition();
        result.pieces = std::array<Bitboard,6>();
        result.colors = std::array<Bitboard,2>();

        FEN_STATE current_state = FEN_STATE::Piece_Placement;
        std::vector<std::string> fen_sections = strutil::split(_fen, " ");
        int index;

        for (std::string &fen_elm : fen_sections)
        {
            switch(current_state)
            {
                case FEN_STATE::Piece_Placement:
                {
                    int square_index = 0;
                    for (index = 0; index < fen_elm.length(); index++)
                    {
                        if (isdigit(fen_elm[index]))
                        {
                            square_index += (fen_elm[index] - '0');
                        }else
                        {
                            switch(fen_elm[index])
                            {
                                default:
                                    continue;

                                // - Square has to be inverted to match endianness

                                // -------- Black Pieces --------
                                
                                // - black Pawn
                                case 'p':
                                    result.pieces[Piece::Pawn].SetBit(square_index ^ 56);
                                    result.colors[Color::Black].SetBit(square_index ^ 56);
                                break;

                                // - black Knight
                                case 'n':
                                    result.pieces[Piece::Knight].SetBit(square_index ^ 56);
                                    result.colors[Color::Black].SetBit(square_index ^ 56);
                                break;
                                
                                // - black Bishop
                                case 'b':
                                    result.pieces[Piece::Bishop].SetBit(square_index ^ 56);
                                    result.colors[Color::Black].SetBit(square_index ^ 56);
                                break;

                                // - black Rook
                                case 'r':
                                    result.pieces[Piece::Rook].SetBit(square_index ^ 56);
                                    result.colors[Color::Black].SetBit(square_index ^ 56);
                                break;

                                // - black Queen
                                case 'q':
                                    result.pieces[Piece::Queen].SetBit(square_index ^ 56);
                                    result.colors[Color::Black].SetBit(square_index ^ 56);
                                break;

                                // - black King
                                case 'k':
                                    result.pieces[Piece::King].SetBit(square_index ^ 56);
                                    result.colors[Color::Black].SetBit(square_index ^ 56);
                                break;

                                // -------- White Pieces --------

                                // - white Pawn
                                case 'P':
                                    result.pieces[Piece::Pawn].SetBit(square_index ^ 56);
                                    result.colors[Color::White].SetBit(square_index ^ 56);
                                break;

                                // - white Knight
                                case 'N':
                                    result.pieces[Piece::Knight].SetBit(square_index ^ 56);
                                    result.colors[Color::White].SetBit(square_index ^ 56);
                                break;

                                // - white Bishop
                                case 'B':
                                    result.pieces[Piece::Bishop].SetBit(square_index ^ 56);
                                    result.colors[Color::White].SetBit(square_index ^ 56);
                                break;

                                // - white Rook
                                case 'R':
                                    result.pieces[Piece::Rook].SetBit(square_index ^ 56);
                                    result.colors[Color::White].SetBit(square_index ^ 56);
                                break;

                                // - white Queen
                                case 'Q':
                                    result.pieces[Piece::Queen].SetBit(square_index ^ 56);
                                    result.colors[Color::White].SetBit(square_index ^ 56);
                                break;

                                // - white King
                                case 'K':
                                    result.pieces[Piece::King].SetBit(square_index ^ 56);
                                    result.colors[Color::White].SetBit(square_index ^ 56);
                                break;
                            }
                            square_index++;
                        }
                    }
                }
                break;

                case FEN_STATE::Side_To_Move:
                {
                    result.side = (fen_elm == "w") ? Color::White : Color::Black;
                }
                break;

                case FEN_STATE::Castling:
                {
                    result.castle_rights = Castle::None;
                    
                    for (index = 0; index < fen_elm.length(); index++)
                    {
                        switch(fen_elm[index])
                        {
                            // black king-side
                            case 'k':
                                result.castle_rights |= Castle::Black_King;
                            break;

                            // black queen-side
                            case 'q':
                                result.castle_rights |= Castle::Black_Queen;
                            break;
                            
                            // white king-side
                            case 'K':
                                result.castle_rights |= Castle::White_King;
                            break;
                            
                            // white queen-side
                            case 'Q':
                                result.castle_rights |= Castle::White_Queen;
                            break;
                        }
                    }
                }
                break;

                case FEN_STATE::En_Passant:
                {
                    if (Square::Valid(fen_elm))
                    {
                        result.en_passant = Square(fen_elm);
                    }else 
                    {
                        result.en_passant = Square::a1;
                    }
                }
                break;

                case FEN_STATE::Halfmove_clock:
                {
                    result.half_moves = (uint8_t)std::stoi(fen_elm);
                }
                break;

                case FEN_STATE::Fullmove_counter:
                {
                    result.full_moves = (uint16_t)std::stoi(fen_elm);
                }
                break;
            }

            current_state = static_cast<FEN_STATE>((int)current_state + 1);
        }
        
        return result;
    }


    static std::string PrintPosition(const BoardPosition* _pos)
    {
        std::stringstream ss;
        int file,rank,pc,color;
        Square sq;
        Bitboard mask_sq, mask_pc;
        bool piece_found;

        for (rank = 0; rank < 8; rank++)
        {
            ss << 8 - rank << "  ";
            for (file = 0; file < 8; file++)
            {
                sq = Square(file,rank).Invert();
                mask_sq = 1ULL << sq;
                piece_found = false;
                for (pc = Piece::Pawn; pc <= Piece::King; pc++)
                {
                    for (color = Color::Black; color <= Color::White; color++)
                    {
                        mask_pc = _pos->pieces[pc] & _pos->colors[color];
                        piece_found = mask_sq & mask_pc;
                        if (piece_found)
                        {
                            switch(pc)
                            {
                                case Piece::Pawn:
                                    if (color == Color::Black)
                                        ss << "p ";
                                    else 
                                        ss << "P ";
                                break;

                                case Piece::Knight:
                                    if (color == Color::Black)
                                        ss << "n ";
                                    else 
                                        ss << "N ";
                                break;

                                case Piece::Bishop:
                                    if (color == Color::Black)
                                        ss << "b ";
                                    else 
                                        ss << "B ";
                                break;

                                case Piece::Rook:
                                    if (color == Color::Black)
                                        ss << "r ";
                                    else 
                                        ss << "R ";
                                break;

                                case Piece::Queen:
                                    if (color == Color::Black)
                                        ss << "q ";
                                    else 
                                        ss << "Q ";
                                break;

                                case Piece::King:
                                    if (color == Color::Black)
                                        ss << "k ";
                                    else 
                                        ss << "K ";
                                break;
                            }
                            break;
                        }
                    }
                    if (piece_found) break;
                }
                if (!piece_found)
                {
                    ss << ". ";
                }
            }
            ss << "\n";
        }

        ss << "   a b c d e f g h";
        ss << "\n\n";
        ss << "side: " << _pos->side.Str() << std::endl;
        ss << "castle: " << _pos->castle_rights.Str() << std::endl;
        ss << "en-passant: ";
        if (_pos->en_passant == Square::a1)
        {
            ss << "none" << std::endl;
        }else 
        {
            ss <<  _pos->en_passant.Str() << std::endl;
        }
        ss << "half-moves: " << (int)_pos->half_moves << std::endl;
        ss << "full-moves: " << (int)_pos->full_moves << std::endl;
        ss << "bitboard: 0x" << std::hex << (uint64_t)(_pos->colors[Color::Black] | _pos->colors[Color::White]) << std::endl;
        ss << "fen: " << GetFENFromPosition(_pos) << std::endl;
        return ss.str();
    }
    
    static std::string PrintBitboard(uint64_t _bb_value)
    {
        std::stringstream ss;
        int file,rank;
        Square sq;
        uint64_t mask;

        for (rank = 0; rank < 8; rank++)
        {
            ss << 8 - rank << "  ";
            for (file = 0; file < 8; file++)
            {
                sq = Square(file, rank).Invert();
                mask = 1ULL << sq;
                
                if (mask & _bb_value)
                {
                    ss << "1 ";
                }else
                {
                    ss << ". ";
                }
            }
            ss << "\n";
        }
        ss << "   a b c d e f g h";
        ss << "\n";
        ss << "   0x" << std::hex << _bb_value << std::endl;
        return ss.str();
    }
}