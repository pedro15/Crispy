#include<iostream>
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
    std::cout << "commands size is " << commands_.size() << std::endl;

    for (std::vector<commandbase>::size_type i = 0; i != commands_.size(); i++)
    {
        commands_[i]->Execute({});
    }
}

void uci::SayHello()
{
    std::cout << "Hello! from UCI client!" << std::endl;
}