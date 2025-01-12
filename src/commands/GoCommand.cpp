#include <chrono>
#include <thread>
#include <iostream>
#include "GoCommand.h"
ThreadPool threads(1);

GoCommand::GoCommand(std::shared_ptr<UciClient> _uci_client) : CommandBase(_uci_client) { }
GoCommand::~GoCommand() { }

void GoCommand::Execute(std::vector<std::string> _args)
{
    threads.enqueue([this]{ Run(); });
}

void GoCommand::Run()
{
    // Placeholder function for now to test command abort
    int counter = 2000;
    while (counter > 0)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        counter--;
        if (m_uci_client->IsAbortRequqested()) break;
    }
    std::cout << "bestmove d2d4" << std::endl;
}