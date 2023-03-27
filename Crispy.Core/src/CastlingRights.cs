namespace Crispy.Core
{
    [System.Flags]
    public enum CastlingRights : int
    {
        None = 0,
        WhiteKing =  1,
        WhiteQueen = 2,
        BlackKing =  4,
        BlackQueen = 8
    }
}