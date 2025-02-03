#include <iostream>
#include <vector>
#include <memory>
#include "UciClient.h"
#include "commands/MainCommands.h"
#if DEBUG 
#include "commands/DebugCommands.h"
#endif

UciClient::UciClient() { }
UciClient::~UciClient(){ }

void UciClient::Init()
{
    m_is_running = false;
    m_abort_requested = false;

    AddCommand("version" ,command_version);
    AddCommand("help", command_help);
    AddCommand("quit", command_quit);
    AddCommand("uci" , command_uci);
    AddCommand("isready", command_isReady);
    AddCommand("position", command_position);
    AddCommand("go", command_go);
    AddCommand("stop", command_stop);
    #if DEBUG 
    AddCommand("tests", command_runTests);
    #endif
}

void UciClient::AddCommand(std::string _cmd, COMMAND_FN _command)
{
    m_commands.emplace(std::make_pair(std::move(_cmd), _command));
}

void UciClient::Run()
{
    if (m_is_running) return;
    m_is_running = true;
    std::shared_ptr<UciClient> local_client = shared_from_this();

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
            m_commands[cmd_line_args[0]](cmd_line_args, local_client);
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

void UciClient::AbortCurrentTask()
{
    m_abort_requested = true;
}

bool UciClient::IsAbortRequqested()
{
    return m_abort_requested;
}