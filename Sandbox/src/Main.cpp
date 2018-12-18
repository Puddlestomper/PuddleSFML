#include <iostream>

#include "PuddleSFML.h"

int main()
{
	std::cout << "Hello World!\n";

	pudl::Frame frame;

	frame.create(500, 450, "TESTESTESTEST");

	frame.setEventHandler(sf::Event::EventType::Closed, [&frame](void)
	{
		frame.getWindow().close();
		std::cout << "Closed!\n"; 
	});
}