#pragma once

#include <vector>
#include <string>

#include "SFML/Graphics.hpp"

#include "Core.h"
#include "Drawable.h"

namespace pudl
{
	class PUDL_API Menu
	{
	public:
		Menu() = default;
		//~Menu();

		void draw() const;
		inline void addDrawable(Drawable& drawable) { m_drawables.emplace_back(&drawable); }

		bool loadMenu(const std::string& file); //True if successful, false otherwise
	private:
		std::vector<Drawable*> m_drawables;
	};
}