#include "BettingSystem.h"

BettingSystem::BettingSystem()
{
	this->balance = 1000;
}

void BettingSystem::setBalance(bool iW)
{
	if (iW)
	{
		this->balance += this->bet * (this->numberOfCockroaches - 1);
	}
	else
	{
		this->balance -= this->bet;
	}
}
int BettingSystem::getBalance()
{
	return this->balance;
}

void BettingSystem::setBet(unsigned bet)
{
	this->bet = bet;
}

void BettingSystem::setNumberOfCockroaches(unsigned nOC)
{
	this->numberOfCockroaches = nOC;
}