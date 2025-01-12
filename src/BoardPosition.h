#pragma once
#include <cstdint>
#include <array>

struct BoardPosition
{
    std::array<Bitboard,6> pieces;
    std::array<Bitboard,2> colors;
    Color side;
    Castle castle_rights;
    Square en_passant;
    uint8_t half_moves;
    uint16_t full_moves;
};