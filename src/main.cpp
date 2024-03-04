#include <iostream>
#include "types.h"
#include "uci.h"

int main(int argc, char* argv[])
{
    std::cout << ENGINE_ANCII_ART  << std::endl;
    std::cout << "Version: " << ENGINE_VERSION << std::endl;
    std::cout << "Type 'help' to display available commands" << std::endl << std::endl;

    uci uci_loop = uci();
    uci_loop.Run();
    
    std::cin.get();
    return 0;   
}