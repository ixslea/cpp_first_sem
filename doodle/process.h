#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>

// ����������� ��������� ��� ��������, ��� x � y - ���������� ������������
struct point
{
	int x, y;
};

// ����� �������, �������������� � �������� ����
class Process {
public:
	Process(float n1, float n2, float n3, point platform, float n4);

	// ����� ��� ������������ ������������� ������
	std::pair<float, float> screenScrolling();

	// ����� randomPlatforms - �������� ��������� ��������� ����������
	point randomPlatforms();

	// ����� standOnPlatforms - ��������� ������������ �� ��������
	float standOnPlatform();

	// ����� newPlatforms - ������� ����� ��������� ����� ����������� ������� �������
	point newPlatforms();

private:
	float y, dy, x, h;
	point plat[20];
};

