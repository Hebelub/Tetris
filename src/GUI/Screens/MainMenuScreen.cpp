//
// Created by glosn on 5/13/2022.
//

#include "MainMenuScreen.h"
#include <SFML/Graphics.hpp>

namespace Tetris::GUI
{

    MainMenuScreen::MainMenuScreen()
    {

     //  m_manager->

     //  sf::Sprite button(m_manager);

     //  addButton(sf::Vector2i{300, 300}, );
    }

    void MainMenuScreen::draw(sf::RenderTarget &renderTarget)
    {
        sf::RectangleShape square{};
        const sf::Vector2f size{23, 23};
        square.setSize(size);
        square.setFillColor(sf::Color::Magenta);
        renderTarget.draw(square);
    }

    void MainMenuScreen::update(float deltaTime)
    {

    }




} // Tetris::GUI