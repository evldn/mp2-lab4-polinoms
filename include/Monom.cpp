#include "Monom.h"

Monom::Monom(double coef, int x, int y, int z) {
	this->coef = coef;
	conv = (x + 10) + ((y + 10) * MAX_POWER) + ((z + 10) * MAX_POWER * MAX_POWER);
}
Monom::Monom(const Monom& m) {
	coef = m.coef;
	conv = m.conv;
}
Monom& Monom::operator=(const Monom& m) {
	if (&m == this) {
		return *this;
	}
	coef = m.coef;
	conv = m.conv;
	return *this;
}


bool Monom::operator==(const Monom& m) {
	if ((coef == m.coef) && (conv == m.conv))
	{
		return true;
	}
	return false;
}

bool Monom::operator!=(const Monom& m) {
	return !(*this == m);
}
bool Monom::operator<(const Monom& m) {
	if (conv == m.conv)
	{
		if (coef < m.coef) {
			return true;
		}
	}
	else if (conv < m.conv) {
		return true;
	}
	return false;
}
bool Monom::operator>(const Monom& m) {
	if (conv == m.conv)
	{
		if (coef > m.coef) {
			return true;
		}
	}
	else if (conv > m.conv) {
		return true;
	}
	return false;
}

istream& operator >> (istream& in, Monom& m) {
	string str;
	in >> str;

	m.coef = 0;
	int x = 0, y = 0, z = 0;
	int st = 0;
	int prevst = 0;
	bool ch = false;
	string t = "";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '^') {
			t = "";
			continue;
		}
		if (str[i] == 'x') {
			ch = true;
			prevst = st;
			st = 1;
		}
		if (str[i] == 'y') {
			ch = true;
			prevst = st;
			st = 2;
		}
		if (str[i] == 'z') {
			ch = true;
			prevst = st;
			st = 3;
		}
		if (!ch) {
			t += str[i];
		}
		else {
			if (prevst == 0) {
				if (t.size() > 0)
					m.coef = stof(t);
			}
			if (prevst > 0) {
				int pp = pow(MAX_POWER, prevst - 1);
				m.conv += stoi(t) * pp;
			}
			t = "";
			ch = false;
		}
	}
	if (t.size() > 0) {
		if (st == 0) {
			m.coef = stof(t);
		}
		if (st > 0) {
			int pp = pow(MAX_POWER, st - 1);
			m.conv += stoi(t) * pp;
		}
	}
	t = "";
	ch = false;
	return in;
}
ostream& operator << (ostream& out, const Monom& m) {
	double t;
	t = m.coef; 
	if (t != 0) {
		if (t > 0.0) out << "+";
		out << t;
		t = m.getX();
		if (t > 0)
			out << "x^" << t;
		else if (t < 0)
			out << "x^(" << t << ")";
		t = m.getY();
		if (t > 0)
			out << "y^" << t;
		else if (t < 0)
			out << "y^(" << t << ")";
		t = m.getZ();
		if (t > 0)
			out << "z^" << t;
		else if (t < 0)
			out << "z^(" << t << ")";
	}
	else {
		out << "0";
	}
	return out;
}