#include <iostream>
#include "HelpCommand.h"

HelpCommand::HelpCommand(UciClient* a_uci_client) : CommandBase(a_uci_client) { }
HelpCommand::~HelpCommand(){ }

void HelpCommand::Execute(const std::vector<std::string> a_params)
{
    std::cout << "Hello i'm help command!" << std::endl; 
}