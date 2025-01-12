#include "HelpCommand.h"
#include "../Info.h"

HelpCommand::HelpCommand(std::shared_ptr<UciClient> _uci_client) : CommandBase(_uci_client) { }
HelpCommand::~HelpCommand(){ }

void HelpCommand::Execute(const std::vector<std::string> _params)
{
    std::cout << " Crispy is meant to be used with a graphical user interface (GUI) \n and implements the Universal Chess Interface (UCI) protocol to communicate with a GUI, etc.." << std::endl;
    std::cout << " please refer to HomePage (" << HOMEPAGE << ") for more details about available commands." << std::endl;
}

