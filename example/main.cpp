#include "../mqtt2exec.h"

#include <iostream>
#include <future>

void TurnOnSpacecraft()
{
	std::cout << "TurnOnSpacecraft()" << std::endl;
	system("echo 1 > /sys/class/gpio/gpio20/value");
}

void TurnOffSpacecraft()
{
	std::cout << "TurnOffSpacecraft()" << std::endl;
	system("echo 0 > /sys/class/gpio/gpio20/value");
}

int main()
{
	const std::string serverAddress = "10.8.0.1:1883";
	const std::string clientId = "HubScreen";
	const std::string topic = "mqtt2exec";

	mqtt2exec connection(serverAddress, clientId, topic);
	connection.AddCmdCallback("TurnOnSpacecraft", TurnOnSpacecraft);
	connection.AddCmdCallback("TurnOffSpacecraft", TurnOffSpacecraft);
	connection.Connect();

	std::promise<void>().get_future().wait();

	return 0;
}
