#include "Frame.h"

#include <iostream>

namespace pudl
{
	void Frame::PrintFrame() const
	{
		std::cout << "Frame: " << width << ", " << height << "\n";
	}

	void Frame::qCreate(const std::string& name)
	{
		create(sf::VideoMode(width, height), name);
	}
}