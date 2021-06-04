#include <iostream>
#include <SFML/Graphics.hpp>
#include "Cockroach.h"
#include "BettingSystem.h"
#include "Race.h"
#include <vector>
#include <ctime>

using namespace std;
using namespace sf;

int main()
{
	srand(time(0));

	vector <Cockroach> cockroaches;
	BettingSystem account;
	Race race;

	int numberOfCockroaches, bet, chosenCockroach;

	cout << "Welcome to the cockroach race!" << endl;
	cout << endl;
	
	while(account.getBalance() > 0)
	{
		cout << "Your account balance: " << account.getBalance() << endl;
		cout << "Make your bet: ";
		cin >> bet;
		account.setBet(bet);

		try
		{
			if (bet < 0)
			{
				throw "Bet cannot be negative";
			}
			if (bet > account.getBalance())
			{
				throw "Bet cannot be higher than your balance";
			}
			cout << "Bet was successful!" << endl;
		}
		catch (const char* exception)
		{
			cerr << "Error: " << exception << endl;
			continue;
		}

		cout << endl;
		cout << "Input your number of cockroaches (min 2 / max 5): ";
		cin >> numberOfCockroaches;
		account.setNumberOfCockroaches(numberOfCockroaches);

		try
		{
			if (numberOfCockroaches < 2 || numberOfCockroaches > 5)
			{
				throw "Choose a number between 2 and 5";
			}
		}
		catch (const char* exception)
		{
			cerr << "Error: " << exception << endl;
			continue;
		}

		vector <unsigned> speedOfCockroach;

		for (unsigned i = 0; i < numberOfCockroaches; ++i)
		{
			cockroaches.push_back(Cockroach(1 + rand() % 6, 1 + rand() % 2, 1 + rand() % 10));
			cockroaches[i].setSpeed();
		}

		cout << endl;
		cout << "Choose your cockroach: ";
		cin >> chosenCockroach;

		try
		{
			if (chosenCockroach <= 0 || chosenCockroach > numberOfCockroaches)
			{
				throw "Choose a cockroach from 1 to your number of cockroaches";
			}			
			cout << "Cockroach was chosen!" << endl;
		}
		catch (const char* exception)
		{
			cerr << "Error: " << exception << endl;
			continue;
		}

		cout << endl << "GO GO GO!" << endl;
		cout << endl;

		RenderWindow window(VideoMode(race.getWidth(), race.getHeight()), "Cockroach race", Style::Default);
		race.start(window, cockroaches, numberOfCockroaches);

		RenderWindow window1(VideoMode(race.getWidth(), race.getHeight()), "Cockroach race", Style::Default);
		race.results(window1, chosenCockroach);

		if (race.getDead() == false)
		{
			cout << "The winner is " << race.getWinner() + 1 << " cockroach!" << endl;
			if(race.getWinner()+1 == chosenCockroach)
			{
				cout << "You won " << bet*(numberOfCockroaches-1) << " hrywnas!" << endl;
				account.setBalance(true);
			}
			else
			{
				cout << "You lost " << bet << " hrywnas!" << endl;
				account.setBalance(false);
			}
		}
		else
		{
			cout << "All cockroaches are dead! No winner today!";
		}
		
		cockroaches.erase(cockroaches.begin(), cockroaches.end());
		cout << endl;
	}

	
	cout << "You lost all your money! Get out from here!";
	cout << endl;
}
