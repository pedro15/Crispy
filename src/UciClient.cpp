#include <iostream>
#include <vector>
#include <memory>
#include "UciClient.h"
#if DEBUG 
#include "commands/tests/RunTestsCommand.h"
#endif
#include "commands/CommandBase.h"
#include "commands/HelpCommand.h"
#include "commands/QuitCommand.h"
#include "commands/VersionCommand.h"
#include "commands/PositionCommand.h"
#include "commands/UciCommand.h"
#include "commands/IsReadyCommand.h"
#include "commands/GoCommand.h"
#include "commands/StopCommand.h"


UciClient::UciClient() { }
UciClient::~UciClient(){ }

void UciClient::Init()
{
    std::shared_ptr<UciClient> local_client = shared_from_this();
    // internal commands
    #if DEBUG 
    AddCommand("tests", std::make_unique<RunTestsCommand>(local_client));
    #endif
    AddCommand("help", std::make_unique<HelpCommand>(local_client));
    AddCommand("version", std::make_unique<VersionCommand>(local_client));
    // uci commands
    AddCommand("uci", std::make_unique<UciCommand>(local_client));
    AddCommand("isready", std::make_unique<IsReadyCommand>(local_client));
    AddCommand("position", std::make_unique<PositionCommand>(local_client));
    AddCommand("go", std::make_unique<GoCommand>(local_client));
    AddCommand("stop", std::make_unique<StopCommand>(local_client));
    AddCommand("quit", std::make_unique<QuitCommand>(local_client));

    m_is_running = false;
    m_abort_requested = false;
}

void UciClient::AddCommand(std::string _cmd, std::unique_ptr<CommandBase> _command)
{
    m_commands.emplace(std::make_pair(std::move(_cmd), std::move(_command)));
}

void UciClient::Run()
{
    if (m_is_running) return;
    m_is_running = true;

    std::string user_input;
    std::vector<std::string> cmd_line_args;

    while (m_is_running)
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
    if (!m_is_running) return;
    m_is_running = false;
}

void UciClient::AbortTask(bool _abort)
{
    m_abort_requested = _abort;
}

bool UciClient::IsAbortRequqested()
{
    return m_abort_requested;
}