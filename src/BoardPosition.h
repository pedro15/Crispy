#include "Bitboard.h"
#include <cstdint>
#include <array>

struct BoardPosition
{
    public:
        std::array<Bitboard,7> bitboards;
        std::array<Bitboard,2> colors;
        uint8_t side;
        uint8_t castle;
        uint8_t halfMoves;
        uint8_t fullMoves;

        BoardPosition(const std::array<Bitboard,7> bitboards, const std::array<Bitboard,2> colors, uint8_t side, uint8_t castle, uint8_t half_moves, uint8_t full_moves)
        {
            this->bitboards = bitboards;
            this->colors = colors;
            this->side = side;
            this->castle = castle;
            this->halfMoves = half_moves;
            this->fullMoves = full_moves;
        }
        ~BoardPosition() { }
};