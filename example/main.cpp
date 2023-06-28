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
	mqtt2exec test("tcp://10.8.0.1:1883", "zigbee2exec", "hello");
	test.AddCmdCallback("TurnOn", TurnOnLamp);
	return 0;
}
