//
// Created by glosn on 5/15/2022.
//

#include "Random.h"

Random::Random(int seed)
        : m_mt(seed)
{

}

Random::Random()
        : m_mt(std::random_device{}())
{
}

int Random::getInt(int min, int max)
{
    std::uniform_int_distribution<> dist(min, max - 1);
    return dist(m_mt);
}


