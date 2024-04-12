#include "HelpCommand.h"

HelpCommand::HelpCommand(std::shared_ptr<UciClient> uci_client) : CommandBase(uci_client) { }
HelpCommand::~HelpCommand(){ }

void HelpCommand::Execute(const std::vector<std::string> params)
{
    std::cout << " Crispy is meant to be used with a graphical user interface (GUI) \n and implements the Universal Chess Interface (UCI) protocol to communicate with a GUI, etc.." << std::endl;
    std::cout << " please refer to HomePage (" << HOMEPAGE << ") for more details about available commands." << std::endl;
}

