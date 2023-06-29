#include "../mqtt2exec.h"

#include <iostream>

void TurnOnLamp()
{
	std::cout << "TurnOnMap()" << std::endl;
	system("echo 123 > /mnt/h/mqtt2exec/test.txt");
	//	system("echo 1 > /sys/class/gpio/gpio20/value");
}

void TurnOffLamp()
{
        //system("echo 0 > /sys/class/gpio/gpio20/value");
}

int main()
{
	std::cout << "main()" << std::endl;
	mqtt2exec test("10.8.0.1:1883", "HubScreen", "zigbee2exec");
	test.AddCmdCallback("TurnOn", TurnOnLamp);

	// Just block till user tells us to quit.
	while (std::tolower(std::cin.get()) != 'q');

	return 0;
}
