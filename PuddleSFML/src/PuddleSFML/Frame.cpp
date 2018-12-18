#include "Frame.h"

namespace pudl
{
	Frame::Frame(int width, int height, const std::string& name = "DEFAULT_WINDOW_NAME")
		: m_window(), m_eventHandles(), m_eventThread(&Frame::run, this, width, height, name) {}
	
	Frame::~Frame()
	{
		stop();
	}

	void Frame::create(int width, int height, const std::string& name)
	{
		stop();

		m_eventHandles.clear();
		
		m_eventThread = std::thread(&Frame::run, this, width, height, name);
	}

	void Frame::run(int width, int height, const std::string& name)
	{
		m_window.create(sf::VideoMode(width, height), name);
		
		while (m_window.isOpen())
		{
			sf::Event event;
			while (m_window.pollEvent(event))
			{
				if (m_eventHandles.count(event.type) == 1) m_eventHandles[event.type]();
				else switch(event.type)
				{
				case sf::Event::Closed:
					m_window.close();
					break;
				}
			}
		}
	}

	void Frame::stop()
	{
		m_window.close();
		if(m_eventThread.joinable()) m_eventThread.join();
	}

	void Frame::setEventHandler(sf::Event::EventType et, const std::function<void(void)>& handler)
	{
		m_eventHandles[et] = handler;
	}
}