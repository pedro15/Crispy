#include "CommandBase.h"

CommandBase::CommandBase(UciClient* uciClient) : m_uciClient(uciClient){ }
CommandBase::~CommandBase() { }
void CommandBase::Execute(const std::vector<std::string> args){ }