namespace Crispy.Core
{
    public static class CastlingRights
    {
        public const byte WHITE_KING =  1;
        public const byte WHITE_QUEEN = 2;
        public const byte BLACK_KING =  4;
        public const byte BLACK_QUEEN = 8;
        public const byte ALL = WHITE_KING | WHITE_QUEEN | BLACK_KING | BLACK_QUEEN;
    }
}