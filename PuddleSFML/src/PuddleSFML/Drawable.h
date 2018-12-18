#pragma once

#include "Core.h"

namespace pudl
{
	struct PUDL_API Drawable
	{
		virtual void draw() = 0;
	};
}