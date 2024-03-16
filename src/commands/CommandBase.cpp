#include "CommandBase.h"

CommandBase::CommandBase(UciClient* a_uci_client) : m_uci_client(a_uci_client){ }
CommandBase::~CommandBase() { }
void CommandBase::Execute(const std::vector<std::string> a_params){ }