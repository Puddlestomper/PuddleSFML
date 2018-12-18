#pragma once

#include <string>
#include <unordered_map>
#include <functional>
#include <thread>
#include <mutex>

#include "SFML/Graphics.hpp"

#include "Core.h"

namespace pudl
{
	class PUDL_API Frame final
	{
	public:
		Frame() = default;
		Frame(int width, int height, const std::string& name);
		~Frame();

		void create(int width, int height, const std::string& name = "DEFAULT_FRAME_NAME");
		void close();

		void setEventHandler(const sf::Event::EventType& et, const std::function<void(void)>& handler);
		inline sf::RenderWindow& getWindow() { return m_window; }

		//Forwarding to sf::RenderWindow methods
		//Should probably do this to limit methods that the client can call, but not sure if this is the best way
		/*
		inline sf::Vector2u getSize() const { return m_window.getSize(); }
		inline bool setActive(bool active = true) { return m_window.setActive(active); }
		inline sf::Image capture() const { return m_window.capture(); }
		inline bool isOpen() const { return m_window.isOpen(); }
		inline sf::Vector2i getPosition() const { return m_window.getPosition(); }
		inline void setPosition(const sf::Vector2i& position) { m_window.setPosition(position); }
		inline void setSize(const sf::Vector2u& size) { m_window.setSize(size); }*/

	private:
		void run(int width, int height, const std::string& name);

		sf::RenderWindow m_window;
		std::mutex m_mtxEventHandles;
		std::unordered_map<sf::Event::EventType, std::function<void()>> m_eventHandles;
		std::thread m_eventThread;
	};
}