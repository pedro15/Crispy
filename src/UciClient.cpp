#include <iostream>
#include <vector>
#include "UciClient.h"
#include "commands/CommandBase.h"
#include "commands/HelpCommand.h"
#include "commands/QuitCommand.h"
#include "commands/VersionCommand.h"
#include "commands/PositionCommand.h"
#include "commands/UciCommand.h"
#include "commands/IsReadyCommand.h"
#include "commands/GoCommand.h"
#include "commands/StopCommand.h"

UciClient::UciClient() 
{ 
    // internal commands
    AddCommand("help", std::make_unique<HelpCommand>(this));
    AddCommand("version", std::make_unique<VersionCommand>(this));
    // uci commands
    AddCommand("uci", std::make_unique<UciCommand>(this));
    AddCommand("isready", std::make_unique<IsReadyCommand>(this));
    AddCommand("position", std::make_unique<PositionCommand>(this));
    AddCommand("go", std::make_unique<GoCommand>(this));
    AddCommand("stop", std::make_unique<StopCommand>(this));
    AddCommand("quit", std::make_unique<QuitCommand>(this));

    m_isRunning = false;
    m_abort_requested = false;
}
UciClient::~UciClient(){ }

void UciClient::AddCommand(std::string cmd, std::unique_ptr<CommandBase> val)
{
    m_commands.emplace(std::make_pair(std::move(cmd), std::move(val)));
}

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

void UciClient::AbortTask(bool abort)
{
    m_abort_requested = abort;
}

bool UciClient::IsAbortRequqested()
{
    return m_abort_requested;
}