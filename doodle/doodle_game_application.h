#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

// Класс, запускающий игру
class GameApplication {
public:

    // Метод подготовки: загрузка текстур
    std::vector<sf::Texture> preparing();

    // Метод, запускающий игру
    int run(); 
};




