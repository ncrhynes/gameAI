#include "TronLevel.h"
#include "TronAI.h"

#include <iostream>
#include <fstream>

TronLevel::TronLevel()
{

}

TronLevel::TronLevel(const std::string& path)
{
    std::ifstream fin(path);
    fin >> m_width >> m_height >> m_gridSize;
    m_level = std::vector<std::vector<int>>(m_width, std::vector<int>(m_height, -1));
    
    std::string token;
    int x, y, r, g, b;
    while (fin.good())
    {
        fin >> token;
        if (token == "Player")
        {
            // read in the values for the player
            fin >> token >> x >> y >> r >> g >> b;

            // add the new player to the players vector
            m_players.push_back(TronPlayer(m_players.size(), x, y, sf::Color(r,g,b), getAI(token)));

            // set the grid cell to its value
            m_level[x][y] = m_players.back().id();
        }
    }
}

void TronLevel::doTurn()
{
    for (auto& player : m_players)
    {
        // skip this player if it's not alive anymore
        if (!player.isAlive()) { continue; }

        // do the turn for the player (ai decision + position update)
        player.doTurn(*this);

        // if the player is not on a blank tile, it dies
        if (!isSafe(player.x(), player.y())) { player.kill(); }

        // if the player is still alive, set the grid cell to its value
        if (player.isAlive()) { m_level[player.x()][player.y()] = player.id(); }
    }
}

std::shared_ptr<TronAI> TronLevel::getAI(const std::string& name) const
{
    if      (name == "Student")         { return std::make_shared<TronAI_Student>(); }
    else if (name == "Random")          { return std::make_shared<TronAI_Random>(); }
    else if (name == "RandomBetter")    { return std::make_shared<TronAI_RandomBetter>(); }
    else if (name == "GoStraight")      { return std::make_shared<TronAI_GoStraight>(); }
    else
    {
        std::cerr << "Unknown AI name: " << name << "\n";
        std::exit(-1);
    }
}

std::vector<TronPlayer>& TronLevel::getPlayers()
{
    return m_players;
}

const std::vector<Direction>& TronLevel::getDirections() const
{
    return m_directions;
}

size_t TronLevel::width() const
{
    return m_width;
}

size_t TronLevel::height() const
{
    return m_height;
}

size_t TronLevel::pixelWidth() const
{
    return width() * gridSize();
}

size_t TronLevel::pixelHeight() const
{
    return height() * gridSize();
}

size_t TronLevel::gridSize() const
{
    return m_gridSize;
}

bool TronLevel::isSafe(size_t x, size_t y) const
{
    return x >= 0 && x < m_level.size() && y >= 0 && y < m_level[x].size() && m_level[x][y] == -1;
}

int TronLevel::getTile(size_t x, size_t y) const
{
    return m_level[x][y];
}