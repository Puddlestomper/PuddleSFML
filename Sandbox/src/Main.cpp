#include <iostream>

#include "SFML/Graphics.hpp"

#include "PuddleSFML.h"

int main()
{
	std::cout << "Hello World!\n";

	pudl::Frame frame(500, 450);
	frame.PrintFrame();
	frame.qCreate("TESTTTTTTTTTT");

	while (frame.isOpen())
	{
		sf::Event event;
		while (frame.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				frame.close();
		}
	}
}