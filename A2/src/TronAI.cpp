#include "TronAI.h"

TronAI::TronAI()
{

}

const std::string& TronAI::name() const
{
    return m_name;
}

// TODO: replace "GroupName" with your group's last names, concatenated (no spaces)
TronAI_Student::TronAI_Student()
{
    m_name = "GroupName";
}

// TODO: implement this function
size_t TronAI_Student::getAction(const TronLevel& level, const TronPlayer& player)
{
    return 0;
}

TronAI_Random::TronAI_Random() 
{
    m_name = "Random";
}

size_t TronAI_Random::getAction(const TronLevel& level, const TronPlayer& player)
{
    size_t action = rand() % level.getDirections().size();

    while (!player.isValidAction(action, level))
    {
        action = rand() % level.getDirections().size();
    }

    return action;
}

TronAI_RandomBetter::TronAI_RandomBetter()
{
    m_name = "RandomBetter";
}

size_t TronAI_RandomBetter::getAction(const TronLevel& level, const TronPlayer& player)
{
    std::vector<size_t> actions;

    for (size_t a = 0; a < level.getDirections().size(); a++)
    {
        if (!player.isValidAction(a, level)) { continue; }

        Direction dir = level.getDirections()[a];
        int newX = player.x() + dir.x;
        int newY = player.y() + dir.y;

        if (!level.isSafe(newX, newY)) { continue; }

        actions.push_back(a);
    }

    if (actions.size() == 0) { return 0; }

    return actions[rand() % actions.size()];
}

TronAI_GoStraight::TronAI_GoStraight()
{
    m_name = "GoStraight";
}

size_t TronAI_GoStraight::getAction(const TronLevel& level, const TronPlayer& player)
{
    Direction d = level.getDirections()[player.dir()];
    int nx = player.x() + d.x;
    int ny = player.y() + d.y;

    if (level.isSafe(nx, ny)) { return player.dir(); }

    std::vector<size_t> actions;

    for (size_t a = 0; a < level.getDirections().size(); a++)
    {
        if (!player.isValidAction(a, level)) { continue; }

        Direction dir = level.getDirections()[a];
        int newX = player.x() + dir.x;
        int newY = player.y() + dir.y;	

        if (!level.isSafe(newX, newY)) { continue; }

        actions.push_back(a);
    }

    if (actions.size() == 0) { return 0; }

    return actions[rand() % actions.size()];
}