#include "CommandBase.h"
#include <iostream>
#include <vector>
#include <sstream>

CommandBase::CommandBase(std::shared_ptr<UciClient> uci_client) : m_uci_client(uci_client){ }
CommandBase::~CommandBase() { }
void CommandBase::Execute(const std::vector<std::string> params){ }