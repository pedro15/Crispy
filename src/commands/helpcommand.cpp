#include <iostream>
#include "helpcommand.h"

helpcommand::helpcommand(uci* uci_client) : commandbase(uci_client) { }
helpcommand::~helpcommand(){ }

void helpcommand::Execute(const std::vector<std::string> args)
{
    std::cout << "Hello i'm help command!" << std::endl; 
    uci_client_->SayHello();
}