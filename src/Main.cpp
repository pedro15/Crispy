#include <iostream>
#include "Types.h"
#include "UciClient.h"

int main(int count, char* values[])
{
    std::cout << ENGINE_ANCII_ART  << std::endl;
    std::cout << ENGINE_VERSION << std::endl;
    std::cout << "Homepage and source code: " << HOMEPAGE << std::endl;

    UciClient uci_loop = UciClient();
    uci_loop.Run();

    return 0;   
}