#include <iostream>
#include "Types.h"
#include "Uci.h"

int main(int argc, char* argv[])
{
    std::cout << ENGINE_ANCII_ART  << std::endl;
    std::cout << "Version: " << ENGINE_VERSION << std::endl;
    std::cout << "Type 'help' to display available commands" << std::endl << std::endl;

    Uci uci_loop = Uci();
    uci_loop.Run();
    
    std::cin.get();
    return 0;   
}