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
    CommandBase(std::shared_ptr<UciClient> _uci_client);
    ~CommandBase();
    virtual void Execute(const std::vector<std::string> _params);
};

template<typename T> static T GetParamValue(const std::vector<std::string> _params, const std::string _token)
{ 
	T result = T{};
	int next_index;
    for (int i = 0; i < _params.size(); i++)
	{
		if (strutil::compare_ignore_case(_params[i], _token))
		{
			next_index = i + 1;
			if (next_index < _params.size())
			{
				std::istringstream(_params[next_index]) >> result;
				return result;
			}
		}
	}
	return result;
}

static bool HasParam(std::string _token, const std::vector<std::string> _params)
{
	auto begin = _params.begin();
	auto end = _params.end();
	return std::find(begin,end, _token) != end;
}