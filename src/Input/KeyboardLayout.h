//
// Created by glosn on 5/1/2022.
//

#ifndef TETRISEXAM_KEYBOARDLAYOUT_H
#define TETRISEXAM_KEYBOARDLAYOUT_H

#include <SFML/Graphics.hpp>

struct KeyboardLayout
{
    sf::Keyboard::Key rotateRight;
    sf::Keyboard::Key fallFast;
    sf::Keyboard::Key moveLeft;
    sf::Keyboard::Key moveRight;
    sf::Keyboard::Key instantFall;
};

#endif //TETRISEXAM_KEYBOARDLAYOUT_H
