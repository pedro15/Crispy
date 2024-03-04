#include <iostream>
#include "HelpCommand.h"

HelpCommand::HelpCommand(Uci* uci_client) : CommandBase(uci_client) { }
HelpCommand::~HelpCommand(){ }

void HelpCommand::Execute(const std::vector<std::string> args)
{
    std::cout << "Hello i'm help command!" << std::endl; 
}