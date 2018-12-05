#pragma once

#include <string>

#include "SFML/Graphics.hpp"

#include "Core.h"

namespace pudl
{
	class PUDL_API Frame : public sf::RenderWindow
	{
	public:
		Frame(int width, int height)
			: width(width), height(height) {}

		void PrintFrame() const;
		void qCreate(const std::string& name);
	private:
		int width, height;
	};
}