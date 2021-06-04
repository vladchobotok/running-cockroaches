#include "Race.h"
#include "Cockroach.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;
using namespace sf;

class Cockroach;

struct CockroachInfo
{
	Sprite first;
	Sprite second;
	double x;
	double y;
};

vector <pair<Texture, Texture>> texturesOfCockroaches;
vector <CockroachInfo> imagesOfCockroaches;
unsigned finished = 0;
unsigned dead = 0;
bool isWinner = false;
bool areDead = false;
unsigned winner;

unsigned Race::getWidth()
{
	return this->width;
}

unsigned Race::getHeight()
{
	return this->height;
}

unsigned Race::getWinner()
{
	return winner;
}

bool Race::getDead()
{
	return areDead;
}

void drawCockroaches(RenderWindow& window, vector <Cockroach> cockroaches, unsigned numberOfCockroaches, unsigned shape)
{
	for (int i = 0; i < numberOfCockroaches; ++i)
	{
		
		if ((imagesOfCockroaches[i].x + cockroaches[i].getSpeed()) >= 1600 && imagesOfCockroaches[i].x != 1600)
		{
			if (isWinner == false)
			{
				isWinner = true;
				winner = i;
			}
			++finished;
			imagesOfCockroaches[i].x = 1600;
		}
		else if (imagesOfCockroaches[i].x < 1600)
		{
			imagesOfCockroaches[i].x += cockroaches[i].getSpeed();
		}
		if (shape == 1)
		{
			imagesOfCockroaches[i].first.setPosition(imagesOfCockroaches[i].x, imagesOfCockroaches[i].y);
			window.draw(imagesOfCockroaches[i].first);
		}
		else
		{
			imagesOfCockroaches[i].second.setPosition(imagesOfCockroaches[i].x, imagesOfCockroaches[i].y);
			window.draw(imagesOfCockroaches[i].second);
		}
		
	}
}

void makeACockroach(unsigned numberOfLegs, vector <Cockroach> cockroaches, unsigned i)
{
	CockroachInfo c = { Sprite(texturesOfCockroaches[cockroaches[i].getLegs()].first), Sprite(texturesOfCockroaches[cockroaches[i].getLegs()].second), 0.0, 0.0 };
	imagesOfCockroaches.push_back(c);
}

void Race::start(RenderWindow& window, vector <Cockroach> cockroaches, unsigned numberOfCockroaches)
{
	Music music;
	music.openFromFile("Musica.wav");
	music.play();
	music.setVolume(10);

	srand(time(0));

	window.setFramerateLimit(60);
	
	Texture body1, body2, map2, map3, map4, map5;

	vector <Sprite> maps;
	
	
	map2.loadFromFile("map2.jpg");
	maps.push_back(Sprite(map2));
	map3.loadFromFile("map3.jpg");
	maps.push_back(Sprite(map3));	
	map4.loadFromFile("map4.jpg");
	maps.push_back(Sprite(map4));
	map5.loadFromFile("map5.jpg");
	maps.push_back(Sprite(map5));
	
	maps[numberOfCockroaches - 2].setPosition(0.0, 0.0);

	body1.loadFromFile("Body0.png");
	body2.loadFromFile("Body0.png");
	texturesOfCockroaches.push_back(make_pair(body1, body2));
	body1.loadFromFile("Body1_2.png");
	body2.loadFromFile("Body1_1.png");
	texturesOfCockroaches.push_back(make_pair(body1, body2));
	body1.loadFromFile("Body2_2.png");
	body2.loadFromFile("Body2_1.png");
	texturesOfCockroaches.push_back(make_pair(body1, body2));
	body1.loadFromFile("Body3_2.png");
	body2.loadFromFile("Body3_1.png");
	texturesOfCockroaches.push_back(make_pair(body1, body2));
	body1.loadFromFile("Body4_2.png");
	body2.loadFromFile("Body4_1.png");
	texturesOfCockroaches.push_back(make_pair(body1, body2));
	body1.loadFromFile("Body5_2.png");
	body2.loadFromFile("Body5_1.png");
	texturesOfCockroaches.push_back(make_pair(body1, body2));
	body1.loadFromFile("Body6_2.png");
	body2.loadFromFile("Body6_1.png");
	texturesOfCockroaches.push_back(make_pair(body1, body2));

	for (unsigned i = 0; i < numberOfCockroaches; ++i)
	{
		makeACockroach(cockroaches[i].getLegs(), cockroaches, i);
		imagesOfCockroaches[i].y = this->height / numberOfCockroaches / 2 - 55 + this->height / numberOfCockroaches * i;
		imagesOfCockroaches[i].first.setPosition(0.0, imagesOfCockroaches[i].y);
	}

	unsigned shape = 2;
	finished = 0;
	dead = 0;
	isWinner = false;
	areDead = false;
	
	while (window.isOpen())
	{
		
		Event event;
		while(window.pollEvent(event))
		{			
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear(Color(255, 255, 255));

		window.draw(maps[numberOfCockroaches - 2]);

		if (shape == 2)
			shape = 1;
		else
			shape = 2;

		for (unsigned i = 0; i < numberOfCockroaches; ++i)
		{
			if (rand() % 2000 <= 1 && cockroaches[i].getLegs() != 0 && imagesOfCockroaches[i].x != 1600)
			{
				cockroaches[i].setLegs();
				imagesOfCockroaches[i].first.setTexture(texturesOfCockroaches[cockroaches[i].getLegs()].first);
				imagesOfCockroaches[i].second.setTexture(texturesOfCockroaches[cockroaches[i].getLegs()].second);
				cockroaches[i].setSpeed();
				if (cockroaches[i].getLegs() == 0)
				{
					++finished;
					++dead;
					cockroaches[i].setSpeed(0);
				}
				if (dead == numberOfCockroaches)
				{
					areDead = true;
				}
			}
		}
		
		drawCockroaches(window, cockroaches, numberOfCockroaches, shape);

		window.display();
		if (finished == numberOfCockroaches)
		{
			window.close();
			texturesOfCockroaches.erase(texturesOfCockroaches.begin(), texturesOfCockroaches.end());
			imagesOfCockroaches.erase(imagesOfCockroaches.begin(), imagesOfCockroaches.end());
			maps.erase(maps.begin(), maps.end());
		}
	}
}

void Race::results(RenderWindow& window, unsigned chosenCockroach)
{
	Clock clock;

	Font font;
	font.loadFromFile("font.ttf");

	Text result("", font, 150);
	Text winnerCockroach("", font, 150);
	result.setOutlineColor(Color::White);

	if (winner+1 == 1)
		winnerCockroach.setString("The winner is cockroach #1");
	else if (winner+1 == 2)
		winnerCockroach.setString("The winner is cockroach #2");
	else if (winner+1 == 3)
		winnerCockroach.setString("The winner is cockroach #3");
	else if (winner+1 == 4)
		winnerCockroach.setString("The winner is cockroach #4");
	else if (winner+1 == 5)
		winnerCockroach.setString("The winner is cockroach #5");

	winnerCockroach.setFillColor(Color::Black);

	if (winner+1 != chosenCockroach)
	{
		result.setString("You Lost =(");
		result.setFillColor(Color::Red);
	}
	else
	{
		result.setString("You Won =)");
		result.setFillColor(Color::Green);
	}

	result.setStyle(Text::Bold);
	winnerCockroach.setStyle(Text::Bold);

	View view;

	result.setPosition(view.getCenter().x, view.getCenter().y - 50);
	winnerCockroach.setPosition(120, view.getCenter().y - 300);

	clock.restart();
	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear(Color(200, 200, 200));
		window.draw(winnerCockroach);
		window.draw(result);
		window.display();

		Time time;
		
		time = clock.getElapsedTime();

		if (time.asSeconds() >= 2.0)
		{
			window.close();
		}
	}
}