#include "TronGUI.h"
#include "TronAI.h"

#include <fstream>
#include <iostream>
#include <sstream>

TronGUI::TronGUI(const std::string & path)
{ 
    m_path = path;
    setMap();
    init();
}

void TronGUI::setMap()
{
    m_level = TronLevel(m_path);
}

void TronGUI::init()
{
    m_window.create(sf::VideoMode(m_level.pixelWidth() + 200, m_level.pixelHeight()), "Tron");
    m_window.setFramerateLimit(60);

    m_font.loadFromFile("fonts/arial.ttf");
    m_text.setFont(m_font);
    m_text.setPosition(10, 5);
    m_text.setCharacterSize(20);
}

void TronGUI::run()
{
    while (m_running)
    {
		if (!m_paused)
		{
			m_level.doTurn();
		}
		sUserInput();
		sRender();
    }
}

// SFML has no dedicated function to draw a line, so we make one
void TronGUI::drawLine(float x1, float y1, float x2, float y2, sf::Color color)
{
    sf::VertexArray lines(sf::LinesStrip, 2);
    lines[0].position.x = x1; lines[0].position.y = y1; lines[0].color = color;
    lines[1].position.x = x2; lines[1].position.y = y2; lines[1].color = color;
    m_window.draw(lines);
}

void TronGUI::sUserInput()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        // this event triggers when the window is closed
        if (event.type == sf::Event::Closed)
        {
            m_running = false;
        }

        // this event is triggered when a key is pressed
        if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
                case sf::Keyboard::Escape: m_running = false; break;
                case sf::Keyboard::R: setMap(); break;
				case sf::Keyboard::P: m_paused = !m_paused; break;
            }
        }
    }
}


void TronGUI::sRender()
{
    m_window.clear();

    // draw background
    float g = (float)m_level.gridSize();

    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(g, g));
    //rect.setOutlineColor(sf::Color::White);
    //rect.setOutlineThickness(1);

    for (size_t x = 0; x < m_level.width(); x++)
    {
        for (size_t y = 0; y < m_level.height(); y++)
        {
            int val = m_level.getTile(x, y);
            if (val == -1) continue;

            rect.setFillColor(m_level.getPlayers()[val].color());
            rect.setPosition(x * g, y * g);
            m_window.draw(rect);
        }
    }

    for (size_t i = 0; i <= m_level.width(); i++)
    {
        drawLine(i * g, 0, i * g, (float)m_level.pixelHeight(), sf::Color(30, 30, 30));
    }

    for (size_t j = 0; j < m_level.height(); j++)
    {
        drawLine(0, j * g, (float)m_level.pixelWidth(), j * g, sf::Color(30, 30, 30));
    }

    // draw score
    for (size_t i=0; i<m_level.getPlayers().size(); i++)
    {
        auto& player = m_level.getPlayers()[i];
        std::stringstream ss;
        ss << player.getAI()->name() << "\n" << player.score();
        m_text.setColor(player.color());
        m_text.setString(ss.str().c_str());
        m_text.setPosition(m_level.pixelWidth() + 5, 5 + i * 64);
        m_window.draw(m_text);
    }


    
    

    m_window.display();
}