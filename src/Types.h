#pragma once
#include <cstdint>

constexpr std::string_view ENGINE_VERSION = "v-0.4";
constexpr std::string_view HOMEPAGE = "https://github.com/pedro15/Crispy";
constexpr std::string_view ENGINE_ANCII_ART = 
"  __    ___    _   ___   ___  __ __    \n" 
" / _|  | o \\  | | / __) | o | \\ V /  \n" 
"| |_   |   /  | | \\__ \\ |  _/  \\ /  \n"  
" \\__|  |_|_\\  |_| (___/ |_|    |_|   \n";

// string representation -----------------------------

constexpr std::string_view str_square[65] =
{
    "a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1",
    "a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2",
    "a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3",
    "a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4",
    "a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5",
    "a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6",
    "a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7",
    "a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8", "None"
};

constexpr std::string_view str_piece[8] = 
{
    "Pawn", 
    "Knight",
    "Bishop",
    "Rook",
    "Queen",
    "King",
    "None"
};

constexpr std::string_view str_color[2] =
{
    "Black", "White"
};

// Type definitions -------------------------------------

// Square definition
struct Square
{
    enum square_enum : uint8_t
    {
        a1, b1, c1, d1, e1, f1, g1, h1,
        a2, b2, c2, d2, e2, f2, g2, h2,
        a3, b3, c3, d3, e3, f3, g3, h3,
        a4, b4, c4, d4, e4, f4, g4, h4,
        a5, b5, c5, d5, e5, f5, g5, h5,
        a6, b6, c6, d6, e6, f6, g6, h6,
        a7, b7, c7, d7, e7, f7, g7, h7,
        a8, b8, c8, d8, e8, f8, g8, h8, None
    };

private:
    square_enum m_val = square_enum::None;

public:
    constexpr Square() = default;
    constexpr inline Square(square_enum square_value)
    {
        m_val = square_value;
    }
    constexpr inline Square(uint8_t square_value)
    {
        m_val = static_cast<square_enum>(square_value);
    }
    constexpr inline Square(uint8_t file, uint8_t rank)
    {
        m_val = static_cast<square_enum>(8 * rank + file);
    }

    constexpr inline uint8_t File()
    {
        return m_val & 7;
    }
    constexpr inline uint8_t Rank()
    {
        return m_val >> 3;
    }

    inline std::string_view Str() const
    {
        return str_square[m_val];
    }

    constexpr inline operator uint8_t() const
    {
        return static_cast<uint8_t>(m_val);
    }
};

inline std::ostream& operator<<(std::ostream& os, const Square& sq)
{
    os << sq.Str();
    return os;
}

// Piece definition
struct Piece
{
    enum piece_enum : uint8_t
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
    piece_enum m_val = Piece::None;

public:
    constexpr Piece() = default;
    constexpr inline Piece(piece_enum piece_value)
    {
        m_val = piece_value;
    }
    constexpr inline Piece(uint8_t piece_value)
    {
        m_val = static_cast<piece_enum>(piece_value);
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

inline std::ostream& operator<<(std::ostream& os, const Piece& piece)
{
    os << piece.Str();
    return os;
}

// Color definition
struct Color
{
    enum color_enum : uint8_t
    {
        Black = 0,
        White = 1
    };

private:
    color_enum m_val = color_enum::Black;

public:
    constexpr Color() = default;
    constexpr inline Color(color_enum color_value)
    {
        m_val = color_value;
    }
    constexpr inline Color(uint8_t color_value)
    {
        m_val = static_cast<color_enum>(color_value);
    }
    inline std::string_view Str() const
    {
        return str_color[m_val];
    }
    constexpr inline Color Invert()
    {
        return static_cast<color_enum>(m_val ^ 1);
    }

    constexpr inline operator uint8_t() const
    {
        return static_cast<uint8_t>(m_val);
    }
};

inline std::ostream& operator<<(std::ostream& os, const Color& color)
{
    os << color.Str();
    return os;
}

// Castle definition
struct Castle
{
    enum castle_enum : uint8_t
    {
        None = 0,
        White_King = 1,
        White_Queen = 2,
        Black_King = 4,
        Black_Queen = 8
    };

private:
    castle_enum m_val = castle_enum::None;

public:
    Castle() = default;
    constexpr inline Castle(castle_enum castle_value)
    {
        m_val = castle_value;
    }

    constexpr inline Castle(uint8_t castle_value)
    {
        m_val = static_cast<castle_enum>(castle_value);
    }

    constexpr inline operator uint8_t() const
    {
        return static_cast<uint8_t>(m_val);
    }

    constexpr inline bool operator==(const Castle &) const = default;

    constexpr inline Castle operator~() const
    {
        return Castle(~m_val);
    }

    constexpr inline Castle operator|(Castle &castle_value) const
    {
        return static_cast<castle_enum>(static_cast<uint8_t>(m_val) | static_cast<uint8_t>(castle_value));
    }

    constexpr inline void operator|=(Castle &castle_value)
    {
        m_val = static_cast<castle_enum>(static_cast<uint8_t>(m_val) | static_cast<uint8_t>(castle_value));
    }

    constexpr inline Castle operator&(Castle &castle_value) const
    {
        return static_cast<castle_enum>(static_cast<uint8_t>(m_val) & static_cast<uint8_t>(castle_value));
    }

    constexpr inline void operator&=(Castle &castle_value)
    {
        m_val = static_cast<castle_enum>(static_cast<uint8_t>(m_val) & static_cast<uint8_t>(castle_value));
    }

    constexpr inline Castle operator^(Castle &castle_value) const
    {
        return static_cast<castle_enum>(static_cast<uint8_t>(m_val) ^ static_cast<uint8_t>(castle_value));
    }

    constexpr inline void operator^=(Castle &castle_value)
    {
        m_val = static_cast<castle_enum>(static_cast<uint8_t>(m_val) ^ static_cast<uint8_t>(castle_value));
    }
};