#include "doodle_game_application.h"
#include "process.h"
#include <SFML/Graphics.hpp>
#include <time.h>

namespace {
    // ��������� ����
    sf::RenderWindow app(sf::VideoMode(400, 533), "Doodle Jump");
}

// ������� �������� ����
int GameApplication::run()
{
    {
        srand(time(0));
        app.setFramerateLimit(60);

        // ����������: x, y, h - ���������� ��������, dx, dy - ���������� ������
        float x = 100, y = 100, h = 200;
        float dx = 0, dy = 0;

        // ���������
        point plat[20];

        Process proc(y, dy, x, plat[20], h);

        // �������� ������� ������� ����, ���������, ������ � �������������� � �������
        sf::Texture t1, t2, t3;
        t1.loadFromFile("images/background.png");
        t2.loadFromFile("images/platform.png");
        t3.loadFromFile("images/doodle.png");
        sf::Sprite sBackground(t1), sPlat(t2), sPers(t3);

        // ����� randomPlatforms - �������� ��������� ��������� ����������
        plat[20] = proc.randomPlatforms();
        
        // ������� ����
        while (app.isOpen())
        {
            // �������� ����
            sf::Event e;
            while (app.pollEvent(e))
            {
                if (e.type == sf::Event::Closed)
                    app.close();
            }

            // �������� ������ - ������� �� ������� �������
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) x += 3;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) x -= 3;

            // ����� ��� ������������ ������������� ������
            auto dy_y = proc.screenScrolling();
            dy = dy_y.first;
            y = dy_y.second;
            
            // ����� newPlatforms - ������� ����� ��������� ����� ����������� ������� �������
            plat[20] = proc.newPlatforms();

            // ����� standOnPlatforms - ��������� ������������ �� ��������
            dy = proc.standOnPlatform();
            
            // ������� ������� ���������
            sPers.setPosition(x, y);

            // ��������� ��������� � ������� ����
            app.draw(sBackground);
            app.draw(sPers);

            // ��������� ��������
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
