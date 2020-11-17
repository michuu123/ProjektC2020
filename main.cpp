#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>
using namespace std;
sf::RenderWindow window(sf::VideoMode(600, 600), "Nasze okno");
class wspolrzedne
{
	public:
		float a, b, c1, c2;
};
class szescian
{
public:
	
	wspolrzedne wsp[8];
	std::vector<sf::CircleShape> punkty = std::vector<sf::CircleShape>(8);
	std::vector<sf::ConvexShape> sciany = std::vector<sf::ConvexShape>(6);
	
	szescian(float xd[3],float wymiary[3])
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

		for(int i =0;i<8;i++)
		{
			wsp[i].a = atan2(pktx[i], pktz[i]) * 180 / 3.14;
			wsp[i].b = atan2(pkty[i], pktz[i]) * 180 / 3.14;
			wsp[i].c1 = sqrt(pktx[i] * pktx[i] + pktz[i] * pktz[i]);
			wsp[i].c2 = sqrt(pkty[i] * pkty[i] + pktz[i] * pktz[i]);
		}

		
		

	}
	void rysuj(int x, int y)
	{
		for (int i = 0; i < 8; i++)
		{
			punkty[i].setPosition(sin(3.1415 * (x + wsp[i].a) / 180) * wsp[i].c1 + 300, sin(3.1415 * (y + wsp[i].b) / 180) * wsp[i].c2 + 300);
//			xD.setPoint(i, sf::Vector2f(sin(3.1415 * (x + wsp[i].a) / 180) * wsp[i].c1 + 300, sin(3.1415 * (y + wsp[i].b) / 180) * wsp[i].c2 + 300));
			punkty[i].setRadius(5);
			window.draw(punkty[i]);
		}
		for (int i = 0; i < 6; i++)
		{
			sciany[i].setPointCount(4);
		}
		sciany[0].setPoint(0, sf::Vector2f(sin(3.1415 * (x + wsp[0].a) / 180) * wsp[0].c1 + 300, sin(3.1415 * (y + wsp[0].b) / 180) * wsp[0].c2 + 300));
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


//		punkty[1].setPosition(sin(3.1415 * (x + wsp[1].a) / 180) * wsp[1].c1 + 300, sin(3.1415 * (y + wsp[1].b) / 180) * wsp[1].c2 + 300);
//		punkty[1].setRadius(5);
//		window.draw(punkty[1]);
		
	}
};
int main()
{
	
	float cos[3] = { -100,-100,-100 }, cos1[3] = { 200,200,200 };
	szescian bk(cos,cos1);
	sf::Mouse mouse;
	int myszX = 0, myszY = 0, przsX, przsY, katX = 0, katXp = 0, katY = 0, katYp = 0;

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
		for (int i = 0; i < 6; i++)
		{

			fejsy[i].setPoint(0, sf::Vector2f((x[i][0] - 300) / sin(45 * pi * 2 / 360) * sin(katX * pi * 2 / 360) + 300, y[i][0]));
			fejsy[i].setPoint(1, sf::Vector2f((x[i][0] - 300) / sin(45 * pi * 2 / 360) * sin(katX * pi * 2 / 360) + 300, y[i][1]));
			fejsy[i].setPoint(2, sf::Vector2f((x[i][2] - 300) / sin(45 * pi * 2 / 360) * sin((katX + 90) * pi * 2 / 360) + 300, y[i][2]));
			fejsy[i].setPoint(3, sf::Vector2f((x[i][3] - 300) / sin(45 * pi * 2 / 360) * sin((katX + 90) * pi * 2 / 360) + 300, y[i][3]));
		}

		// czyszczenie (na czarno)  
		window.display();
		window.clear(sf::Color::Black);
		bk.rysuj(katX,katY);
		
   
	}
	return 0;
}