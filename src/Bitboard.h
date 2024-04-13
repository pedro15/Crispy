#pragma once
#include <string>
#include <cstdint>
#include "Types.h"

struct Bitboard
{
    private:
        uint64_t m_value;
          
    public:
        constexpr Bitboard() = default;
        constexpr inline Bitboard(uint64_t bb_value)
        {
            m_value = bb_value;
        }

        // Public API

        inline Square PopSquare()
        {
            Square sq = LSB();
            m_value &= m_value -1;
            return sq;
        }

        inline uint8_t Count() const 
        {
            return std::popcount(m_value);
        }

        inline Square LSB() const 
        {
            return std::countr_zero(m_value);
        }

        inline Square MSB() const 
        {
            return std::countl_zero(m_value);
        }

        // Conversions

        constexpr inline operator uint64_t() const 
        {
            return m_value;
        }

        // Operators

        constexpr inline bool operator ==(const Bitboard& ) const = default;

        constexpr inline Bitboard operator ~() const 
        {
            return Bitboard(~m_value);
        }

        constexpr inline Bitboard operator |(const Bitboard& bb) const 
        {
            return Bitboard(m_value | bb);
        }

        constexpr inline void operator |=(const Bitboard& bb) 
        {
            m_value |= bb;
        }

        constexpr inline Bitboard operator &(const Bitboard& bb)
        {
            m_value &= bb;
        }

        constexpr inline Bitboard operator -(const Bitboard& bb)
        {
            return m_value & ~bb;
        }

        constexpr inline void operator -=(const Bitboard& bb)
        {
            m_value &= ~bb;
        }

        constexpr inline Bitboard operator +(const Square& sq)
        {
            return m_value | Bitboard(sq);
        }

        constexpr inline void operator +=(const Square& sq)
        {
            m_value |= Bitboard(sq);
        }

        constexpr inline Bitboard operator ^(const Bitboard& bb)
        {
            return m_value ^ bb;
        }

        constexpr inline void operator ^= (const Bitboard& bb)
        {
            m_value ^= bb;
        }

        constexpr inline bool operator <(const Bitboard& bb)
        {
            return m_value < bb;
        }

        constexpr inline bool operator <=(const Bitboard& bb)
        {
            return m_value <= bb;
        }

        // ... to be continued.
};