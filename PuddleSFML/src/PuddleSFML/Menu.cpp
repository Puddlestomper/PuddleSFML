#include "Menu.h"

namespace pudl
{
	void Menu::draw() const
	{
		for (Drawable* d : m_drawables) d->draw();
	}
}