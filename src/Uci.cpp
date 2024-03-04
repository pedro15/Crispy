#include<iostream>
#include<vector>
#include "Uci.h"
#include "commands/CommandBase.h"
#include "commands/HelpCommand.h"

Uci::Uci() 
{ 
    commands = { new HelpCommand(this) };
    is_running = false;
}
Uci::~Uci(){ }
void Uci::Run()
{
    if (is_running) return;
    is_running = true;
    while (is_running)
    {
        
    }   
}

void Uci::Stop()
{
    if (!is_running) return;
    is_running = false;
}