#include "CommandBase.h"

CommandBase::CommandBase(Uci* uci_client) : uciClient(uci_client){ }
CommandBase::~CommandBase() { }
void CommandBase::Execute(const std::vector<std::string> args){ }