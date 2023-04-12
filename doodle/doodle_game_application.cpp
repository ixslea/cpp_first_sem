#include "doodle_game_application.h"
#include "process.h"
#include <SFML/Graphics.hpp>
#include <time.h>

namespace {
    // Рендеринг окна
    sf::RenderWindow app(sf::VideoMode(400, 533), "Doodle Jump");
}

// Функция процесса игры
int GameApplication::run()
{
    {
        srand(time(0));
        app.setFramerateLimit(60);

        // Переменные: x, y, h - координаты платформ, dx, dy - координаты игрока
        float x = 100, y = 100, h = 200;
        float dx = 0, dy = 0;

        // Платформы
        point plat[20];

        Process proc(y, dy, x, plat[20], h);

        // Загрузка текстур заднего фона, платформы, игрока и преобразование в спрайты
        sf::Texture t1, t2, t3;
        t1.loadFromFile("images/background.png");
        t2.loadFromFile("images/platform.png");
        t3.loadFromFile("images/doodle.png");
        sf::Sprite sBackground(t1), sPlat(t2), sPers(t3);

        // Метод randomPlatforms - придание рандомных координат платформам
        plat[20] = proc.randomPlatforms();
        
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
            
            // Метод newPlatforms - создает новые платформы после прохождения прежних игроком
            plat[20] = proc.newPlatforms();

            // Метод standOnPlatforms - отработка отталкивания от платформ
            dy = proc.standOnPlatform();
            
            // Задание позиции персонажа
            sPers.setPosition(x, y);

            // Отрисовка персонажа и заднего фона
            app.draw(sBackground);
            app.draw(sPers);

            // Отрисовка платформ
            for (int i = 0; i < 10; i++)
            {
                sPlat.setPosition(plat[i].x, plat[i].y);
                app.draw(sPlat);
            }

            app.display();
        }

        return 0;
    }
};
