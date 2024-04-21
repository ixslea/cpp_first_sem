#include "process.h"

Process::Process(float n1, float n2, float n3, point platform, float n4) {
    y = n1;
    dy = n2;
    x = n3;
    plat[20] = platform;
    h = n4;
}

// Метод для постепенного пролистывания экрана
std::pair<float, float> Process::screenScrolling() {
    dy += 0.2;
    y += dy;
    if (y > 500)  dy = -10;
    return {dy, y};
}

// Метод randomPlatforms - придание рандомных координат платформам
point Process::randomPlatforms() {
    for (int i = 0; i < 10; i++)
    {
        plat[i].x = rand() % 400;
        plat[i].y = rand() % 533;
    }
    return plat[20];
}

// Метод standOnPlatforms - отработка отталкивания от платформ
float Process::standOnPlatform() {
    for (int i = 0; i < 10; i++)
        if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68)
            && (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0))  dy = -10;
    return dy;
}

// Метод newPlatforms - создает новые платформы после прохождения прежних игроком
point Process::newPlatforms() {
    if (y < h)
        for (int i = 0; i < 10; i++)
        {
            y = h;
            plat[i].y = plat[i].y - dy;
            if (plat[i].y > 533) { plat[i].y = 0; plat[i].y = rand() % 400; }
        }
    return plat[20];
}


