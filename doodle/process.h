#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

// Класс функций, использующихся в процессе игры
class Process {
public:
	Process(float n1, float n2, float n4, std::vector<std::pair<int, int>> plats);

	// Метод для постепенного пролистывания экрана
	std::pair<float, float> screenScrolling();

	// Метод randomPlatforms - придание рандомных координат платформам
    void randomPlatforms();

	// Метод standOnPlatforms - отработка отталкивания от платформ
	float standOnPlatform(float x);

	// Метод newPlatforms - создает новые платформы после прохождения прежних игроком
    void newPlatforms();

    // Метод drawPlatforms - отрисовка платформ
    sf::Sprite drawPlatforms(sf::Sprite sPlat, int i);

private:
	float y = 100, // Координата y игрока
          dy = 0, // Координата смещения
          h = 200; // Высота экрана
    // Вектор с платформами
    std::vector<std::pair<int, int>> platforms;
};

