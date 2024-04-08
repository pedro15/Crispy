#pragma once
#include <string>
#include <cstdint>
#include "Types.h"

class Bitboard
{
private:
    uint64_t m_value;
    uint8_t m_count;
public:
    Bitboard(uint64_t value);
    ~Bitboard();
    bool MoveNext();
    Square Current();
};