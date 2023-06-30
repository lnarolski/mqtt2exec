#include "../mqtt2exec.h"

#include <iostream>
#include <future>

void TurnOnSpacecraft()
{
	std::cout << "TurnOnSpacecraft()" << std::endl;
	system("date > /mnt/h/mqtt2exec/test.tmp");
	//	system("echo 1 > /sys/class/gpio/gpio20/value");
}

void TurnOffSpacecraft()
{
	std::cout << "TurnOffSpacecraft()" << std::endl;
	system("date > /mnt/h/mqtt2exec/test2.tmp");
    //system("echo 0 > /sys/class/gpio/gpio20/value");
}

int main()
{
	mqtt2exec test("10.8.0.1:1883", "HubScreen", "zigbee2exec");
	test.AddCmdCallback("TurnOnSpacecraft", TurnOnSpacecraft);
	test.AddCmdCallback("TurnOffSpacecraft", TurnOffSpacecraft);

	std::promise<void>().get_future().wait();

	return 0;
}
