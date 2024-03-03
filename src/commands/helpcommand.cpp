#include <iostream>
#include "helpcommand.h"

helpcommand::helpcommand(uci &uci_client_) : commandbase(uci_client_){ }
helpcommand::~helpcommand(){ }

void helpcommand::Execute(const std::vector<std::string> args)
{
    std::cout << "Hello i'm help command!" << std::endl; 
}