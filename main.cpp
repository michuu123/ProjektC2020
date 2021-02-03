#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <time.h> 
using namespace std;
sf::RenderWindow window(sf::VideoMode(1920, 1080), "Nasze okno");
class wspolrzedne
{
public:
	float a, b, c;
};
class szescian
{
public:

	wspolrzedne wsp[8];
	std::vector<sf::CircleShape> punkty = std::vector<sf::CircleShape>(8);
	std::vector<sf::ConvexShape> sciany = std::vector<sf::ConvexShape>(6);

	szescian(float xd[3], float wymiary[3])
	{
		float pktx[8], pkty[8], pktz[8];
		pktx[0] = xd[0];
		pkty[0] = xd[1];
		pktz[0] = xd[2];
		pktx[1] = xd[0] + wymiary[0];
		pkty[1] = xd[1];
		pktz[1] = xd[2];
		pktx[2] = xd[0] + wymiary[0];
		pkty[2] = xd[1];
		pktz[2] = xd[2] + wymiary[2];
		pktx[3] = xd[0];
		pkty[3] = xd[1];
		pktz[3] = xd[2] + wymiary[2];
		pktx[4] = xd[0];
		pkty[4] = xd[1] + wymiary[1];
		pktz[4] = xd[2];
		pktx[5] = xd[0] + wymiary[0];
		pkty[5] = xd[1] + wymiary[1];
		pktz[5] = xd[2];
		pktx[6] = xd[0] + wymiary[0];
		pkty[6] = xd[1] + wymiary[1];
		pktz[6] = xd[2] + wymiary[2];
		pktx[7] = xd[0];
		pkty[7] = xd[1] + wymiary[1];
		pktz[7] = xd[2] + wymiary[2];

				
		for (int i = 0; i < 8; i++)
		{
			wsp[i].a = atan2(pktz[i], pktx[i]) * 180 / 3.14;
			//	wsp[i].b = atan2(pkty[i], sqrt(pktz[i] * pktz[i] + pktx[i] * pktx[i])) * 180 / 3.14;
			wsp[i].b = atan2(pkty[i], pktz[i]) * 180 / 3.14;
			wsp[i].c = sqrt(pktz[i] * pktz[i] + pktx[i] * pktx[i] + pkty[i] * pkty[i]);
			cout <<wsp[i].b<< endl;
		}




	}
	void metoda(float xd[3], float wymiary[3])
	{
		float pktx[8], pkty[8], pktz[8];
		pktx[0] = xd[0];
		pkty[0] = xd[1];
		pktz[0] = xd[2];
		pktx[1] = xd[0] + wymiary[0];
		pkty[1] = xd[1];
		pktz[1] = xd[2];
		pktx[2] = xd[0] + wymiary[0];
		pkty[2] = xd[1];
		pktz[2] = xd[2] + wymiary[2];
		pktx[3] = xd[0];
		pkty[3] = xd[1];
		pktz[3] = xd[2] + wymiary[2];
		pktx[4] = xd[0];
		pkty[4] = xd[1] + wymiary[1];
		pktz[4] = xd[2];
		pktx[5] = xd[0] + wymiary[0];
		pkty[5] = xd[1] + wymiary[1];
		pktz[5] = xd[2];
		pktx[6] = xd[0] + wymiary[0];
		pkty[6] = xd[1] + wymiary[1];
		pktz[6] = xd[2] + wymiary[2];
		pktx[7] = xd[0];
		pkty[7] = xd[1] + wymiary[1];
		pktz[7] = xd[2] + wymiary[2];


		for (int i = 0; i < 8; i++)
		{
			wsp[i].a = atan2(pktz[i], pktx[i]) * 180 / 3.14;
			//	wsp[i].b = atan2(pkty[i], sqrt(pktz[i] * pktz[i] + pktx[i] * pktx[i])) * 180 / 3.14;
			wsp[i].b = atan2(pkty[i], pktz[i]) * 180 / 3.14;
			wsp[i].c = sqrt(pktz[i] * pktz[i] + pktx[i] * pktx[i] + pkty[i] * pkty[i]);
			cout << wsp[i].b << endl;
		}




	}

	void rysuj(int x, int y, int typ)
	{
		if (typ == 0)
		{
			for (int i = 0; i < 8; i++)
			{
				punkty[i].setPosition(sin(3.1415 * (x + wsp[i].a) / 180) * wsp[i].c + 960, sin(3.1415 * (y + wsp[i].b) / 180) * wsp[i].c + 540);
				//	punkty[i].setPosition(cos(3.1415 * (y + wsp[i].b) / 180) * wsp[i].c * cos(3.1415 * (x + wsp[i].a) / 180) + 300, sin(3.1415 * (y + wsp[i].b) / 180) * wsp[i].c + 300);
				//  punkty[i].setPosition(cos(3.1415 * (wsp[i].b) / 180) * wsp[i].c * cos(3.1415 * (x + wsp[i].a) / 180) + 300, sin(3.1415 * (y + wsp[i].b) / 180) * wsp[i].c + 300);
				//	punkty[i].setPosition(cos(3.1415 * (wsp[i].b+270) / 180) * wsp[i].c * cos(3.1415 * (x + wsp[i].a) / 180) + 300, (sin(3.1415 * (y + wsp[i].b) / 180) * wsp[i].c)+(cos(3.1415 * (wsp[i].b + 270) / 180) * wsp[i].c * cos(3.1415 * (x + wsp[i].a) / 180))*sin(y*3.1415/180) + 300);
				//	punkty[i].setPosition(cos(wsp[i].b*3.1415/180)*wsp[i].c*cos((x+wsp[i].a)*3.1415/180)+300, sin(3.1415 * (y + wsp[i].b) / 180) * wsp[i].c + 300);
		//			xD.setPoint(i, sf::Vector2f(sin(3.1415 * (x + wsp[i].a) / 180) * wsp[i].c1 + 300, sin(3.1415 * (y + wsp[i].b) / 180) * wsp[i].c2 + 300));
				punkty[i].setRadius(5);
				window.draw(punkty[i]);
			}
			
		}
		if (typ == 3)
		{
			for (int i = 0; i < 6; i++)
			{
				sciany[i].setPointCount(4);
				sciany[i].setOutlineThickness(0);
			}
			sciany[0].setPoint(0, sf::Vector2f(sin(3.1415 * (x + wsp[1].a) / 180) * wsp[1].c + 960, sin(3.1415 * (y + wsp[1].b) / 180) * wsp[1].c + 540));
			sciany[0].setPoint(1, sf::Vector2f(sin(3.1415 * (x + wsp[2].a) / 180) * wsp[2].c + 960, sin(3.1415 * (y + wsp[2].b) / 180) * wsp[2].c + 540));
			sciany[0].setPoint(2, sf::Vector2f(sin(3.1415 * (x + wsp[6].a) / 180) * wsp[6].c + 960, sin(3.1415 * (y + wsp[6].b) / 180) * wsp[6].c + 540));
			sciany[0].setPoint(3, sf::Vector2f(sin(3.1415 * (x + wsp[5].a) / 180) * wsp[5].c + 960, sin(3.1415 * (y + wsp[5].b) / 180) * wsp[5].c + 540));
			sciany[0].setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, 100));
			window.draw(sciany[0]);

			sciany[1].setPoint(0, sf::Vector2f(sin(3.1415 * (x + wsp[2].a) / 180) * wsp[2].c + 960, sin(3.1415 * (y + wsp[2].b) / 180) * wsp[2].c + 540));
			sciany[1].setPoint(1, sf::Vector2f(sin(3.1415 * (x + wsp[3].a) / 180) * wsp[3].c + 960, sin(3.1415 * (y + wsp[3].b) / 180) * wsp[3].c + 540));
			sciany[1].setPoint(2, sf::Vector2f(sin(3.1415 * (x + wsp[7].a) / 180) * wsp[7].c + 960, sin(3.1415 * (y + wsp[7].b) / 180) * wsp[7].c + 540));
			sciany[1].setPoint(3, sf::Vector2f(sin(3.1415 * (x + wsp[6].a) / 180) * wsp[6].c + 960, sin(3.1415 * (y + wsp[6].b) / 180) * wsp[6].c + 540));
			sciany[1].setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, 100));
			window.draw(sciany[1]);

			sciany[2].setPoint(0, sf::Vector2f(sin(3.1415 * (x + wsp[0].a) / 180) * wsp[0].c + 960, sin(3.1415 * (y + wsp[0].b) / 180) * wsp[0].c + 540));
			sciany[2].setPoint(1, sf::Vector2f(sin(3.1415 * (x + wsp[1].a) / 180) * wsp[1].c + 960, sin(3.1415 * (y + wsp[1].b) / 180) * wsp[1].c + 540));
			sciany[2].setPoint(2, sf::Vector2f(sin(3.1415 * (x + wsp[5].a) / 180) * wsp[5].c + 960, sin(3.1415 * (y + wsp[5].b) / 180) * wsp[5].c + 540));
			sciany[2].setPoint(3, sf::Vector2f(sin(3.1415 * (x + wsp[4].a) / 180) * wsp[4].c + 960, sin(3.1415 * (y + wsp[4].b) / 180) * wsp[4].c + 540));
			sciany[2].setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, 100));
			window.draw(sciany[2]);

			sciany[3].setPoint(0, sf::Vector2f(sin(3.1415 * (x + wsp[3].a) / 180) * wsp[3].c + 960, sin(3.1415 * (y + wsp[3].b) / 180) * wsp[3].c + 540));
			sciany[3].setPoint(1, sf::Vector2f(sin(3.1415 * (x + wsp[0].a) / 180) * wsp[0].c + 960, sin(3.1415 * (y + wsp[0].b) / 180) * wsp[0].c + 540));
			sciany[3].setPoint(2, sf::Vector2f(sin(3.1415 * (x + wsp[4].a) / 180) * wsp[4].c + 960, sin(3.1415 * (y + wsp[4].b) / 180) * wsp[4].c + 540));
			sciany[3].setPoint(3, sf::Vector2f(sin(3.1415 * (x + wsp[7].a) / 180) * wsp[7].c + 960, sin(3.1415 * (y + wsp[7].b) / 180) * wsp[7].c + 540));
			sciany[3].setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, 100));
			window.draw(sciany[3]);

			sciany[4].setPoint(0, sf::Vector2f(sin(3.1415 * (x + wsp[0].a) / 180) * wsp[0].c + 960, sin(3.1415 * (y + wsp[0].b) / 180) * wsp[0].c + 540));
			sciany[4].setPoint(1, sf::Vector2f(sin(3.1415 * (x + wsp[1].a) / 180) * wsp[1].c + 960, sin(3.1415 * (y + wsp[1].b) / 180) * wsp[1].c + 540));
			sciany[4].setPoint(2, sf::Vector2f(sin(3.1415 * (x + wsp[2].a) / 180) * wsp[2].c + 960, sin(3.1415 * (y + wsp[2].b) / 180) * wsp[2].c + 540));
			sciany[4].setPoint(3, sf::Vector2f(sin(3.1415 * (x + wsp[3].a) / 180) * wsp[3].c + 960, sin(3.1415 * (y + wsp[3].b) / 180) * wsp[3].c + 540));
			sciany[4].setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, 100));
			window.draw(sciany[4]);

			sciany[5].setPoint(0, sf::Vector2f(sin(3.1415 * (x + wsp[4].a) / 180) * wsp[4].c + 960, sin(3.1415 * (y + wsp[4].b) / 180) * wsp[4].c + 540));
			sciany[5].setPoint(1, sf::Vector2f(sin(3.1415 * (x + wsp[5].a) / 180) * wsp[5].c + 960, sin(3.1415 * (y + wsp[5].b) / 180) * wsp[5].c + 540));
			sciany[5].setPoint(2, sf::Vector2f(sin(3.1415 * (x + wsp[6].a) / 180) * wsp[6].c + 960, sin(3.1415 * (y + wsp[6].b) / 180) * wsp[6].c + 540));
			sciany[5].setPoint(3, sf::Vector2f(sin(3.1415 * (x + wsp[7].a) / 180) * wsp[7].c + 960, sin(3.1415 * (y + wsp[7].b) / 180) * wsp[7].c + 540));
			sciany[5].setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, 100));
			window.draw(sciany[5]);
		}
		if (typ == 1)
		{
			for (int i = 0; i < 6; i++)
			{
				sciany[i].setPointCount(4);
			}
			sciany[0].setPoint(0, sf::Vector2f(sin(3.1415 * (x + wsp[1].a) / 180) * wsp[1].c + 960, sin(3.1415 * (y + wsp[1].b) / 180) * wsp[1].c + 540));
			sciany[0].setPoint(1, sf::Vector2f(sin(3.1415 * (x + wsp[2].a) / 180) * wsp[2].c + 960, sin(3.1415 * (y + wsp[2].b) / 180) * wsp[2].c + 540));
			sciany[0].setPoint(2, sf::Vector2f(sin(3.1415 * (x + wsp[6].a) / 180) * wsp[6].c + 960, sin(3.1415 * (y + wsp[6].b) / 180) * wsp[6].c + 540));
			sciany[0].setPoint(3, sf::Vector2f(sin(3.1415 * (x + wsp[5].a) / 180) * wsp[5].c + 960, sin(3.1415 * (y + wsp[5].b) / 180) * wsp[5].c + 540));
			sciany[0].setFillColor(sf::Color(0, 0, 0, 0));
			sciany[0].setOutlineThickness(1);
			sciany[0].setOutlineColor(sf::Color(255, 255, 255));
			window.draw(sciany[0]);

			sciany[1].setPoint(0, sf::Vector2f(sin(3.1415 * (x + wsp[2].a) / 180) * wsp[2].c + 960, sin(3.1415 * (y + wsp[2].b) / 180) * wsp[2].c + 540));
			sciany[1].setPoint(1, sf::Vector2f(sin(3.1415 * (x + wsp[3].a) / 180) * wsp[3].c + 960, sin(3.1415 * (y + wsp[3].b) / 180) * wsp[3].c + 540));
			sciany[1].setPoint(2, sf::Vector2f(sin(3.1415 * (x + wsp[7].a) / 180) * wsp[7].c + 960, sin(3.1415 * (y + wsp[7].b) / 180) * wsp[7].c + 540));
			sciany[1].setPoint(3, sf::Vector2f(sin(3.1415 * (x + wsp[6].a) / 180) * wsp[6].c + 960, sin(3.1415 * (y + wsp[6].b) / 180) * wsp[6].c + 540));
			sciany[1].setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, 100));
			sciany[1].setFillColor(sf::Color(0, 0, 0, 0));
			sciany[1].setOutlineThickness(1);
			sciany[1].setOutlineColor(sf::Color(255, 255, 255));
			window.draw(sciany[1]);

			sciany[2].setPoint(0, sf::Vector2f(sin(3.1415 * (x + wsp[0].a) / 180) * wsp[0].c + 960, sin(3.1415 * (y + wsp[0].b) / 180) * wsp[0].c + 540));
			sciany[2].setPoint(1, sf::Vector2f(sin(3.1415 * (x + wsp[1].a) / 180) * wsp[1].c + 960, sin(3.1415 * (y + wsp[1].b) / 180) * wsp[1].c + 540));
			sciany[2].setPoint(2, sf::Vector2f(sin(3.1415 * (x + wsp[5].a) / 180) * wsp[5].c + 960, sin(3.1415 * (y + wsp[5].b) / 180) * wsp[5].c + 540));
			sciany[2].setPoint(3, sf::Vector2f(sin(3.1415 * (x + wsp[4].a) / 180) * wsp[4].c + 960, sin(3.1415 * (y + wsp[4].b) / 180) * wsp[4].c + 540));
			sciany[2].setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, 100));
			sciany[2].setFillColor(sf::Color(0, 0, 0, 0));
			sciany[2].setOutlineThickness(1);
			sciany[2].setOutlineColor(sf::Color(255, 255, 255));
			window.draw(sciany[2]);

			sciany[3].setPoint(0, sf::Vector2f(sin(3.1415 * (x + wsp[3].a) / 180) * wsp[3].c + 960, sin(3.1415 * (y + wsp[3].b) / 180) * wsp[3].c + 540));
			sciany[3].setPoint(1, sf::Vector2f(sin(3.1415 * (x + wsp[0].a) / 180) * wsp[0].c + 960, sin(3.1415 * (y + wsp[0].b) / 180) * wsp[0].c + 540));
			sciany[3].setPoint(2, sf::Vector2f(sin(3.1415 * (x + wsp[4].a) / 180) * wsp[4].c + 960, sin(3.1415 * (y + wsp[4].b) / 180) * wsp[4].c + 540));
			sciany[3].setPoint(3, sf::Vector2f(sin(3.1415 * (x + wsp[7].a) / 180) * wsp[7].c + 960, sin(3.1415 * (y + wsp[7].b) / 180) * wsp[7].c + 540));
			sciany[3].setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, 100));
			sciany[3].setFillColor(sf::Color(0, 0, 0, 0));
			sciany[3].setOutlineThickness(1);
			sciany[3].setOutlineColor(sf::Color(255, 255, 255));
			window.draw(sciany[3]);

			sciany[4].setPoint(0, sf::Vector2f(sin(3.1415 * (x + wsp[0].a) / 180) * wsp[0].c + 960, sin(3.1415 * (y + wsp[0].b) / 180) * wsp[0].c + 540));
			sciany[4].setPoint(1, sf::Vector2f(sin(3.1415 * (x + wsp[1].a) / 180) * wsp[1].c + 960, sin(3.1415 * (y + wsp[1].b) / 180) * wsp[1].c + 540));
			sciany[4].setPoint(2, sf::Vector2f(sin(3.1415 * (x + wsp[2].a) / 180) * wsp[2].c + 960, sin(3.1415 * (y + wsp[2].b) / 180) * wsp[2].c + 540));
			sciany[4].setPoint(3, sf::Vector2f(sin(3.1415 * (x + wsp[3].a) / 180) * wsp[3].c + 960, sin(3.1415 * (y + wsp[3].b) / 180) * wsp[3].c + 540));
			sciany[4].setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, 100));
			sciany[4].setFillColor(sf::Color(0, 0, 0, 0));
			sciany[4].setOutlineThickness(1);
			sciany[4].setOutlineColor(sf::Color(255, 255, 255));
			window.draw(sciany[4]);

			sciany[5].setPoint(0, sf::Vector2f(sin(3.1415 * (x + wsp[4].a) / 180) * wsp[4].c + 960, sin(3.1415 * (y + wsp[4].b) / 180) * wsp[4].c + 540));
			sciany[5].setPoint(1, sf::Vector2f(sin(3.1415 * (x + wsp[5].a) / 180) * wsp[5].c + 960, sin(3.1415 * (y + wsp[5].b) / 180) * wsp[5].c + 540));
			sciany[5].setPoint(2, sf::Vector2f(sin(3.1415 * (x + wsp[6].a) / 180) * wsp[6].c + 960, sin(3.1415 * (y + wsp[6].b) / 180) * wsp[6].c + 540));
			sciany[5].setPoint(3, sf::Vector2f(sin(3.1415 * (x + wsp[7].a) / 180) * wsp[7].c + 960, sin(3.1415 * (y + wsp[7].b) / 180) * wsp[7].c + 540));
			sciany[5].setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, 100));
			sciany[5].setFillColor(sf::Color(0, 0, 0, 0));
			sciany[5].setOutlineThickness(1);
			sciany[5].setOutlineColor(sf::Color(255, 255, 255));
			window.draw(sciany[5]);
		}

		if (typ == 2)
		{
			for (int i = 0; i < 6; i++)
			{
				sciany[i].setPointCount(4);
				sciany[i].setOutlineThickness(0);
			}
			sciany[0].setPoint(0, sf::Vector2f(sin(3.1415 * (x + wsp[1].a) / 180) * wsp[1].c + 960, sin(3.1415 * (y + wsp[1].b) / 180) * wsp[1].c + 540));
			sciany[0].setPoint(1, sf::Vector2f(sin(3.1415 * (x + wsp[2].a) / 180) * wsp[2].c + 960, sin(3.1415 * (y + wsp[2].b) / 180) * wsp[2].c + 540));
			sciany[0].setPoint(2, sf::Vector2f(sin(3.1415 * (x + wsp[6].a) / 180) * wsp[6].c + 960, sin(3.1415 * (y + wsp[6].b) / 180) * wsp[6].c + 540));
			sciany[0].setPoint(3, sf::Vector2f(sin(3.1415 * (x + wsp[5].a) / 180) * wsp[5].c + 960, sin(3.1415 * (y + wsp[5].b) / 180) * wsp[5].c + 540));
			sciany[0].setFillColor(sf::Color(0, 200, 200, 100));
			window.draw(sciany[0]);

			sciany[1].setPoint(0, sf::Vector2f(sin(3.1415 * (x + wsp[2].a) / 180) * wsp[2].c + 960, sin(3.1415 * (y + wsp[2].b) / 180) * wsp[2].c + 540));
			sciany[1].setPoint(1, sf::Vector2f(sin(3.1415 * (x + wsp[3].a) / 180) * wsp[3].c + 960, sin(3.1415 * (y + wsp[3].b) / 180) * wsp[3].c + 540));
			sciany[1].setPoint(2, sf::Vector2f(sin(3.1415 * (x + wsp[7].a) / 180) * wsp[7].c + 960, sin(3.1415 * (y + wsp[7].b) / 180) * wsp[7].c + 540));
			sciany[1].setPoint(3, sf::Vector2f(sin(3.1415 * (x + wsp[6].a) / 180) * wsp[6].c + 960, sin(3.1415 * (y + wsp[6].b) / 180) * wsp[6].c + 540));
			sciany[1].setFillColor(sf::Color(0, 255, 100, 100));
			window.draw(sciany[1]);

			sciany[2].setPoint(0, sf::Vector2f(sin(3.1415 * (x + wsp[0].a) / 180) * wsp[0].c + 960, sin(3.1415 * (y + wsp[0].b) / 180) * wsp[0].c + 540));
			sciany[2].setPoint(1, sf::Vector2f(sin(3.1415 * (x + wsp[1].a) / 180) * wsp[1].c + 960, sin(3.1415 * (y + wsp[1].b) / 180) * wsp[1].c + 540));
			sciany[2].setPoint(2, sf::Vector2f(sin(3.1415 * (x + wsp[5].a) / 180) * wsp[5].c + 960, sin(3.1415 * (y + wsp[5].b) / 180) * wsp[5].c + 540));
			sciany[2].setPoint(3, sf::Vector2f(sin(3.1415 * (x + wsp[4].a) / 180) * wsp[4].c + 960, sin(3.1415 * (y + wsp[4].b) / 180) * wsp[4].c + 540));
			sciany[2].setFillColor(sf::Color(0,255,150,100));
			window.draw(sciany[2]);

			sciany[3].setPoint(0, sf::Vector2f(sin(3.1415 * (x + wsp[3].a) / 180) * wsp[3].c + 960, sin(3.1415 * (y + wsp[3].b) / 180) * wsp[3].c + 540));
			sciany[3].setPoint(1, sf::Vector2f(sin(3.1415 * (x + wsp[0].a) / 180) * wsp[0].c + 960, sin(3.1415 * (y + wsp[0].b) / 180) * wsp[0].c + 540));
			sciany[3].setPoint(2, sf::Vector2f(sin(3.1415 * (x + wsp[4].a) / 180) * wsp[4].c + 960, sin(3.1415 * (y + wsp[4].b) / 180) * wsp[4].c + 540));
			sciany[3].setPoint(3, sf::Vector2f(sin(3.1415 * (x + wsp[7].a) / 180) * wsp[7].c + 960, sin(3.1415 * (y + wsp[7].b) / 180) * wsp[7].c + 540));
			sciany[3].setFillColor(sf::Color(0,100,255,100));
			window.draw(sciany[3]);

			sciany[4].setPoint(0, sf::Vector2f(sin(3.1415 * (x + wsp[0].a) / 180) * wsp[0].c + 960, sin(3.1415 * (y + wsp[0].b) / 180) * wsp[0].c + 540));
			sciany[4].setPoint(1, sf::Vector2f(sin(3.1415 * (x + wsp[1].a) / 180) * wsp[1].c + 960, sin(3.1415 * (y + wsp[1].b) / 180) * wsp[1].c + 540));
			sciany[4].setPoint(2, sf::Vector2f(sin(3.1415 * (x + wsp[2].a) / 180) * wsp[2].c + 960, sin(3.1415 * (y + wsp[2].b) / 180) * wsp[2].c + 540));
			sciany[4].setPoint(3, sf::Vector2f(sin(3.1415 * (x + wsp[3].a) / 180) * wsp[3].c + 960, sin(3.1415 * (y + wsp[3].b) / 180) * wsp[3].c + 540));
			sciany[4].setFillColor(sf::Color(0,230,200,100));
			window.draw(sciany[4]);

			sciany[5].setPoint(0, sf::Vector2f(sin(3.1415 * (x + wsp[4].a) / 180) * wsp[4].c + 960, sin(3.1415 * (y + wsp[4].b) / 180) * wsp[4].c + 540));
			sciany[5].setPoint(1, sf::Vector2f(sin(3.1415 * (x + wsp[5].a) / 180) * wsp[5].c + 960, sin(3.1415 * (y + wsp[5].b) / 180) * wsp[5].c + 540));
			sciany[5].setPoint(2, sf::Vector2f(sin(3.1415 * (x + wsp[6].a) / 180) * wsp[6].c + 960, sin(3.1415 * (y + wsp[6].b) / 180) * wsp[6].c + 540));
			sciany[5].setPoint(3, sf::Vector2f(sin(3.1415 * (x + wsp[7].a) / 180) * wsp[7].c + 960, sin(3.1415 * (y + wsp[7].b) / 180) * wsp[7].c + 540));
			sciany[5].setFillColor(sf::Color(0,150,150,100));
			window.draw(sciany[5]);
		}

//		cout << y << endl;

		/*	sciany[0].setPoint(0, sf::Vector2f(sin(3.1415 * (x + wsp[0].a) / 180) * wsp[0].c1 + 300, sin(3.1415 * (y + wsp[0].b) / 180) * wsp[0].c2 + 300));
			sciany[0].setPoint(1, sf::Vector2f(sin(3.1415 * (x + wsp[1].a) / 180) * wsp[1].c1 + 300, sin(3.1415 * (y + wsp[1].b) / 180) * wsp[1].c2 + 300));
			sciany[0].setPoint(2, sf::Vector2f(sin(3.1415 * (x + wsp[2].a) / 180) * wsp[2].c1 + 300, sin(3.1415 * (y + wsp[2].b) / 180) * wsp[2].c2 + 300));
			sciany[0].setPoint(3, sf::Vector2f(sin(3.1415 * (x + wsp[3].a) / 180) * wsp[3].c1 + 300, sin(3.1415 * (y + wsp[3].b) / 180) * wsp[3].c2 + 300));
			sciany[0].setFillColor(sf::Color(100, 100, 100, 255));
			window.draw(sciany[0]);

			sciany[1].setPoint(0, sf::Vector2f(sin(3.1415 * (x + wsp[2].a) / 180) * wsp[2].c1 + 300, sin(3.1415 * (y + wsp[2].b) / 180) * wsp[2].c2 + 300));
			sciany[1].setPoint(1, sf::Vector2f(sin(3.1415 * (x + wsp[3].a) / 180) * wsp[3].c1 + 300, sin(3.1415 * (y + wsp[3].b) / 180) * wsp[3].c2 + 300));
			sciany[1].setPoint(2, sf::Vector2f(sin(3.1415 * (x + wsp[7].a) / 180) * wsp[7].c1 + 300, sin(3.1415 * (y + wsp[7].b) / 180) * wsp[7].c2 + 300));
			sciany[1].setPoint(3, sf::Vector2f(sin(3.1415 * (x + wsp[6].a) / 180) * wsp[6].c1 + 300, sin(3.1415 * (y + wsp[6].b) / 180) * wsp[6].c2 + 300));
			sciany[1].setFillColor(sf::Color(200, 200, 200, 255));
			window.draw(sciany[1]);

			sciany[2].setPoint(0, sf::Vector2f(sin(3.1415 * (x + wsp[1].a) / 180) * wsp[1].c1 + 300, sin(3.1415 * (y + wsp[1].b) / 180) * wsp[1].c2 + 300));
			sciany[2].setPoint(1, sf::Vector2f(sin(3.1415 * (x + wsp[2].a) / 180) * wsp[2].c1 + 300, sin(3.1415 * (y + wsp[2].b) / 180) * wsp[2].c2 + 300));
			sciany[2].setPoint(2, sf::Vector2f(sin(3.1415 * (x + wsp[6].a) / 180) * wsp[6].c1 + 300, sin(3.1415 * (y + wsp[6].b) / 180) * wsp[6].c2 + 300));
			sciany[2].setPoint(3, sf::Vector2f(sin(3.1415 * (x + wsp[5].a) / 180) * wsp[5].c1 + 300, sin(3.1415 * (y + wsp[5].b) / 180) * wsp[5].c2 + 300));
			sciany[2].setFillColor(sf::Color(0, 200, 200, 255));
			window.draw(sciany[2]);
		*/

		//		punkty[1].setPosition(sin(3.1415 * (x + wsp[1].a) / 180) * wsp[1].c1 + 300, sin(3.1415 * (y + wsp[1].b) / 180) * wsp[1].c2 + 300);
		//		punkty[1].setRadius(5);
		//		window.draw(punkty[1]);

	}
};
int main()
{
	sf::Texture xm;
	xm.loadFromFile("Xdown.png");
	sf::Sprite xM;
	xM.setTexture(xm);

	sf::Texture xw;
	xw.loadFromFile("Xup.png");
	sf::Sprite xW;
	xW.setTexture(xw);

	sf::Texture ym;
	ym.loadFromFile("Ydown.png");
	sf::Sprite yM;
	yM.setTexture(ym);

	sf::Texture yw;
	yw.loadFromFile("Yup.png");
	sf::Sprite yW;
	yW.setTexture(yw);

	sf::Texture zm;
	zm.loadFromFile("Zdown.png");
	sf::Sprite zM;
	zM.setTexture(zm);

	sf::Texture zw;
	zw.loadFromFile("Zup.png");
	sf::Sprite zW;
	zW.setTexture(zw);

	sf::Texture punkty;
	punkty.loadFromFile("punkty.png");
	sf::Texture szkielet;
	szkielet.loadFromFile("szkielet.png");
	sf::Texture pelne;
	pelne.loadFromFile("pelne.png");
	sf::Texture disco;
	disco.loadFromFile("disco.png");
	sf::Sprite render;
	render.setTexture(punkty);


	srand(time(NULL));
	float cos[3] = { -100,-100,-100 }, cos1[3] = { 200,200,200 };
	szescian bk(cos, cos1);
	sf::Mouse mouse;
	int myszX = 0, myszY = 0, przsX, przsY, katX = 0, katXp = 0, katY = 0, katYp = 0, renderType=0;
	render.setPosition(sf::Vector2f(50, 50));
	render.setColor(sf::Color(50,50, 50, 255));

	xW.setPosition(sf::Vector2f(120, 120));
	xW.setColor(sf::Color(50, 50, 50, 255));
	xM.setPosition(sf::Vector2f(50, 120));
	xM.setColor(sf::Color(50, 50, 50, 255));
	yW.setPosition(sf::Vector2f(120, 190));
	yW.setColor(sf::Color(50, 50, 50, 255));
	yM.setPosition(sf::Vector2f(50, 190));
	yM.setColor(sf::Color(50, 50, 50, 255));
	zW.setPosition(sf::Vector2f(120, 260));
	zW.setColor(sf::Color(50, 50, 50, 255));
	zM.setPosition(sf::Vector2f(50, 260));
	zM.setColor(sf::Color(50, 50, 50, 255));

	bool guzik;
	float pi = 3.1415;
	srand(time(NULL));
	// create an empty shape
	sf::ConvexShape convex;

	// resize it to 5 points
	convex.setPointCount(5);


	// define the points
	int x[6][4] = { {350,350,250,250},{250,250,250,250},{250,250,350,350},{350,350,350,350} }, y[6][4] = { {250,350,350,250},{250,350,350,250},{250,350,350,250},{250,350,350,250} };
	//tworzenie punktów, [6] oznacza, szeœæ œcian [4] liczbê punktów ka¿dej œciany, mowa o wspó³rzêdnych x, wspó³rzêdne y znajduj¹ siê w kolejnej zmiennej
	convex.setPoint(0, sf::Vector2f(0, 0));
	convex.setPoint(1, sf::Vector2f(150, 10));
	convex.setPoint(2, sf::Vector2f(120, 90));
	convex.setPoint(3, sf::Vector2f(30, 100));
	convex.setPoint(4, sf::Vector2f(0, 50));
	convex.setFillColor(sf::Color(150, 50, 250));

	std::vector<sf::ConvexShape> fejsy(6);
	for (int i = 0; i < 6; i++)
	{
		fejsy[i].setPointCount(4);
	}

	while (window.isOpen())    // dopoki okno jest otwarte...
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			// uzytkownik nacisnal klawisz
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					myszX = mouse.getPosition(window).x;
					myszY = mouse.getPosition(window).y;
					if ((mouse.getPosition(window).x > 50) && (mouse.getPosition(window).x < 170) && (mouse.getPosition(window).y < 100) && (mouse.getPosition(window).y > 50))
					{
						render.setColor(sf::Color(150, 150, 150, 255));
						renderType += 1;
						renderType %= 4;
						if(renderType==0)
							render.setTexture(punkty);
						if (renderType == 1)
							render.setTexture(szkielet);
						if (renderType == 2)
							render.setTexture(pelne);
						if (renderType == 3)
							render.setTexture(disco);

					}
				}
				if ((mouse.getPosition(window).x > 50) && (mouse.getPosition(window).x < 100) && (mouse.getPosition(window).y > 120) && (mouse.getPosition(window).y < 170))
				{
					xM.setColor(sf::Color(150, 150, 150, 255));
					cos1[0] -= 10;
					bk.metoda(cos, cos1);
				}


				if ((mouse.getPosition(window).x > 120) && (mouse.getPosition(window).x < 170) && (mouse.getPosition(window).y > 120) && (mouse.getPosition(window).y < 170))
				{
					xW.setColor(sf::Color(150, 150, 150, 255));
					cos1[0] += 10;
					bk.metoda(cos, cos1);
				}


				if ((mouse.getPosition(window).x > 50) && (mouse.getPosition(window).x < 100) && (mouse.getPosition(window).y > 190) && (mouse.getPosition(window).y < 240))
				{
					yM.setColor(sf::Color(150, 150, 150, 255));
					cos1[1] -= 10;
					bk.metoda(cos, cos1);
				}


				if ((mouse.getPosition(window).x > 120) && (mouse.getPosition(window).x < 170) && (mouse.getPosition(window).y > 190) && (mouse.getPosition(window).y < 240))
				{
					cos1[1] += 10;
					bk.metoda(cos, cos1);
				}


				if ((mouse.getPosition(window).x > 50) && (mouse.getPosition(window).x < 100) && (mouse.getPosition(window).y > 260) && (mouse.getPosition(window).y < 300))
				{
					cos1[2] -= 10;
					bk.metoda(cos, cos1);
				}


				if ((mouse.getPosition(window).x > 120) && (mouse.getPosition(window).x < 170) && (mouse.getPosition(window).y > 260) && (mouse.getPosition(window).y < 300))
				{
					cos1[2] += 10;
					bk.metoda(cos, cos1);
				}


			}
			if (event.type == sf::Event::MouseButtonReleased)
			{
				katXp = (katXp + mouse.getPosition(window).x - myszX) % 360;
				katYp = (katYp + mouse.getPosition(window).y - myszY) % 360;
			}


		}
		if (mouse.isButtonPressed(mouse.Left))
		{
			katX = (katXp + mouse.getPosition(window).x - myszX) % 360;
			if (katX < 0)
			{
				katX = katX + 360;
			}
			katY = (katYp + mouse.getPosition(window).y - myszY) % 360;
			if (katY < 0)
			{
				katY = katY + 360;
			}

			//cout << sin(katX * pi * 2 / 360) << endl;
			//cout << katY << endl;
			przsX = (mouse.getPosition(window).x - myszX);
			przsY = (mouse.getPosition(window).y - myszY);
		}
		/*		for (int i = 0; i < 6; i++)
				{
					fejsy[i].setFillColor(sf::Color(i * 40, i * 20, 100, 255));
					if ((katX > 315) || (katX < 135))
					{
						window.draw(fejsy[0]);
					}
					if ((katX > 45) && (katX < 225))
					{
						window.draw(fejsy[1]);
					}

					if ((katX > 135) && (katX < 315))
					{
						window.draw(fejsy[2]);
					}

					if ((katX > 225) || (katX < 45))
					{
						window.draw(fejsy[3]);
					}

				}
		*/

		if ((mouse.getPosition(window).x > 50) && (mouse.getPosition(window).x < 170) && (mouse.getPosition(window).y < 100) && (mouse.getPosition(window).y > 50))
		{
			if (mouse.isButtonPressed(mouse.Left));
			else
				render.setColor(sf::Color(100, 100, 100, 255));
		}
		else
		{
			render.setColor(sf::Color(50, 50, 50, 255));
		}
		

		if ((mouse.getPosition(window).x > 50) && (mouse.getPosition(window).x < 100) && (mouse.getPosition(window).y > 120) && (mouse.getPosition(window).y < 170))
		{
			if (mouse.isButtonPressed(mouse.Left));
			else
				xM.setColor(sf::Color(100, 100, 100, 255));
		}
		else
		{
			xM.setColor(sf::Color(50, 50, 50, 255));
		}
		

		if ((mouse.getPosition(window).x > 120) && (mouse.getPosition(window).x < 170) && (mouse.getPosition(window).y > 120) && (mouse.getPosition(window).y < 170))
		{
			if (mouse.isButtonPressed(mouse.Left));
			else
				xW.setColor(sf::Color(100, 100, 100, 255));
		}
		else
		{
			xW.setColor(sf::Color(50, 50, 50, 255));
		}
		

		if ((mouse.getPosition(window).x > 50) && (mouse.getPosition(window).x < 100) && (mouse.getPosition(window).y > 190) && (mouse.getPosition(window).y < 240))
		{
			if (mouse.isButtonPressed(mouse.Left));
			else
				yM.setColor(sf::Color(100, 100, 100, 255));
		}
		else
		{
			yM.setColor(sf::Color(50, 50, 50, 255));
		}


		if ((mouse.getPosition(window).x > 120) && (mouse.getPosition(window).x < 170) && (mouse.getPosition(window).y > 190) && (mouse.getPosition(window).y < 240))
		{
			if (mouse.isButtonPressed(mouse.Left));
			else
				yW.setColor(sf::Color(100, 100, 100, 255));
		}
		else
		{
			yW.setColor(sf::Color(50, 50, 50, 255));
		}
		

		if ((mouse.getPosition(window).x > 50) && (mouse.getPosition(window).x < 100) && (mouse.getPosition(window).y > 260) && (mouse.getPosition(window).y < 300))
		{
			if (mouse.isButtonPressed(mouse.Left));
			else
				zM.setColor(sf::Color(100, 100, 100, 255));
		}
		else
		{
			zM.setColor(sf::Color(50, 50, 50, 255));
		}


		if ((mouse.getPosition(window).x > 120) && (mouse.getPosition(window).x < 170) && (mouse.getPosition(window).y > 260) && (mouse.getPosition(window).y < 300))
		{
			if (mouse.isButtonPressed(mouse.Left));
			else
				zW.setColor(sf::Color(100, 100, 100, 255));
		}
		else
		{
			zW.setColor(sf::Color(50, 50, 50, 255));
		}

		// czyszczenie (na czarno)  
		window.display();
		window.clear(sf::Color::Black);
		bk.rysuj(katX, katY,renderType);
		window.draw(render);

		window.draw(xW);
		window.draw(xM);
		window.draw(yW);
		window.draw(yM);
		window.draw(zW);
		window.draw(zM);
		


	}
	return 0;
}