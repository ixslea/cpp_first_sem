#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>

// Специальная структура для платформ, где x и y - координаты расположения
struct point
{
	int x, y;
};

// Класс функций, использующихся в процессе игры
class Process {
public:
	Process(float n1, float n2, float n3, point platform, float n4);

	// Метод для постепенного пролистывания экрана
	std::pair<float, float> screenScrolling();

	// Метод randomPlatforms - придание рандомных координат платформам
	point randomPlatforms();

	// Метод standOnPlatforms - отработка отталкивания от платформ
	float standOnPlatform();

	// Метод newPlatforms - создает новые платформы после прохождения прежних игроком
	point newPlatforms();

private:
	float y, dy, x, h;
	point plat[20];
};

