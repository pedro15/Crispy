#include "commandbase.h"

commandbase::commandbase(uci* uci_client) : uci_client_(uci_client){ }
commandbase::~commandbase() { }
void commandbase::Execute(const std::vector<std::string> args){ }