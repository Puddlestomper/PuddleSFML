#include "Frame.h"

namespace pudl
{
	Frame::Frame(int width, int height, const std::string& name = "DEFAULT_WINDOW_NAME")
		: m_window(), m_mtxEventHandles(), m_eventHandles(), m_eventThread(&Frame::run, this, width, height, name) {}
	
	Frame::~Frame()
	{
		close();
	}

	void Frame::create(int width, int height, const std::string& name)
	{
		close();

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
				m_mtxEventHandles.lock();

				if (m_eventHandles.count(event.type) > 0) m_eventHandles[event.type]();
				else switch(event.type)
				{
				case sf::Event::Closed:
					m_window.close();
					break;
				}

				m_mtxEventHandles.unlock();
			}
		}
	}

	void Frame::close()
	{
		m_window.close();
		if(m_eventThread.joinable()) m_eventThread.join();
	}

	void Frame::setEventHandler(const sf::Event::EventType& et, const std::function<void(void)>& handler)
	{
		m_mtxEventHandles.lock();

		m_eventHandles[et] = handler;

		m_mtxEventHandles.unlock();
	}
}