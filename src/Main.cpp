#include <iostream>
#include "Types.h"
#include "UciClient.h"

int main(int count, char* values[])
{
    std::cout << ENGINE_ANCII_ART  << std::endl;
    std::cout << "Version: " << ENGINE_VERSION << std::endl;
    std::cout << "Type 'help' to display available commands" << std::endl << std::endl;

    UciClient uci_loop = UciClient();
    uci_loop.Run();
    
    std::cin.get();
    return 0;   
}