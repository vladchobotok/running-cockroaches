#include "Cockroach.h"
#include <cmath>

Cockroach::Cockroach(unsigned l, unsigned e, unsigned st)
{
	this->legs = l;
	this->eyes = e;
	this->age = st;
}

void Cockroach::setLegs()
{
	this->legs -= 1;
}

unsigned Cockroach::getLegs()
{
	return this->legs;
}

unsigned Cockroach::getEyes()
{
	return this->eyes;
}

unsigned Cockroach::getAge()
{
	return this->age;
}

void Cockroach::setSpeed()
{
	this->speed = this->legs * 3.0 + this->eyes * 2.0 + this->age * 3.0;
	this->speed /= 10.0;
}

void Cockroach::setSpeed(unsigned i)
{
	this->speed = 0.0;
}

double Cockroach::getSpeed()
{
	return this->speed;
}