#include "process.h"


Process::Process(float n1, float n2, float n4, std::vector<std::pair<int, int>> plats) :
    y(n1),
    platforms()
{
    y = n1;
    dy = n2;
    h = n4;
    platforms = plats;
}

// Метод для постепенного пролистывания экрана
std::pair<float, float> Process::screenScrolling() {
    dy += 0.2;
    y += dy;
    if (y > 500)  dy = -10;
    return {dy, y};
}

// Функция randomPlatforms - придание рандомных координат платформам
void Process::randomPlatforms() {
    for (int i = 0; i < 10; i++)
    {
        platforms[i].first = rand() % 400;
        platforms[i].second = rand() % 533;
    }
    
}

// Метод standOnPlatforms - отработка отталкивания от платформ
float Process::standOnPlatform(float x){
    
    for (int i = 0; i < 10; i++) {
        if ((x + 50 > platforms[i].first) && (x + 20 < platforms[i].first + 68)
            && (y + 70 > platforms[i].second) && (y + 70 < platforms[i].second + 14) && (dy > 0))
        {
            dy = -10;
        }
    }
    return dy;
}

// Функция newPlatforms - создает новые платформы после прохождения прежних игроком
void Process::newPlatforms() {
    if (y < h)
        for (int i = 0; i < 10; i++) {
            {
                y = h;
                platforms[i].second = platforms[i].second - dy;
                if (platforms[i].second > 533) { platforms[i].second = 0; platforms[i].first = rand() % 400; }
            }
        }
}

// Метод drawPlatforms - отрисовка платформ
sf::Sprite Process::drawPlatforms(sf::Sprite sPlat, int i) {
    sPlat.setPosition(platforms[i].first, platforms[i].second);
    return sPlat;
}

