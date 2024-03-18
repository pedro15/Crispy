#pragma once
#include <string>
#include <iostream>
#include "../UciClient.h"
#include "../lib/strutil.h"

class UciClient;
class CommandBase
{
protected:
    UciClient* m_uci_client;
public:
    CommandBase(UciClient* a_uci_client);
    ~CommandBase();
    virtual void Execute(const std::vector<std::string> a_params);
};

template<typename T> static T GetParamValue(const std::vector<std::string> a_params, const std::string a_token)
{ 
	T result = T{};
	int next_index;
    for (int i = 0; i < a_params.size(); i++)
	{
		if (strutil::compare_ignore_case(a_params[i], a_token))
		{
			next_index = i + 1;
			if (next_index < a_params.size())
			{
				std::istringstream(a_params[next_index]) >> result;
				return result;
			}
		}
	}
	return result;
}