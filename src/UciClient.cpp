#include <iostream>
#include <vector>
#include "UciClient.h"
#include "commands/CommandBase.h"
#include "commands/HelpCommand.h"
#include "commands/QuitCommand.h"
#include "commands/VersionCommand.h"
#include "commands/PositionCommand.h"

UciClient::UciClient() 
{ 
    m_commands = {  {"help", new HelpCommand(this)}, {"quit", new QuitCommand(this)}, {"version", new VersionCommand(this)},
                    {"position", new PositionCommand(this)} };
    m_isRunning = false;
}
UciClient::~UciClient(){ }

void UciClient::Run()
{
    if (m_isRunning) return;
    m_isRunning = true;

    std::string user_input;
    std::vector<std::string> cmd_line_args;

    while (m_isRunning)
    {
        user_input.clear();
        std::getline(std::cin,user_input);
        strutil::trim(user_input);

        cmd_line_args.clear();
        cmd_line_args = strutil::split(user_input, " ");
        
        if (cmd_line_args.size() > 0 && m_commands.find(cmd_line_args[0]) != m_commands.end())
        {
            m_commands[cmd_line_args[0]]->Execute(cmd_line_args);
        }else if (!user_input.empty()) 
        {
            std::cout << "Command not found" << std::endl;
        }
    }
}

void UciClient::Stop()
{
    if (!m_isRunning) return;
    m_isRunning = false;
}