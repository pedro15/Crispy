#include "Bitboard.h"

Bitboard::Bitboard(uint64_t value)
{
    m_value = value;
}

Square Bitboard::Current()
{

    return Square(0);
}

bool Bitboard::MoveNext()
{
    return false;
}