#pragma once
#include "Monom.h"

class Polinom {
	List<Monom> monoms;
public:
	Polinom() = default;
	Polinom(List<Monom> monoms);
	Polinom(const Polinom& p);
	Polinom& operator=(const Polinom& p);
	Polinom operator+(Polinom& p);
	Polinom operator*(Polinom& p);
	Polinom operator*(int value);
	Polinom operator-(Polinom& p);
	bool operator==(Polinom& p);
	friend istream& operator >> (istream& in, Polinom& p);
	friend ostream& operator << (ostream& out, Polinom& p);
};

/*c_ijk x^i y^j z^k
s = i*p^0 + j*p^1 + k*p^2
i = (s/p^0)%p
j = (s/p^1)%p
k = (s/p^2)%p
вычитаем -10
1. Полином от 3-х переменных
2. Максимальная степень = 20
3. -10 < i,j,k < 10
4. Читать полиномы из файла, сохранять в файл
5. Сложение, вычитание, умножение полиномов*/