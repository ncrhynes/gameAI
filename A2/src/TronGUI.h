#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TronLevel.h"


class TronGUI
{
    std::string         m_path;
    TronLevel           m_level;
    sf::RenderWindow    m_window;          
    sf::Font            m_font;             
    sf::Text            m_text;
    sf::Clock           m_clock;
	bool				m_paused = false;
    bool                m_running = true;  

    void setMap();
    void init();  

    void sUserInput();
    void sRender();   

    void drawLine(float x1, float y1, float x2, float y2, sf::Color color);
    
public:

    TronGUI(const std::string & config); 

    void run();
};