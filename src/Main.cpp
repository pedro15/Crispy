#include <iostream>
#include "Types.h"
#include "UciClient.h"
#include "Bitboard.h"
#define C64(constantU64) constantU64##ULL

int main(int count, char* values[])
{
    Bitboard bb = C64(0x104000280000001);
    
    while (bb)
    {
        Square curr = bb.PopSquare();
        std::cout << curr << std::endl;
    }

    std::cout << ENGINE_ANCII_ART  << std::endl;
    std::cout << ENGINE_VERSION << std::endl;
    std::cout << "Homepage and source code: " << HOMEPAGE << std::endl;
    std::shared_ptr<UciClient> uci_client = std::make_shared<UciClient>();
    uci_client->Init();
    uci_client->Run();
    return 0;   
}