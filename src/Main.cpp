#include <iostream>
#include "Types.h"
#include "UciClient.h"
#include "Bitboard.h"

int main(int count, char* values[])
{
    Bitboard bb = 0x8000000000000001ULL;

    std::cout << bb.Str() << std::endl;
    
    while (bb)
    {
        Square curr = bb.PopSquare();
        std::cout << curr.Str() << std::endl;
    }

    std::cout << ENGINE_ANCII_ART  << std::endl;
    std::cout << ENGINE_VERSION << std::endl;
    std::cout << "Homepage and source code: " << HOMEPAGE << std::endl;
    std::shared_ptr<UciClient> uci_client = std::make_shared<UciClient>();
    uci_client->Init();
    uci_client->Run();
    return 0;   
}