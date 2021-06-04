#pragma once
class Cockroach
{
public:
	Cockroach(unsigned l, unsigned e, unsigned st);
	void setLegs();
	unsigned getLegs();
	unsigned getEyes();
	unsigned getAge();
	void setSpeed();
	void setSpeed(unsigned i);
	double getSpeed();
private:
	double speed;
	int legs;
	unsigned eyes;
	unsigned age;
};

