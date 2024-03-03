#include <iostream>
#include "types.h"
#include "uci.h"
#include "commands/helpcommand.h"

int main(int argc, char* argv[])
{
    std::cout << ENGINE_HEADER  << std::endl;
    std::cout << "VERSION: " << ENGINE_VERSION << std::endl;
    std::cout << "Type 'help' to display available commands" << std::endl;

    uci uci_loop = uci();
    uci_loop.Run();
    
    helpcommand help_command = helpcommand(uci_loop);
    help_command.Execute(std::vector<std::string>());
    
    std::cin.get();
    return 0;   
}