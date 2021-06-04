#pragma once
class BettingSystem
{
public:
	BettingSystem();
	void setBalance(bool isWinner);
	int getBalance();
	void setBet(unsigned b);
	void setNumberOfCockroaches(unsigned nOC);
private:
	int balance;
	unsigned bet;
	unsigned numberOfCockroaches;
};

