#include "Bitboard.h"
#include <cstdint>
#include <array>

struct BoardPosition
{
    std::array<Bitboard,7> bitboards;
    std::array<Bitboard,2> colors;
    Color side;
    Castle castle;
    uint8_t halfMoves;
    uint8_t fullMoves;
};