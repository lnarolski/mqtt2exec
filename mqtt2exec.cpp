#include "mqtt2exec.h"

mqtt2exec::mqtt2exec(std::string serverAddress, std::string clientId, std::string topic)
{
        std::cout << "mqtt2exec::mqtt2exec(std::string serverAddress, std::string clientId, std::string topic)" << std::endl;
}

mqtt2exec::~mqtt2exec()
{
	
}

bool mqtt2exec::AddCmdCallback(std::string receivedMsg, void(*callback)())
{
	std::cout << "mqtt2exec::AddCmdCallback(std::string receivedMsg, void(*callback)())" << std::endl;
	if (callbacks.find(receivedMsg) == callbacks.end())
	{
		return false;
	}
	
	callbacks[receivedMsg] = callback;
	return true;
}

bool mqtt2exec::RemoveCmdCallback(std::string receivedMsg)
{
	std::cout << "mqtt2exec::RemoveCmdCallback(std::string receivedMsg)" << std::endl;
	return true;
}
