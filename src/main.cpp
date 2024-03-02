#include <iostream>
#include "types.h"
#include "uci.h"

int main(int argc, char* argv[])
{
    std::cout << ENGINE_HEADER  << std::endl;
    std::cout << ENGINE_VERSION << " - type 'help' to display available commands" << std::endl << std::endl;

    uci uci_loop = uci();
    uci_loop.Run();
    
    std::cin.get();
    return 0;   
}