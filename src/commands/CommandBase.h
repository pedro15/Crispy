#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include "../UciClient.h"
#include "../lib/strutil.h"

class UciClient;
class CommandBase
{
protected:
    UciClient* m_uci_client;
public:
    CommandBase(UciClient* uci_client);
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

static std::string GetFEN(const std::vector<std::string> params)
{
	std::stringstream result;
	for (int i = 0; i < params.size(); i++)
	{
		if (params[i] == "fen" || params[i] == "position")
		{
			continue;
		}else if (params[i] == "moves")
		{
			break;
		}

		result << params[i];
		if (i < params.size() - 1 && params[i+1] != "moves")
			result << " ";
	}
	return result.str();
}