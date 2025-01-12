#pragma once

#include <iostream>
#include <cstdint>

struct MagicEntry
{
    public:
        const uint64_t mask;
        const uint64_t magic;
        const uint8_t offest;
        MagicEntry(uint64_t _mask, uint64_t _magic, uint8_t _offest) : mask(_mask), magic(_magic), offest(_offest){ }
};