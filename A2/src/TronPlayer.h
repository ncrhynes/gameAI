#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class TronAI;
class TronLevel;
class TronPlayer
{
    friend class TronLevel;

    size_t      m_id    = 0;
    int         m_x     = 0;
    int         m_y     = 0;
    size_t      m_dir   = 0;
    sf::Color   m_color;
    size_t      m_score = 0;
    bool        m_alive = true;
    std::shared_ptr<TronAI> m_ai;

    void kill();
 
public:

    TronPlayer();
    TronPlayer(size_t id, size_t x, size_t y, sf::Color color, std::shared_ptr<TronAI> ai);

    size_t id() const;
    size_t x() const;
    size_t y() const;
    size_t dir() const;
    size_t score() const;
    bool isAlive() const;
    bool isValidAction(size_t action, const TronLevel& level) const;

    void doTurn(const TronLevel & map);

    std::shared_ptr<TronAI> getAI();

    const sf::Color& color() const;
};