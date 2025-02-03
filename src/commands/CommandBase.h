#pragma once
#include <algorithm>
#include <vector>
#include <string>

#define COMMAND_FN std::function<void(const std::vector<std::string>,std::shared_ptr<UciClient>)>

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

static void PrintTestsResults(bool _success)
{
    if (_success)
    {
        std::cout << "[SUCCESS] test completed!" << std::endl;
    }else
    {
        std::cout << "[ERROR] test failed with errors" << std::endl;
    }
}