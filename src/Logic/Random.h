//
// Created by glosn on 5/15/2022.
//

#ifndef TETRISEXAM_RANDOM_H
#define TETRISEXAM_RANDOM_H

#include <random>

class Random
{
public:
    Random();
    explicit Random(int seed);

    int getInt(int min, int max);

private:
    std::mt19937 m_mt;
};


#endif //TETRISEXAM_RANDOM_H
