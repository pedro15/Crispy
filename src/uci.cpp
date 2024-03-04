#include<iostream>
#include<vector>
#include "uci.h"
#include "commands/commandbase.h"
#include "commands/helpcommand.h"

uci::uci() 
{ 
    commands_ = { new helpcommand(this) };
}
uci::~uci(){ }
void uci::Run()
{
    if (is_running) return;
    is_running = true;
    while (is_running)
    {
        
    }   
}

void uci::Stop()
{
    if (!is_running) return;
    is_running = false;
}