#include "doodle_game_application.h"
#include "process.h"
#include <SFML/Graphics.hpp>
#include <time.h>

namespace {
// Рендеринг окна
sf::RenderWindow app(sf::VideoMode(400, 533), "Doodle Jump");
}

// Метод подготовки: загрузка текстур
std::vector<sf::Texture> GameApplication::preparing()
{
    sf::Texture t1, t2, t3;
    t1.loadFromFile("images/background.png");
    t2.loadFromFile("images/platform.png");
    t3.loadFromFile("images/doodle.png");
    std::vector<sf::Texture> textures = {t1, t2, t3};
    return textures;
}


// Функция процесса игры
int GameApplication::run()
{
    srand(time(0));
    app.setFramerateLimit(60);

    // Переменные: x, y, h - координаты игрока, dx, dy - смещение
    float x = 100, y = 100, h = 200;
    float dx = 0, dy = 0;

    // Платформы
    std::vector<std::pair<int, int>> platforms(10);

    // Экземпляр класса Process
    Process proc(y, dy, h, platforms);

    //Загрузка текстур и создание спрайтов
    std::vector<sf::Texture> textures = preparing();
    sf::Sprite sBackground(textures[0]),
                sPlat(textures[1]),
                sPers(textures[2]);

    // Метод randomPlatforms - придание рандомных координат платформам
    proc.randomPlatforms();
        
    // Процесс игры
    while (app.isOpen())
    {
        // Закрытие игры
        sf::Event e;
        while (app.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                app.close();
        }

        // Движение игрока - реакция на зажатые клавиши
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) x += 3;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) x -= 3;

        // Метод для постепенного пролистывания экрана
        auto dy_y = proc.screenScrolling();
        dy = dy_y.first;
        y = dy_y.second;


        // Функция newPlatforms - создает новые платформы после прохождения прежних игроком
        proc.newPlatforms();

        // Метод standOnPlatforms - отработка отталкивания от платформ
        dy = proc.standOnPlatform(x);
            
        // Задание позиции персонажа
        sPers.setPosition(x, y);

        // Отрисовка персонажа и заднего фона
        app.draw(sBackground);
            

        // Отрисовка платформ
        for (int i = 0; i < 10; i++)
        {
            sPlat = proc.drawPlatforms(sPlat, i);
            app.draw(sPlat);
        }
        app.draw(sPers);
        app.display();
    }

    return 0;
};
