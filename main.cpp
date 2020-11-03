#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>
using namespace std;
int main()
{
	sf::Mouse mouse;
	int myszX = 0, myszY = 0, przsX, przsY, katX = 45, katXp = 45;
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
	sf::RenderWindow window(sf::VideoMode(600, 600), "Nasze okno");
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
			}

		}
		if (mouse.isButtonPressed(mouse.Left))
		{
			katX = (katXp + mouse.getPosition(window).x - myszX) % 360;
			if (katX < 0)
			{
				katX = katX+360;
			}
			
			//cout << sin(katX * pi * 2 / 360) << endl;
			cout << katX << endl;
			przsX = (mouse.getPosition(window).x - myszX);
			przsY = (mouse.getPosition(window).y - myszY);
		}
		for (int i = 0; i < 6; i++)
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
		for (int i = 0; i < 6; i++)
		{

			fejsy[i].setPoint(0, sf::Vector2f((x[i][0] - 300) / sin(45 * pi * 2 / 360) * sin(katX * pi * 2 / 360) + 300, y[i][0]));
			fejsy[i].setPoint(1, sf::Vector2f((x[i][0] - 300) / sin(45 * pi * 2 / 360) * sin(katX * pi * 2 / 360) + 300, y[i][1]));
			fejsy[i].setPoint(2, sf::Vector2f((x[i][2] - 300) / sin(45 * pi * 2 / 360) * sin((katX + 90) * pi * 2 / 360) + 300, y[i][2]));
			fejsy[i].setPoint(3, sf::Vector2f((x[i][3] - 300) / sin(45 * pi * 2 / 360) * sin((katX + 90) * pi * 2 / 360) + 300, y[i][3]));
		}


		window.display();
		window.clear(sf::Color::Black);
   
	}
	return 0;
}