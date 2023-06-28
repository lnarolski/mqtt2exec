#pragma once

#include <string>
#include <map>

#include <iostream>

class mqtt2exec
{
	private:
	std::map<std::string, void(*)()> callbacks{};

	public:
	mqtt2exec(std::string serverAddress, std::string clientId, std::string topic);
	~mqtt2exec();

	bool AddCmdCallback(std::string receivedMsg, void(*callback)());
	bool RemoveCmdCallback(std::string receivedMsg);
};
