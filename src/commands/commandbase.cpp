#include "commandbase.h"

commandbase::~commandbase() { }
commandbase::commandbase(uci &uci_client) : uci_client_(uci_client){ }
void commandbase::Execute(const std::vector<std::string> args){ }