#include <iostream>
#include "HelpCommand.h"

HelpCommand::HelpCommand(UciClient* uci_client) : CommandBase(uci_client) { }

void HelpCommand::Execute(const std::vector<std::string> params)
{
    std::cout << "Hello i'm help command!" << std::endl;
    std::cout << "age is " << GetParamValue<int>(params, "age") << std::endl;
}

HelpCommand::~HelpCommand(){ }