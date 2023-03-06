#include "Polinom.h"

Polinom::Polinom(List<Monom> monoms) {
	this->monoms = monoms;
}
Polinom::Polinom(const Polinom& p) {
	monoms = p.monoms;
}
Polinom& Polinom::operator=(const Polinom& p) {
	if (&p == this) {
		return *this;
	}
	monoms.Clear();
	monoms = p.monoms;
	return *this;
}
Polinom Polinom::operator+(Polinom& p) {
	Polinom new_polinom;
	Link<Monom>* current_1 = monoms.getHead()->next;
	Link<Monom>* current_2 = p.monoms.getHead()->next;
	while ((current_1 != monoms.getHead()) && (current_2 != p.monoms.getHead())) {
		if (current_1->value == current_2->value) {
			if (current_1->value.coef + current_2->value.coef != 0) {
				Monom new_monom(current_1->value.coef + current_2->value.coef, current_1->value.conv);
				new_polinom.monoms.AddLast(new_monom);
			}
			current_1 = current_1->next;
			current_2 = current_2->next;
		}
		else if (current_1->value < current_2->value) {
			new_polinom.monoms.AddLast(current_1->value);
			current_1 = current_1->next;
		}
		else if (current_1->value > current_2->value) {
			new_polinom.monoms.AddLast(current_2->value);
			current_2 = current_2->next;
		}
	}
	while (current_1 != monoms.getHead()) {
		new_polinom.monoms.OrderedInsert(current_1->value);
		current_1 = current_1->next;
	}
	while (current_2 != p.monoms.getHead()) {
		new_polinom.monoms.OrderedInsert(current_2->value);
		current_2 = current_2->next;
	}
	return new_polinom;
}

Polinom Polinom::operator*(Polinom& p) {
	Polinom new_polinom;
	for (Link<Monom>* current_1 = monoms.getHead()->next; current_1 != monoms.getHead(); current_1 = current_1->next) {
		for (Link<Monom>* current_2 = p.monoms.getHead()->next; current_2 != p.monoms.getHead(); current_2 = current_2->next) {
			int newx = current_1->value.getX() + current_2->value.getX();
			int newy = current_1->value.getY() + current_2->value.getY();
			int newz = current_1->value.getZ() + current_2->value.getZ();
			int newcoef = current_1->value.coef * current_2->value.coef;
			int newconv = (newx + 10) + ((newy + 10) * MAX_POWER) + ((newz + 10) * MAX_POWER * MAX_POWER);
			int flag = 0;
			for (Link<Monom>* current_3 = new_polinom.monoms.getHead()->next; current_3 != new_polinom.monoms.getHead(); current_3 = current_3->next) {
				if (current_3->value.conv == newconv) {
					current_3->value.coef += newcoef;
					flag = 1;
					break;
				}
			}
			if ((flag == 0) && (newcoef != 0))
			{
				Monom temp(newcoef, newx, newy, newz);
				new_polinom.monoms.AddLast(temp);
			}
			flag = 0;
		}
	}
	return new_polinom;
}

Polinom Polinom::operator*(int value) {
	Polinom new_polinom;
	for (Link<Monom>* current = monoms.getHead()->next; current != monoms.getHead(); current = current->next) {
		if (value != 0) {
			Monom temp(value * current->value.coef, current->value.getX(), current->value.getY(), current->value.getZ());
			new_polinom.monoms.AddLast(temp);
		}
	}
	return new_polinom;
}

Polinom Polinom::operator-(Polinom& p) {
	Polinom temp = p * (- 1);
	return *this + temp;
}


istream& operator >> (istream& in, Polinom& p) {
	string str;
	in >> str;
	string t;
	p.monoms.Clear();
	for (int i = 0; i < str.size(); i++) {
		if ((str[i] == ' ') || (str[i] == '+') || (str[i] == '-')) {
			if ((str[i] == '-') && (str[i-1] == '^')) {
				t += str[i];
				continue;
			}
			if (t.size() > 0) {
				istringstream ss(t);
				Monom m;
				ss >> m;
				p.monoms.AddLast(m);
			}
			t = "";
			if (str[i] == '-') {
				t += str[i];
			}
		}
		else {
			t += str[i];
		}
	}
	if (t.size() > 0) {
		istringstream ss(t);
		Monom m;
		ss >> m;
		p.monoms.AddLast(m);
	}
	t = "";
	return in;
}
ostream& operator << (ostream& out, Polinom& p) {
	Iterator<Monom>* i = p.monoms.Iterator();
	while (i->hasNext()) {
		out << i->Next();
	}
	return out;
}