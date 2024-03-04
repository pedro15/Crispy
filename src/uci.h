#pragma once
#include <vector>
#include "commands/commandbase.h"

class commandbase;
class uci
{
private:
    std::vector<commandbase*> commands_;
public:
    uci();
    ~uci();
    void Run();
    void SayHello();
};