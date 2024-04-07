#pragma once
#include <cstdint>

constexpr std::string_view ENGINE_ANCII_ART = 
"  __    ___    _   ___   ___  __ __    \n" 
" / _|  | o \\  | | / __) | o | \\ V /  \n" 
"| |_   |   /  | | \\__ \\ |  _/  \\ /  \n"  
" \\__|  |_|_\\  |_| (___/ |_|    |_|   \n";

constexpr std::string_view ENGINE_VERSION = "v0.3";
constexpr std::string_view HOMEPAGE = "https://github.com/pedro15/Crispy";

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
    "None",
    "None",
    "Pawn", 
    "Knight",
    "Bishop",
    "Rook",
    "Queen",
    "King"
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

    square_enum val = square_enum::None;

    constexpr Square() = default;
    constexpr inline Square(square_enum square_value)
    {
        val = square_value;
    }
    constexpr inline explicit Square(uint8_t square_value)
    {
        val = static_cast<square_enum>(square_value);
    }
    constexpr inline explicit Square(uint8_t file, uint8_t rank)
    {
        val = static_cast<square_enum>(8 * rank + file);
    }

    constexpr inline explicit operator uint8_t() const
    {
        return static_cast<uint8_t>(val);
    }

    constexpr inline uint8_t File()
    {
        return val & 7;
    }
    constexpr inline uint8_t Rank()
    {
        return val >> 3;
    }

    inline std::string_view Str() const
    {
        return str_square[val];
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
        None   = 0,
        Pawn   = 2,
        Knight = 3,
        Bishop = 4,
        Rook   = 5,
        Queen  = 6,
        King   = 7
    };
    piece_enum val = piece_enum::None;
    
    constexpr Piece() = default;
    constexpr inline Piece(piece_enum piece_value)
    {
        val = piece_value;
    }
    constexpr inline Piece(uint8_t piece_value)
    {
        val = static_cast<piece_enum>(piece_value);
    }
    constexpr inline explicit operator uint8_t() const 
    {
        return static_cast<uint8_t>(val);
    }

    inline std::string_view Str() const
    {
        return str_piece[val];
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
    color_enum val = color_enum::Black;
    
    constexpr Color() = default;
    constexpr inline Color(color_enum color_value)
    {
        val = color_value;
    }
    constexpr inline Color(uint8_t color_value)
    {
        val = static_cast<color_enum>(color_value);
    }
    constexpr inline explicit operator uint8_t() const 
    {
        return static_cast<uint8_t>(val);
    }
    constexpr inline Color Invert()
    {
        return static_cast<color_enum>(val ^ 1);
    }
    inline std::string_view Str() const
    {
        return str_color[val];
    }
};

inline std::ostream& operator<<(std::ostream& os, const Color& color)
{
    os << color.Str();
    return os;
}