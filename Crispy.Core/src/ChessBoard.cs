using System.Runtime.CompilerServices;
using System.Collections.Generic;

namespace Crispy.Core 
{
    public sealed class ChessBoard 
    {
        // Board Data
        public ulong[] bitboards;
        public byte sideToMove;
        public byte enPassant;
        public byte halfMoves;
        public byte castleRights;
        public ulong key;
        public uint  keyPawns;
        // State Data
        private ChessPosition[] history;
        private byte[] captures;
        private short history_index = -1;
        private short captures_index = -1;

        public ChessBoard()
        {
            bitboards = new ulong[8];
            history = new ChessPosition[ChessPosition.MAX_PLY];
            captures = new byte[ChessPosition.MAX_PLY];
        }

        public ChessBoard(ChessPosition _position) : this()
        {   
            bitboards[Piece.PAWN]   = _position.bitboards[Piece.PAWN];
            bitboards[Piece.KNIGHT] = _position.bitboards[Piece.KNIGHT];
            bitboards[Piece.BISHOP] = _position.bitboards[Piece.BISHOP];
            bitboards[Piece.ROOK]   = _position.bitboards[Piece.ROOK];
            bitboards[Piece.QUEEN]  = _position.bitboards[Piece.QUEEN];
            bitboards[Piece.KING]   = _position.bitboards[Piece.KING];

            sideToMove = _position.sideToMove;
            enPassant = _position.enPassant;
            halfMoves = _position.halfMoves;
            castleRights = _position.castleRights;
            key = _position.key;
            keyPawns = _position.key_pawns;
        }

        private void CopyBoardState()
        {
            history_index++;
            ChessPosition pos = history[history_index];

            pos.bitboards[Piece.WHITE] = bitboards[Piece.WHITE];
            pos.bitboards[Piece.BLACK] = bitboards[Piece.BLACK];
            pos.bitboards[Piece.PAWN] = bitboards[Piece.PAWN];
            pos.bitboards[Piece.KNIGHT] = bitboards[Piece.KNIGHT];
            pos.bitboards[Piece.BISHOP] = bitboards[Piece.BISHOP];
            pos.bitboards[Piece.ROOK] = bitboards[Piece.ROOK];
            pos.bitboards[Piece.QUEEN] = bitboards[Piece.QUEEN];
            pos.bitboards[Piece.KING] = bitboards[Piece.KING];
            pos.sideToMove = sideToMove;
            pos.enPassant = enPassant;
            pos.halfMoves = halfMoves;
            pos.castleRights = castleRights;
            pos.key = key;
            pos.key_pawns = keyPawns;

            history[history_index] = pos;
        }

        private void RestoreBoardState()
        {   
            ChessPosition pos = history[history_index];
            bitboards[Piece.WHITE] = pos.bitboards[Piece.WHITE];
            bitboards[Piece.BLACK] = pos.bitboards[Piece.BLACK];
            bitboards[Piece.PAWN] = pos.bitboards[Piece.PAWN];
            bitboards[Piece.KNIGHT] = pos.bitboards[Piece.KNIGHT];
            bitboards[Piece.BISHOP] = pos.bitboards[Piece.BISHOP];
            bitboards[Piece.ROOK] = pos.bitboards[Piece.ROOK];
            bitboards[Piece.QUEEN] = pos.bitboards[Piece.QUEEN];
            bitboards[Piece.KING] = pos.bitboards[Piece.KING];
            enPassant = pos.enPassant;
            halfMoves = pos.halfMoves;
            key = pos.key;
            keyPawns = pos.key_pawns;
            sideToMove = pos.sideToMove;
            history_index--;
        }

        public void MakeMove()
        {
            
        }

        public void UndoLastMove()
        {
            
        }
    }
}