namespace Crispy.Core
{
    public struct ChessPosition 
    {
        public const byte MAX_PLY = 255;
        public ulong[] bitboards;
        public byte sideToMove;
        public byte enPassant;
        public byte halfMoves;
        public byte castleRights;
        // Zorbist keys
        public ulong key;
        public uint  key_pawns;
    } 
}