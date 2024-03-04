#include "CommandBase.h"

CommandBase::CommandBase(Uci* uci_client) : uci_client_(uci_client){ }
CommandBase::~CommandBase() { }
void CommandBase::Execute(const std::vector<std::string> args){ }