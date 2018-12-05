#pragma once

#include <iostream>

#include "Core.h"

namespace pudl
{
	class PUDL_API Frame
	{
	public:
		Frame(int width, int height)
			: width(width), height(height) {}

		void PrintFrame() const;

	private:
		int width, height;
	};
}