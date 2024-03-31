#include "HelpCommand.h"

HelpCommand::HelpCommand(UciClient* uci_client) : CommandBase(uci_client) { }

void HelpCommand::Execute(const std::vector<std::string> params)
{
    std::cout << " Crispy is meant to be used with a graphical user interface (GUI) and implements the Universal Chess Interface (UCI) protocol to communicate with a GUI, etc.." << std::endl;
    std::cout << " please refer to HomePage (" << HOMEPAGE << ") for more details about available commands." << std::endl;
}

HelpCommand::~HelpCommand(){ }