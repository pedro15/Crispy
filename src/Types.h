#pragma once
#include <cstdint>
#include <sstream>

// ----------------------------------------------
// - - - - STRING REPRESENTATION
// ----------------------------------------------

constexpr std::string_view str_square[65] =
{
    "a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1",
    "a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2",
    "a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3",
    "a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4",
    "a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5",
    "a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6",
    "a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7",
    "a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8", "none"
};

constexpr std::string_view str_piece[6] = 
{
    "pawn","knight","bishop","rook","queen","king"
};

constexpr std::string_view str_color[2] =
{
    "black","white"
};

constexpr std::string_view str_files[8] = 
{
    "a", "b", "c" , "d", "e", "f", "g", "h"
};

// ----------------------------------------------
// - - - - TYPES
// ----------------------------------------------


/* ---------------------------------------------- 
// - Square
// ------------------------------------------- */


struct Square
{
    enum square_type : uint8_t
    {
        a1, b1, c1, d1, e1, f1, g1, h1,
        a2, b2, c2, d2, e2, f2, g2, h2,
        a3, b3, c3, d3, e3, f3, g3, h3,
        a4, b4, c4, d4, e4, f4, g4, h4,
        a5, b5, c5, d5, e5, f5, g5, h5,
        a6, b6, c6, d6, e6, f6, g6, h6,
        a7, b7, c7, d7, e7, f7, g7, h7,
        a8, b8, c8, d8, e8, f8, g8, h8, none
    };

    static constexpr inline bool Valid(std::string _square_notation)
    {
        if (_square_notation.length() != 2 || !isdigit(_square_notation[1])) 
            return false;
        
        bool file_valid = false;
        bool rank_valid = false;

        switch(_square_notation[0])
        {
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            case 'g':
            case 'h':
                file_valid = true;
            break;
        }
        int rank = (_square_notation[1] - '0') - 1;
        if (rank >= 0 && rank < 8)
            rank_valid = true;
        
        return file_valid && rank_valid;
    }

private:
    square_type m_value = square_type::none;

public:
    constexpr Square() = default;
    constexpr inline Square(square_type _square_value)
    {
        m_value = _square_value;
    }
    constexpr inline Square(uint8_t _square_value)
    {
        m_value = static_cast<square_type>(_square_value);
    }
    constexpr inline Square(uint8_t _file, uint8_t _rank)
    {
        m_value = static_cast<square_type>(8 * _rank + _file);
    }

    constexpr inline Square(std::string _square_str)
    {
        if (!Valid(_square_str))
        {
            return;
        }

        int rank = (_square_str[1] - '0') - 1;
        int file = 0;

        if (_square_str[0] == 'a')
            file = 0;
        else if  (_square_str[0] == 'b')
            file = 1;
        else if (_square_str[0] ==  'c')
            file = 2;
        else if (_square_str[0] ==  'd')
            file = 3;
        else if (_square_str[0] ==  'e')
            file = 4;
        else if (_square_str[0] ==  'f')
            file = 5;
        else if (_square_str[0] ==  'g')
            file = 6;
        else if (_square_str[0] ==  'h')
            file = 7;
        
        m_value = static_cast<square_type>(8 * rank + file);
    }

    constexpr inline uint8_t File() const
    {
        return m_value & 7;
    }
    constexpr inline uint8_t Rank() const
    {
        return m_value >> 3;
    }

    inline std::string_view Str() const
    {
        return str_square[m_value];
    }
    
    inline Square Invert() const
    {
        return Square(m_value ^ 56);
    }

    constexpr inline operator uint8_t() const
    {
        return static_cast<uint8_t>(m_value);
    }
};

inline std::ostream& operator<<(std::ostream& _os, const Square& _sq)
{
    _os << _sq.Str();
    return _os;
}

/* ---------------------------------------------- 
// - Piece
// ------------------------------------------- */

struct Piece
{
    enum piece_type : uint8_t
    {
        Pawn    = 0,
        Knight  = 1,
        Bishop  = 2,
        Rook    = 3,
        Queen   = 4,
        King    = 5,
        None    = 6,
    };

private:
    piece_type m_val = Piece::None;

public:
    constexpr Piece() = default;
    constexpr inline Piece(piece_type _piece_value)
    {
        m_val = _piece_value;
    }
    constexpr inline Piece(uint8_t _piece_value)
    {
        m_val = static_cast<piece_type>(_piece_value);
    }
    inline std::string_view Str() const
    {
        return str_piece[m_val];
    }

    constexpr inline operator uint8_t() const
    {
        return static_cast<uint8_t>(m_val);
    }
};

inline std::ostream& operator<<(std::ostream& _os, const Piece& _piece)
{
    _os << _piece.Str();
    return _os;
}

/* ---------------------------------------------- 
// - Color
// ------------------------------------------- */

struct Color
{
    enum color_type : uint8_t
    {
        Black = 0,
        White = 1
    };

private:
    color_type m_value = color_type::Black;

public:
    constexpr Color() = default;
    constexpr inline Color(color_type _color_value)
    {
        m_value = _color_value;
    }
    constexpr inline Color(uint8_t _color_value)
    {
        m_value = static_cast<color_type>(_color_value);
    }
    inline std::string_view Str() const
    {
        return str_color[m_value];
    }
    constexpr inline Color Invert()
    {
        return static_cast<color_type>(m_value ^ 1);
    }

    constexpr inline operator uint8_t() const
    {
        return static_cast<uint8_t>(m_value);
    }
};

inline std::ostream& operator<<(std::ostream& _os, const Color& _color)
{
    _os << _color.Str();
    return _os;
}

/* ---------------------------------------------- 
// - Castle
// ------------------------------------------- */

struct Castle
{
    enum castle_type : uint8_t
    {
        None = 0,
        White_King = 1,
        White_Queen = 2,
        Black_King = 4,
        Black_Queen = 8
    };

private:
    castle_type m_value = castle_type::None;

public:
    Castle() = default;
    constexpr inline Castle(castle_type _castle_value)
    {
        m_value = _castle_value;
    }

    constexpr inline Castle(uint8_t _castle_value)
    {
        m_value = static_cast<castle_type>(_castle_value);
    }

    inline std::string_view Str() const
    {
        std::stringstream ss;
        bool empty = true;
        
        if ((m_value & castle_type::White_King) != castle_type::None)
        {
            ss << "K";
            empty = false;
        }
        
        if ((m_value & castle_type::White_Queen) != castle_type::None)
        {
            ss << "Q";
            empty = false;
        }

        if ((m_value & castle_type::Black_King) != castle_type::None)
        {
            ss << "k";
            empty = false;
        }
        
        if ((m_value & castle_type::Black_Queen) != castle_type::None)
        {
            ss << "q";
            empty = false;
        }

        if (empty)
        {
            ss << "-";
        }

        return std::string_view(ss.str());
    }

    constexpr inline operator uint8_t() const
    {
        return static_cast<uint8_t>(m_value);
    }

    constexpr inline bool operator==(const Castle &) const = default;

    constexpr inline Castle operator~() const
    {
        return Castle(~m_value);
    }

    constexpr inline Castle operator|(const Castle &_castle_value) const
    {
        return static_cast<castle_type>(static_cast<uint8_t>(m_value) | static_cast<uint8_t>(_castle_value));
    }

    constexpr inline void operator|=(const Castle &_castle_value)
    {
        m_value = static_cast<castle_type>(static_cast<uint8_t>(m_value) | static_cast<uint8_t>(_castle_value));
    }

    constexpr inline Castle operator&(const Castle &_castle_value) const
    {
        return static_cast<castle_type>(static_cast<uint8_t>(m_value) & static_cast<uint8_t>(_castle_value));
    }

    constexpr inline void operator&=(const Castle &_castle_value)
    {
        m_value = static_cast<castle_type>(static_cast<uint8_t>(m_value) & static_cast<uint8_t>(_castle_value));
    }

    constexpr inline Castle operator^(const Castle &_castle_value) const
    {
        return static_cast<castle_type>(static_cast<uint8_t>(m_value) ^ static_cast<uint8_t>(_castle_value));
    }

    constexpr inline void operator^=(const Castle &_castle_value)
    {
        m_value = static_cast<castle_type>(static_cast<uint8_t>(m_value) ^ static_cast<uint8_t>(_castle_value));
    }
};

inline std::ostream& operator<<(std::ostream& _os, const Castle& _castle)
{
    _os << _castle.Str();
    return _os;
}

/* ---------------------------------------------- 
// - Bitboard
// ------------------------------------------- */

struct Bitboard
{
    private:
        uint64_t m_value;
          
    public:
        constexpr Bitboard() = default;
        constexpr inline Bitboard(uint64_t _bb_value)
        {
            m_value = _bb_value;
        }
        constexpr inline Bitboard(const Square _square)
        {
            m_value = 1ULL << _square;
        }
        
        // API
        inline void SetBit(Square _sq)
        {
            m_value |= (1ULL << _sq);
        }

        inline void ClearBit(Square _sq)
        {
            m_value &= ~(1ULL << _sq);
        }

        inline Square PopSquare()
        {
            Square sq = LSB();
            m_value &= m_value -1;
            return sq;
        }

        inline bool Contains(Square _sq) const
        {
            return (1 & (m_value >> (uint8_t)_sq)) != 0;
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
        
        std::string Str() const
        {
            std::stringstream stream;
            stream << m_value;
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
        constexpr inline bool operator <=(const Bitboard& _bb)
        {
            return (m_value & _bb.m_value) == _bb.m_value;  
        }

        // complete mask contains
        constexpr inline bool operator >=(const Bitboard& _bb)
        {
            return (m_value & _bb.m_value) == m_value;
        }

        // negation
        constexpr inline Bitboard operator ~() const 
        {
            return Bitboard(~m_value);
        }

        // Addition bb (bitboard)
        constexpr inline Bitboard operator |(const Bitboard& _bb) const 
        {
            return Bitboard(m_value | _bb);
        }

        // Addition _bb (loacl)
        constexpr inline void operator |=(const Bitboard& _bb) 
        {
            m_value |= _bb;
        }

        // and (local)
        constexpr inline void operator &=(const Bitboard& _bb)
        {
            m_value &= _bb;
        }

        // and (bitboard)
        constexpr inline Bitboard operator &(const Bitboard& _bb) const 
        {
            return m_value & _bb;
        }

        constexpr inline Bitboard operator &(const int& _by) const 
        {
            return m_value & _by;
        }

        // xor (bitboard)
        constexpr inline Bitboard operator ^(const Bitboard& _bb) const
        {
            return m_value ^ _bb;
        }

        // xor (local)
        constexpr inline void operator ^= (const Bitboard& _bb)
        {
            m_value ^= _bb;
        }

        // used to check if an square exists
        constexpr inline bool operator[](const Square& sq) const
        {
            return 1 & (m_value >> sq); 
        }
        
        // binary operations

        constexpr inline Bitboard operator >>(const Bitboard& _by) const 
        {
            return m_value >> _by;
        }

        constexpr inline Bitboard operator >>(const int& _by) const 
        {
            return m_value >> _by;
        }

        constexpr inline void operator >>=(const Bitboard& _by)
        {
            m_value >>= _by;
        }

        constexpr inline Bitboard operator <<(const Bitboard& _by) const 
        {
            return m_value << _by;
        }

        constexpr inline Bitboard operator <<(const int& _by) const 
        {
            return m_value << _by;
        }

        constexpr inline void operator <<=(const Bitboard& _by)
        {
            m_value <<= _by;
        }
};

inline std::ostream& operator<<(std::ostream& _os, const Bitboard& _bb)
{
    _os << _bb.Str();
    return _os;
}