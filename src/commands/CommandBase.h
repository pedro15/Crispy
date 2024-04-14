#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include "../UciClient.h"
#include "../lib/strutil.h"
#include "../Types.h"
#include "../Notation.h"

class UciClient;
class CommandBase
{
protected:
    std::shared_ptr<UciClient> m_uci_client;
public:
    CommandBase(std::shared_ptr<UciClient> uci_client);
    ~CommandBase();
    virtual void Execute(const std::vector<std::string> params);
};

template<typename T> static T GetParamValue(const std::vector<std::string> params, const std::string token)
{ 
	T result = T{};
	int next_index;
    for (int i = 0; i < params.size(); i++)
	{
		if (strutil::compare_ignore_case(params[i], token))
		{
			next_index = i + 1;
			if (next_index < params.size())
			{
				std::istringstream(params[next_index]) >> result;
				return result;
			}
		}
	}
	return result;
}