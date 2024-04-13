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

        // API

        inline Square PopSquare()
        {
            Square sq = LSB();
            m_value &= m_value -1;
            return sq;
        }

        // Add the specified square to the bitboard
        constexpr inline void AddSq(Square sq)
        {
            m_value |= 1ULL << sq;
        }

        // remove the specified square from the bitboard
        constexpr inline void RemoveSq(Square sq)
        {
            m_value &= ~(1ULL << sq);
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

        inline std::string Str()
        {
            std::stringstream stream;
            stream << "[bitboard] " << m_value;
            return stream.str();
        }

        // Conversions

        constexpr inline operator uint64_t() const 
        {
            return m_value;
        }

        // Operators

        // default equal operator
        constexpr inline bool operator ==(const Bitboard& ) const = default;

        // partial mask contains
        constexpr inline bool operator <=(const Bitboard& bb)
        {
            return (m_value & bb.m_value) == bb.m_value;  
        }

        // complete mask contains
        constexpr inline bool operator >=(const Bitboard& bb)
        {
            return (m_value & bb.m_value) == m_value;
        }

        // negation
        constexpr inline Bitboard operator ~() const 
        {
            return Bitboard(~m_value);
        }

        // Addition bb (bitboard)
        constexpr inline Bitboard operator |(const Bitboard& bb) const 
        {
            return Bitboard(m_value | bb);
        }

        // Addition bb (loacl)
        constexpr inline void operator |=(const Bitboard& bb) 
        {
            m_value |= bb;
        }

        // negation (bitboard)
        constexpr inline Bitboard operator -(const Bitboard& bb)
        {
            return m_value & ~bb;
        }

        // negation (local)
        constexpr inline void operator -=(const Bitboard& bb)
        {
            m_value &= ~bb;
        }

        // and (local)
        constexpr inline void operator &=(const Bitboard& bb)
        {
            m_value &= bb;
        }

        // and (bitboard)
        constexpr inline Bitboard operator &(const Bitboard& bb)
        {
            return m_value & bb;
        }

        // xor (bitboard)
        constexpr inline Bitboard operator ^(const Bitboard& bb)
        {
            return m_value ^ bb;
        }

        // xor (local)
        constexpr inline void operator ^= (const Bitboard& bb)
        {
            m_value ^= bb;
        }

        // used to check if an square exists
        constexpr inline bool operator[](const Square& sq) const
        {
            return 1 & (m_value >> sq); 
        }

        // binary operations

        constexpr inline Bitboard operator >>(const Bitboard& by) const 
        {
            return m_value >> by;
        }

        constexpr inline void operator >>=(const Bitboard& by)
        {
            m_value >>= by;
        }

        constexpr inline Bitboard operator <<(const Bitboard& by) const 
        {
            return m_value << by;
        }

        constexpr inline void operator <<=(const Bitboard& by)
        {
            m_value <<= by;
        }
};