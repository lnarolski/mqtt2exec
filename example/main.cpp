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
	mqtt2exec test("", "", "");
	test.AddCmdCallback("TurnOn", TurnOnLamp);
	return 0;
}
