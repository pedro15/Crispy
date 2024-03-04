#include "CommandBase.h"

CommandBase::CommandBase(Uci* uciClient) : uci_client(uciClient){ }
CommandBase::~CommandBase() { }
void CommandBase::Execute(const std::vector<std::string> args){ }