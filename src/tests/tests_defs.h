#include <vector>
#include <string>
#include <iostream>

const std::vector<std::string> fen_suite = 
{
    "1B6/8/8/8/5pP1/8/7k/4K3 b - g3 0 1",
    "1k6/8/8/8/5pP1/8/7B/4K3 b - g3 0 1",
    "1r2k2r/8/8/8/8/8/8/R3K2R b KQk - 0 1",
    "1r2k2r/8/8/8/8/8/8/R3K2R w KQk - 0 1",
    "2K2r2/4P3/8/8/8/8/8/3k4 w - - 0 1",
    "2kr3r/p1ppqpb1/bn2Qnp1/3PN3/1p2P3/2N5/PPPBBPPP/R3K2R b KQ - 3 2",
    "2r1k2r/8/8/8/8/8/8/R3K2R b KQk - 0 1",
    "2r1k2r/8/8/8/8/8/8/R3K2R w KQk - 0 1",
    "2r5/3pk3/8/2P5/8/2K5/8/8 w - - 5 4",
    "3k4/3p4/8/K1P4r/8/8/8/8 b - - 0 1",
    "3k4/3pp3/8/8/8/8/3PP3/3K4 b - - 0 1",
    "3k4/3pp3/8/8/8/8/3PP3/3K4 w - - 0 1",
    "3k4/8/8/8/8/8/8/R3K3 w Q - 0 1",
    "4k2r/6K1/8/8/8/8/8/8 b k - 0 1",
    "4k2r/6K1/8/8/8/8/8/8 w k - 0 1",
    "4k2r/8/8/8/8/8/8/4K3 b k - 0 1",
    "4k2r/8/8/8/8/8/8/4K3 w k - 0 1",
    "4k3/1P6/8/8/8/8/K7/8 w - - 0 1",
    "4k3/4p3/4K3/8/8/8/8/8 b - - 0 1",
    "4k3/7K/8/5Pp1/8/8/8/1b6 w - g6 0 1",
    "4k3/7b/8/5Pp1/8/8/8/1K6 w - g6 0 1",
    "4k3/8/4q3/8/8/8/3b4/4K3 w - - 0 1",
    "4k3/8/4r3/8/8/8/3p4/4K3 w - - 0 1",
    "4k3/8/8/2PpP3/8/8/8/4K3 w - d6 0 1",
    "4k3/8/8/4pP2/3K4/8/8/8 w - e6 0 1",
    "4k3/8/8/8/1b2r3/8/3Q4/4K3 w - - 0 1",
    "4k3/8/8/8/1b2r3/8/3QP3/4K3 w - - 0 1",
    "4k3/8/8/8/1b5b/2Q5/5P2/4K3 w - - 0 1",
    "4k3/8/8/8/1b5b/2R5/5P2/4K3 w - - 0 1",
    "4k3/8/8/8/1b5b/8/3Q4/4K3 w - - 0 1",
    "4k3/8/8/8/1b5b/8/3R4/4K3 w - - 0 1",
    "4k3/8/8/8/2pPp3/8/8/4K3 b - d3 0 1",
    "4k3/8/8/8/8/8/8/4K2R b K - 0 1",
    "4k3/8/8/8/8/8/8/4K2R w K - 0 1",
    "4k3/8/8/8/8/8/8/R3K2R b KQ - 0 1",
    "4k3/8/8/8/8/8/8/R3K2R w KQ - 0 1",
    "4k3/8/8/8/8/8/8/R3K3 b Q - 0 1",
    "4k3/8/8/8/8/8/8/R3K3 w Q - 0 1",
    "4k3/8/K6q/3pP3/8/8/8/8 w - d6 0 1",
    "4k3/8/K6r/3pP3/8/8/8/8 w - d6 0 1",
    "4k3/K7/8/1pP5/8/8/8/6b1 w - b6 0 1",
    "4k3/b7/8/1pP5/8/8/8/6K1 w - b6 0 1",
    "5k2/8/8/8/8/8/8/4K2R w K - 0 1",
    "6B1/8/8/8/1Pp5/8/k7/4K3 b - b3 0 1",
    "6KQ/8/8/8/8/8/8/7k b - - 0 1",
    "6k1/8/8/8/1Pp5/8/B7/4K3 b - b3 0 1",
    "6kq/8/8/8/8/8/8/7K w - - 0 1",
    "6qk/8/8/8/8/8/8/7K b - - 0 1",
    "7K/7p/7k/8/8/8/8/8 b - - 0 1",
    "7K/7p/7k/8/8/8/8/8 w - - 0 1",
    "7k/3p4/8/8/3P4/8/8/K7 b - - 0 1",
    "7k/3p4/8/8/3P4/8/8/K7 w - - 0 1",
    "7k/8/1p6/8/8/P7/8/7K b - - 0 1",
    "7k/8/1p6/8/8/P7/8/7K w - - 0 1",
    "7k/8/8/1p6/P7/8/8/7K b - - 0 1",
    "7k/8/8/1p6/P7/8/8/7K w - - 0 1",
    "7k/8/8/3p4/8/8/3P4/K7 b - - 0 1",
    "7k/8/8/3p4/8/8/3P4/K7 w - - 0 1",
    "7k/8/8/p7/1P6/8/8/7K b - - 0 1",
    "7k/8/8/p7/1P6/8/8/7K w - - 0 1",
    "7k/8/p7/8/8/1P6/8/7K b - - 0 1",
    "7k/8/p7/8/8/1P6/8/7K w - - 0 1",
    "7k/RR6/8/8/8/8/rr6/7K b - - 0 1",
    "7k/RR6/8/8/8/8/rr6/7K w - - 0 1",
    "8/1k6/8/5N2/8/4n3/8/2K5 b - - 0 1",
    "8/1k6/8/5N2/8/4n3/8/2K5 w - - 0 1",
    "8/1n4N1/2k5/8/8/5K2/1N4n1/8 b - - 0 1",
    "8/1n4N1/2k5/8/8/5K2/1N4n1/8 w - - 0 1",
    "8/2k1p3/3pP3/3P2K1/8/8/8/8 b - - 0 1",
    "8/2k1p3/3pP3/3P2K1/8/8/8/8 w - - 0 1",
    "8/2p5/3p4/KP5r/1R3p1k/8/4P1P1/8 w - - 0 1",
    "8/3k4/3p4/8/3P4/3K4/8/8 b - - 0 1",
    "8/3k4/3p4/8/3P4/3K4/8/8 w - - 0 1",
    "8/8/1B6/7b/7k/8/2B1b3/7K b - - 0 1",
    "8/8/1B6/7b/7k/8/2B1b3/7K w - - 0 1",
    "8/8/1P2K3/8/2n5/1q6/8/5k2 b - - 0 1",
    "8/8/1k6/2b5/2pP4/8/5K2/8 b - d3 0 1",
    "8/8/2k5/5q2/5n2/8/5K2/8 b - - 0 1",
    "8/8/3K4/3Nn3/3nN3/4k3/8/8 b - - 0 1",
    "8/8/3k4/3p4/3P4/3K4/8/8 b - - 0 1",
    "8/8/3k4/3p4/3P4/3K4/8/8 w - - 0 1",
    "8/8/3k4/3p4/8/3P4/3K4/8 b - - 0 1",
    "8/8/3k4/3p4/8/3P4/3K4/8 w - - 0 1",
    "8/8/4k3/3Nn3/3nN3/4K3/8/8 w - - 0 1",
    "8/8/4k3/8/2p5/8/B2P2K1/8 w - - 0 1",
    "8/8/7k/7p/7P/7K/8/8 b - - 0 1",
    "8/8/7k/7p/7P/7K/8/8 w - - 0 1",
    "8/8/8/2k5/2pP4/8/B7/4K3 b - d3 0 3",
    "8/8/8/4k3/5Pp1/8/8/3K4 b - f3 0 1",
    "8/8/8/8/1k1PpN1R/8/8/4K3 b - d3 0 1",
    "8/8/8/8/1k1Ppn1R/8/8/4K3 b - d3 0 1",
    "8/8/8/8/8/4k3/4P3/4K3 w - - 0 1",
    "8/8/8/8/8/7K/7P/7k b - - 0 1",
    "8/8/8/8/8/7K/7P/7k w - - 0 1",
    "8/8/8/8/8/8/1k6/R3K3 b Q - 0 1",
    "8/8/8/8/8/8/1k6/R3K3 w Q - 0 1",
    "8/8/8/8/8/8/6k1/4K2R b K - 0 1",
    "8/8/8/8/8/8/6k1/4K2R w K - 0 1",
    "8/8/8/8/8/K7/P7/k7 b - - 0 1",
    "8/8/8/8/8/K7/P7/k7 w - - 0 1",
    "8/8/k7/p7/P7/K7/8/8 b - - 0 1",
    "8/8/k7/p7/P7/K7/8/8 w - - 0 1",
    "8/P1k5/K7/8/8/8/8/8 w - - 0 1",
    "8/PPPk4/8/8/8/8/4Kppp/8 b - - 0 1",
    "8/PPPk4/8/8/8/8/4Kppp/8 w - - 0 1",
    "8/Pk6/8/8/8/8/6Kp/8 b - - 0 1",
    "8/Pk6/8/8/8/8/6Kp/8 w - - 0 1",
    "8/k1P5/8/1K6/8/8/8/8 w - - 0 1",
    "B6b/8/8/8/2K5/4k3/8/b6B w - - 0 1",
    "B6b/8/8/8/2K5/5k2/8/b6B b - - 0 1",
    "K1k5/8/P7/8/8/8/8/8 w - - 0 1",
    "K7/8/2n5/1n6/8/8/8/k6N b - - 0 1",
    "K7/8/2n5/1n6/8/8/8/k6N w - - 0 1",
    "K7/8/8/3Q4/4q3/8/8/7k b - - 0 1",
    "K7/8/8/3Q4/4q3/8/8/7k w - - 0 1",
    "K7/b7/1b6/1b6/8/8/8/k6B b - - 0 1",
    "K7/b7/1b6/1b6/8/8/8/k6B w - - 0 1",
    "K7/p7/k7/8/8/8/8/8 b - - 0 1",
    "K7/p7/k7/8/8/8/8/8 w - - 0 1",
    "R6r/8/8/2K5/5k2/8/8/r6R b - - 0 1",
    "R6r/8/8/2K5/5k2/8/8/r6R w - - 0 1",
    "k7/6p1/8/8/8/8/7P/K7 b - - 0 1",
    "k7/6p1/8/8/8/8/7P/K7 w - - 0 1",
    "k7/7p/8/8/8/8/6P1/K7 b - - 0 1",
    "k7/7p/8/8/8/8/6P1/K7 w - - 0 1",
    "k7/8/2N5/1N6/8/8/8/K6n b - - 0 1",
    "k7/8/2N5/1N6/8/8/8/K6n w - - 0 1",
    "k7/8/3p4/8/3P4/8/8/7K b - - 0 1",
    "k7/8/3p4/8/3P4/8/8/7K w - - 0 1",
    "k7/8/3p4/8/8/4P3/8/7K b - - 0 1",
    "k7/8/3p4/8/8/4P3/8/7K w - - 0 1",
    "k7/8/6p1/8/8/7P/8/K7 b - - 0 1",
    "k7/8/6p1/8/8/7P/8/K7 w - - 0 1",
    "k7/8/7p/8/8/6P1/8/K7 b - - 0 1",
    "k7/8/7p/8/8/6P1/8/K7 w - - 0 1",
    "k7/8/8/3p4/4p3/8/8/7K b - - 0 1",
    "k7/8/8/3p4/4p3/8/8/7K w - - 0 1",
    "k7/8/8/6p1/7P/8/8/K7 b - - 0 1",
    "k7/8/8/6p1/7P/8/8/K7 w - - 0 1",
    "k7/8/8/7p/6P1/8/8/K7 b - - 0 1",
    "k7/8/8/7p/6P1/8/8/K7 w - - 0 1",
    "k7/B7/1B6/1B6/8/8/8/K6b b - - 0 1",
    "k7/B7/1B6/1B6/8/8/8/K6b w - - 0 1",
    "n1n5/1Pk5/8/8/8/8/5Kp1/5N1N b - - 0 1",
    "n1n5/1Pk5/8/8/8/8/5Kp1/5N1N w - - 0 1",
    "n1n5/PPPk4/8/8/8/8/4Kppp/5N1N b - - 0 1",
    "n1n5/PPPk4/8/8/8/8/4Kppp/5N1N w - - 0 1",
    "r1bqkbnr/pppppppp/n7/8/8/P7/1PPPPPPP/RNBQKBNR w KQkq - 2 2",
    "r3k1r1/8/8/8/8/8/8/R3K2R b KQq - 0 1",
    "r3k1r1/8/8/8/8/8/8/R3K2R w KQq - 0 1",
    "r3k2r/1b4bq/8/8/8/8/7B/R3K2R w KQkq - 0 1",
    "r3k2r/8/3Q4/8/8/5q2/8/R3K2R b KQkq - 0 1",
    "r3k2r/8/8/8/8/8/8/1R2K2R b Kkq - 0 1",
    "r3k2r/8/8/8/8/8/8/1R2K2R w Kkq - 0 1",
    "r3k2r/8/8/8/8/8/8/2R1K2R b Kkq - 0 1",
    "r3k2r/8/8/8/8/8/8/2R1K2R w Kkq - 0 1",
    "r3k2r/8/8/8/8/8/8/4K3 b kq - 0 1",
    "r3k2r/8/8/8/8/8/8/4K3 w kq - 0 1",
    "r3k2r/8/8/8/8/8/8/R3K1R1 b Qkq - 0 1",
    "r3k2r/8/8/8/8/8/8/R3K1R1 w Qkq - 0 1",
    "r3k2r/8/8/8/8/8/8/R3K2R b KQkq - 0 1",
    "r3k2r/8/8/8/8/8/8/R3K2R w KQkq - 0 1",
    "r3k2r/p1pp1pb1/bn2Qnp1/2qPN3/1p2P3/2N5/PPPBBPPP/R3K2R b KQkq - 3 2",
    "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1",
    "r3k3/1K6/8/8/8/8/8/8 b q - 0 1",
    "r3k3/1K6/8/8/8/8/8/8 w q - 0 1",
    "r3k3/8/8/8/8/8/8/4K3 b q - 0 1",
    "r3k3/8/8/8/8/8/8/4K3 w q - 0 1",
    "r4rk1/1pp1qppp/p1np1n2/2b1p1B1/2B1P1b1/P1NP1N2/1PP1QPPP/R4RK1 w - - 0 10",
    "r6r/1b2k1bq/8/8/7B/8/8/R3K2R b KQ - 3 2",
    "rnb2k1r/pp1Pbppp/2p5/q7/2B5/8/PPPQNnPP/RNB1K2R w KQ - 3 9",
    "rnbq1k1r/pp1Pbppp/2p5/8/2B5/8/PPP1NnPP/RNBQK2R w KQ - 1 8",
    "rnbqkb1r/ppppp1pp/7n/4Pp2/8/8/PPPP1PPP/RNBQKBNR w KQkq f6 0 3",
    "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1" 
};