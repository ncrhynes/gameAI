#pragma once

#include <vector>
#include <string>
#include "TronPlayer.h"

struct Direction
{
    int x = 0;
    int y = 0;
};

class TronLevel
{
    size_t                          m_width = 0;
    size_t                          m_height = 0;
    size_t                          m_gridSize = 64;
    std::vector<std::vector<int>>   m_level;
    std::vector<TronPlayer>         m_players;

    // Legal Directions                              UP       DOWN    LEFT     RIGHT
    std::vector<Direction>          m_directions = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };;

    std::shared_ptr<TronAI> getAI(const std::string& name) const;

public:

    TronLevel();
    TronLevel(const std::string& path);

    size_t width() const;
    size_t height() const;
    size_t gridSize() const;
    size_t pixelWidth() const;
    size_t pixelHeight() const;
    
    void doTurn();

    std::vector<TronPlayer> & getPlayers();
    const std::vector<Direction>& getDirections() const;

    bool isSafe(size_t x, size_t y) const;
    int getTile(size_t x, size_t y) const;
};