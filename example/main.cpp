#include "../mqtt2exec.h"

#include <iostream>

void TurnOnLamp()
{

}

void TurnOffLamp()
{

}

int main()
{
	std::cout << "main()" << std::endl;
	mqtt2exec test("10.8.0.1:1883", "zigbee2exec", "hello");
	test.AddCmdCallback("TurnOn", TurnOnLamp);

	// Just block till user tells us to quit.
	while (std::tolower(std::cin.get()) != 'q');

	return 0;
}
