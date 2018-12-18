#pragma once

#include <string>
#include <unordered_map>
#include <functional>
#include <thread>

#include "SFML/Graphics.hpp"

#include "Core.h"

namespace pudl
{
	class PUDL_API Frame
	{
	public:
		Frame() = default;
		Frame(int width, int height, const std::string& name);
		~Frame();

		void create(int width, int height, const std::string& name = "DEFAULT_FRAME_NAME");
		void stop();

		void setEventHandler(sf::Event::EventType et, const std::function<void(void)>& handler);
	private:
		void run(int width, int height, const std::string& name);

		sf::RenderWindow m_window;
		std::unordered_map<sf::Event::EventType, std::function<void()>> m_eventHandles;
		std::thread m_eventThread;
	};
}