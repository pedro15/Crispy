#include "Types.h"
#include <array>

namespace BoardUtils 
{
    /* ---------------------------------------------- 
    // - Masks
    // ------------------------------------------- */

    constexpr uint64_t BLACK_SQUARES  = 0x55aa55aa55aa55aaULL;
    constexpr uint64_t MASK_FILE_A    = 0xfefefefefefefefeULL;
    constexpr uint64_t MASK_FILE_H    = 0x7f7f7f7f7f7f7f7fULL;
    constexpr uint64_t MASK_FILE_AB   = 0xfcfcfcfcfcfcfcfcULL;
    constexpr uint64_t MASK_FILE_GH   = 0x3f3f3f3f3f3f3f3fULL;

    constexpr uint64_t MASK_CASTLE_QUEENSIDE_WHITE = 0x00000000000000eULL;
    constexpr uint64_t MASK_CASTLE_QUEENSIDE_BLACK = 0xe00000000000000ULL;
    constexpr uint64_t MASK_CASTLE_KINSIDE_WHITE   = 0x0000000000000060ULL;
    constexpr uint64_t MASK_CASTLE_KINGSIDE_BLACK  = 0x6000000000000000ULL;

    /* ---------------------------------------------- 
    // - Files and Ranks
    // ------------------------------------------- */

    constexpr uint64_t FILES[] = 
    {
        0x0101010101010101ULL, // A 
        0x0202020202020202ULL, // B 
        0x0404040404040404ULL, // C
        0x0808080808080808ULL, // D 
        0x1010101010101010ULL, // E
        0x2020202020202020ULL, // F 
        0x4040404040404040ULL, // G
        0x8080808080808080ULL  // H
    };

    constexpr uint64_t RANKS[] = 
    {
        0x00000000000000ffULL, // 1
        0x000000000000ff00ULL, // 2
        0x0000000000ff0000ULL, // 3
        0x00000000ff000000ULL, // 4 
        0x000000ff00000000ULL, // 5 
        0x0000ff0000000000ULL, // 6
        0x00ff000000000000ULL, // 7
        0xff00000000000000ULL  // 8
    };

    /* ---------------------------------------------- 
    // - Distances
    // ------------------------------------------- */

    constexpr uint8_t CENTER_DISTANCE[] = 
    {
        6, 5, 4, 3, 3, 4, 5, 6,
        5, 4, 3, 2, 2, 3, 4, 5,
        4, 3, 2, 1, 1, 2, 3, 4,
        3, 2, 1, 0, 0, 1, 2, 3,
        3, 2, 1, 0, 0, 1, 2, 3,
        4, 3, 2, 1, 1, 2, 3, 4,
        5, 4, 3, 2, 2, 3, 4, 5,
        6, 5, 4, 3, 3, 4, 5, 6
    };

    constexpr uint8_t ComputeDistance(Square square_a, Square square_b)
    {
        return (uint8_t)std::max(abs(square_b.Rank() - square_a.Rank()), abs(square_b.File() - square_a.File()));
    }

    constexpr std::array<std::array<uint8_t,64>,64> C_GetDistances()
    {
        std::array<std::array<uint8_t,64>,64> arr = { };
        for (uint8_t sq_a = 0; sq_a < 64; sq_a++)
        {   
            for (uint8_t sq_b = 0; sq_b < 64; sq_b++)
            {
                arr[sq_a][sq_b] = ComputeDistance(sq_a, sq_b);  
            }
        }
        return arr;
    };

    constexpr std::array<std::array<uint8_t,64>,64> DISTANCE = C_GetDistances();

    /* ---------------------------------------------- 
    // - Castle
    // ------------------------------------------- */

    constexpr std::array<std::array<Castle,64>,2> C_GetRookCastleRights()
    {
        std::array<std::array<Castle,64>,2> arr = { };
        for (char sq = 0; sq < 64; sq++)
        {
            arr[Color::Black][sq] = Castle::None;
            arr[Color::White][sq] = Castle::None;
        }

        arr[Color::Black][Square::a8] = Castle::Black_Queen;
        arr[Color::Black][Square::h8] = Castle::Black_King;
        arr[Color::White][Square::a1] = Castle::White_Queen;
        arr[Color::White][Square::h1] = Castle::White_King;
        
        return arr;
    }
    
    constexpr std::array<std::array<Castle,64>,2> ROOK_CASTLE_RIGHTS = C_GetRookCastleRights();
    
    /* ---------------------------------------------- 
    // - Directions
    // ------------------------------------------- */

    inline Bitboard D_East(const Bitboard _origin)
    {
        return _origin << 1;
    }

    inline Bitboard D_West(const Bitboard _origin)
    {
        return _origin >> 1;
    }

    inline Bitboard D_NorthWest(const Bitboard _origin)
    {
        return _origin << 7;
    }

    inline Bitboard D_SouthWest(const Bitboard _origin)
    {
        return _origin >> 9;
    }

    inline Bitboard D_North(const Bitboard _origin)
    {
        return _origin << 8;
    }

    inline Bitboard D_South(const Bitboard _origin)
    {
        return _origin >> 8;
    }

    inline Bitboard D_NortEast(const Bitboard _origin)
    {
        return _origin << 9;
    }

    inline Bitboard D_SouthEast(const Bitboard _origin)
    {
        return _origin >> 7;
    }
}