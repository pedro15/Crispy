#include "Types.h"
#include "BoardUtils.h"

namespace MoveGenerator 
{
    // ---------- PAWNS ----------

    inline Bitboard PawnsAbleToPush(const Bitboard _pawns, const Bitboard _empty, const Color _color)
    {
        switch(_color)
        {
            case Color::White:
                return BoardUtils::D_South(_empty) & _pawns;

            case Color::Black:
                return BoardUtils::D_North(_empty) & _pawns;
        }

        return 0ULL;
    }

    inline Bitboard PawnsAbleToDoublePush(const Bitboard _pawns, const Bitboard _empty, const Color _color)
    {
        Bitboard empty_rank = 0;
        switch (_color)
        {
            case Color::White:
                empty_rank = BoardUtils::D_South(_empty & BoardUtils::RANKS[3]) & _empty;
                return PawnsAbleToPush(_pawns, empty_rank, _color);

            case Color::Black:
                empty_rank = BoardUtils::D_North(_empty & BoardUtils::RANKS[4]) & _empty;
                return PawnsAbleToPush(_pawns, empty_rank, _color);
        }
        return 0ULL;
    }

    inline Bitboard PawnSinglePush(const Square _sq, const Bitboard _empty, const Color _color)
    {
        Bitboard pawn_bb = Bitboard(_sq);
        switch (_color)
        {
            case Color::White:
                return BoardUtils::D_North(pawn_bb) & _empty;
            
            case Color::Black:
                return BoardUtils::D_South(pawn_bb) & _empty;
        }
    }

    inline Bitboard PawnDoublePush(const Square _sq, const Bitboard _empty, const Color _color)
    {
        Bitboard single_pushs = 0ULL;
        Bitboard pawn_bb = Bitboard(_sq);
        
        switch(_color)
        {
            case Color::White:
                single_pushs = BoardUtils::D_North(pawn_bb) & _empty;
                return BoardUtils::D_North(single_pushs) & _empty & BoardUtils::RANKS[3];

            case Color::Black:
                single_pushs = BoardUtils::D_South(pawn_bb) & _empty;
                return BoardUtils::D_South(single_pushs) & _empty & BoardUtils::RANKS[4];
        }

        return 0ULL;
    }
}