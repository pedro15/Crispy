#include<iostream>
#include<vector>
#include "Uci.h"
#include "commands/CommandBase.h"
#include "commands/HelpCommand.h"

Uci::Uci() 
{ 
    commands = { new HelpCommand(this) };
}
Uci::~Uci(){ }
void Uci::Run()
{
    if (isRunning) return;
    isRunning = true;
    while (isRunning)
    {
        
    }   
}

void Uci::Stop()
{
    if (!isRunning) return;
    isRunning = false;
}