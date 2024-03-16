#include<iostream>
#include<vector>
#include "UciClient.h"
#include "commands/CommandBase.h"
#include "commands/HelpCommand.h"

UciClient::UciClient() 
{ 
    m_commands = { new HelpCommand(this) };
    m_isRunning = false;
}

UciClient::~UciClient(){ }
void UciClient::Run()
{
    if (m_isRunning) return;
    m_isRunning = true;
}

void UciClient::Stop()
{
    if (!m_isRunning) return;
    m_isRunning = false;
}