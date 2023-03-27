namespace Crispy.Core
{
    public struct BoardPositionData 
    {
        public ulong[] bitboards;
        public CastlingRights castlingRights;
        public Square ep_square;
        public Piece sideToMove; // Only returns either 'White' or 'Black'
        public ulong hash;
        public uint pawn_hash;
        
        public BoardPositionData Copy()
        {
            ulong[] cpy_bitboards = new ulong[bitboards.Length];
            System.Array.Copy(bitboards,cpy_bitboards, cpy_bitboards.Length);
            
            CastlingRights cpy_castling = castlingRights;
            Square cpy_ep_square = ep_square;
            Piece cpy_sideToMove = sideToMove;
            ulong cpy_hash = hash;
            uint cpy_pawn_hash = pawn_hash;

            return new BoardPositionData()
            {
                bitboards = cpy_bitboards,
                castlingRights = cpy_castling,
                ep_square = cpy_ep_square,
                sideToMove = cpy_sideToMove,
                hash = cpy_hash,
                pawn_hash = cpy_pawn_hash
            };
        }
    } 
}