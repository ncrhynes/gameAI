#pragma once

#include "TronLevel.h"
#include "TronPlayer.h"


class TronAI
{
protected:

    std::string m_name = "Default";

public:

    TronAI();
    const std::string& name() const;

    virtual size_t getAction(const TronLevel& level, const TronPlayer& player) = 0;
};

class TronAI_Student : public TronAI
{
public:

    TronAI_Student();
    virtual size_t getAction(const TronLevel& level, const TronPlayer& player);
};

class TronAI_Random : public TronAI
{
public:

    TronAI_Random();
    virtual size_t getAction(const TronLevel& level, const TronPlayer& player);
};

class TronAI_RandomBetter : public TronAI
{
public:

    TronAI_RandomBetter();
    virtual size_t getAction(const TronLevel& level, const TronPlayer& player);
};

class TronAI_GoStraight : public TronAI
{
public:

    TronAI_GoStraight();
    virtual size_t getAction(const TronLevel& level, const TronPlayer& player);
};