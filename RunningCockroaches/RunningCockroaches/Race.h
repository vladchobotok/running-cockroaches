#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Cockroach;

class Race
{
public:
	unsigned getWidth();
	unsigned getHeight();
	unsigned getWinner();
	bool getDead();
	void results(RenderWindow& window, unsigned chosenCockroach);
	void start(RenderWindow &window, vector <Cockroach> cockroach, unsigned numberOfCockroaches);
private:
	const unsigned width = 1800;
	const unsigned height = 900;
};

