#include <iostream>
#include "HelpCommand.h"

HelpCommand::HelpCommand(UciClient* uciClient) : CommandBase(uciClient) { }
HelpCommand::~HelpCommand(){ }

void HelpCommand::Execute(const std::vector<std::string> args)
{
    std::cout << "Hello i'm help command!" << std::endl; 
}