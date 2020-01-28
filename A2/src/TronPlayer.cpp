#include "TronPlayer.h"
#include "TronAI.h"


TronPlayer::TronPlayer()
{

}

TronPlayer::TronPlayer(size_t id, size_t x, size_t y, sf::Color color, std::shared_ptr<TronAI> ai)
    : m_id      (id)
    , m_x       (x)
    , m_y       (y)
    , m_color   (color)
    , m_ai      (ai)
{
    
}

size_t TronPlayer::x() const
{
    return m_x;
}

size_t TronPlayer::y() const
{
    return m_y;
}

size_t TronPlayer::dir() const
{
    return m_dir;
}

const sf::Color& TronPlayer::color() const
{
    return m_color;
}

std::shared_ptr<TronAI> TronPlayer::getAI()
{
    return m_ai;
}

bool TronPlayer::isValidAction(size_t action, const TronLevel & level) const
{
    const Direction& oldDir = level.getDirections()[m_dir];
    const Direction& newDir = level.getDirections()[action];

    // it's not a valid action if it goes backward onto itself
    if ((oldDir.x != 0) && (oldDir.x + newDir.x == 0)) { return false; }
    if ((oldDir.y != 0) && (oldDir.y + newDir.y == 0)) { return false; }
    return true;
}

void TronPlayer::kill()
{
    m_alive = false;
}

bool TronPlayer::isAlive() const
{
    return m_alive;
}

size_t TronPlayer::id() const
{
    return m_id;
}

size_t TronPlayer::score() const
{
    return m_score;
}

void TronPlayer::doTurn(const TronLevel& level)
{
    // get the index of the action to perform from the ai
    size_t action = m_ai->getAction(level, *this);
    m_dir = action;

    // update the position based on the direction
    const Direction& dir = level.getDirections()[action];
    m_x += dir.x;
    m_y += dir.y;

    m_score++;
}