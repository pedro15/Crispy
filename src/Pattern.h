#include "Types.h"
#include "BoardUtils.h"

namespace Pattern
{
    static Bitboard PatternSubset(int _index, int _count, Bitboard _mask)
    {
        int i,sq;
        Bitboard result = 0;
        for (i = 0; i < _count; i++)
        {
            sq = _mask.PopSquare();
            if (_index & (1 << i)) 
            {
                result.SetBit(sq);
            }
        }
        return result;
    }

    static Bitboard PatternFileRankMask(int _file, int _rank)
    {
        Bitboard result = 0;
        for (int r = 0; r < 8; r++)
        {
            for (int f = 0; f < 8; f++)
            {
                Square sq = Square(f,r);
                if (_file >= 0 && f == _file)
                {
                    result.SetBit(sq);
                }else if(_rank >= 0 && r == _rank)
                {
                    result.SetBit(sq);
                }
            }
        }
        return result;
    }

    static Bitboard PatternPawnAttacks(Square _sq, Color _color)
    {
        Bitboard result = 0;
        Bitboard ph = Bitboard(_sq);

        switch (_color)
        {
            case Color::White:
                result |= ((ph << 7) & BoardUtils::MASK_FILE_H);
                result |= ((ph << 9) & BoardUtils::MASK_FILE_A);
            break;

            case Color::Black:
                result |= ((ph >> 7) & BoardUtils::MASK_FILE_A);
                result |= ((ph >> 9) & BoardUtils::MASK_FILE_H);
            break;
        }

        return result;
    }

    static Bitboard PatternKnight(Square _sq)
    {
        Bitboard result = 0;
        Bitboard ph = Bitboard(_sq);

        // bottom
        result |= ((ph << 17) & BoardUtils::MASK_FILE_A);
        result |= ((ph << 15) & BoardUtils::MASK_FILE_H);
        result |= ((ph << 10) & BoardUtils::MASK_FILE_AB);
        result |= ((ph << 6)  & BoardUtils::MASK_FILE_GH);
        // top
        result |= ((ph >> 17) & BoardUtils::MASK_FILE_H);
        result |= ((ph >> 15) & BoardUtils::MASK_FILE_A);
        result |= ((ph >> 10) & BoardUtils::MASK_FILE_GH);
        result |= ((ph >> 6)  & BoardUtils::MASK_FILE_AB);

        return result;
    }
    
    static Bitboard PatternKing(Square _sq)
    {
        Bitboard result = 0;
        Bitboard ph = Bitboard(_sq);

        result |= ((ph << 7) & BoardUtils::MASK_FILE_H);
        result |= (ph << 8);
        result |= ((ph << 9) & BoardUtils::MASK_FILE_A);
        result |= ((ph << 1) & BoardUtils::MASK_FILE_A);

        result |= ((ph >> 7) & BoardUtils::MASK_FILE_A);
        result |= (ph >> 8);
        result |= ((ph >> 9) & BoardUtils::MASK_FILE_H);
        result |= ((ph >> 1) & BoardUtils::MASK_FILE_H);

        return result;
    }

    static Bitboard PatternSliding(Piece _pc, Square _sq)
    {
        Bitboard result = 0;
        int rk = _sq / 8, fl = _sq % 8, r, f;

        switch(_pc)
        {
            case Piece::Bishop:
                for (r=rk+1, f=fl+1; r <= 6 && f <= 6; r++, f++)  result |= (1ULL << (f + r * 8));
                for (r=rk+1, f=fl-1; r <= 6 && f >= 1; r++, f++)  result |= (1ULL << (f + r * 8));
                for (r=rk-1, f=fl+1; r >= 1 && f <= 6; r--, f++)  result |= (1ULL << (f + r * 8));
                for (r=rk-1, f=fl-1; r >= 1 && f >= 1; r--, f--)  result |= (1ULL << (f + r * 8));
            break;

            case Piece::Rook:
                for (r = rk+1; r <= 6; r++) result |= (1ULL << (fl + r * 8));
                for (r = rk-1; r >= 1; r--) result |= (1ULL << (fl + r * 8));
                for (f = fl+1; f <= 6; f++) result |= (1ULL << (f + rk * 8));
                for (f = fl-1; f >= 1; f--) result |= (1ULL << (f + rk * 8));
            break;
        }

        return result;
    }

    static Bitboard PatternSlidingRelevantOccupancy(Piece _pc, Square _sq, Bitboard _mask)
    {
        Bitboard result = 0;
        Square square;
        char rank_origin = _sq.Rank();
        char file_origin = _sq.File();
        int rank,file;
        switch(_pc)
        {
            case Piece::Bishop:
                // bottom-left
                for (rank = rank_origin + 1, file = file_origin -1; rank < 8 && file >= 0; rank++, file--)
                {
                    square = Square(file, rank);
                    result.SetBit(square);
                    if (_mask.Contains(square)) break;
                }
                // bottom-right
                for (rank = rank_origin + 1, file = file_origin + 1; rank < 8 && file < 8; rank++, file++)
                {
                    square = Square(file,rank);
                    result.SetBit(square);
                    if (_mask.Contains(square)) break;
                }
                // top-left
                for (rank = rank_origin -1, file = file_origin -1; rank >= 0 && file >= 0; rank--, file--)
                {
                    square = Square(file,rank);
                    result.SetBit(square);
                    if (_mask.Contains(square)) break;
                }
                // top-right
                for (rank = rank_origin -1, file = file_origin + 1; rank >= 0 && file < 8; rank--, file++)
                {
                    square = Square(file,rank);
                    result.SetBit(square);
                    if (_mask.Contains(square)) break;
                }
            break;

            case Piece::Rook:
                // top
                for (rank = rank_origin +1; rank < 8; rank++)
                {
                    square = Square(file_origin,rank);
                    result.SetBit(square);
                    if (_mask.Contains(square)) break;
                }
                // bottom 
                for (rank = rank_origin -1; rank >= 0; rank--)
                {
                    square = Square(file_origin,rank);
                    result.SetBit(square);
                    if (_mask.Contains(square)) break;
                }
                // left 
                for (file = file_origin -1; file >= 0; file--)
                {
                    square = Square(file,rank_origin);
                    result.SetBit(square);
                    if (_mask.Contains(square)) break;
                }
                // right
                for (file = file_origin + 1; file < 8; file++)
                {
                    square = Square(file,rank_origin);
                    result.SetBit(square);
                    if (_mask.Contains(square)) break;
                }
            break;
        }
        return result;
    }
}