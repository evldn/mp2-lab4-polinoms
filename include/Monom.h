#pragma once
#include "List.h"
#include <cstdlib>
#include <sstream>
#include <string>

const int MAX_POWER = 29;

struct Monom {
	double coef;
	int conv;
	Monom(double coef = 1.0, int x = 0, int y = 0, int z = 0);
	Monom(const Monom& m);
	Monom& operator=(const Monom& m);
	int getX()const { return ((conv / 1) % MAX_POWER) - 10; }
	int getY()const { return ((conv / MAX_POWER) % MAX_POWER) - 10; }
	int getZ()const { return ((conv / (MAX_POWER * MAX_POWER)) % MAX_POWER) - 10; }

	bool operator==(const Monom& m);
	bool operator!=(const Monom& m);
	bool operator<(const Monom& m);
	bool operator>(const Monom& m);
	friend istream& operator >> (istream& in, Monom& m);
	friend ostream& operator << (ostream& out, const Monom& m);
};