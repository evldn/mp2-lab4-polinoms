#include "Polinom.h"
#include "Monom.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

//int toConv(int x, int y, int z) {
//	return x + y * MAX_POWER + z * MAX_POWER * MAX_POWER;
//}
//
//void fromConv(int conv, int a[]) {
//	a[0] = (conv / 1) % MAX_POWER;
//	a[1] = (conv / MAX_POWER) % MAX_POWER;
//	a[2] = (conv / (MAX_POWER * MAX_POWER)) % MAX_POWER;
//}

using namespace std;

int main() {
	Polinom p1, p2, p3, p4, p5, p6;
	ifstream f_in("Polinoms_test.txt");
	f_in >> p1;
	cout << "P = " << p1 << endl;
	f_in >> p2;
	cout << "Q = " << p2 << endl;
	p3 = p1 + p2;
	cout << "P + Q = " << p3 << endl << endl;
	
	/*f_in >> p4;
	cout << "R = " << p4 << endl;*/
	
	
	
	
	/*Monom m1(1, 1, 0, 0);
	Monom m2(1, 0, 1, 0);
	List<Monom> monoms1;
	monoms1.AddLast(m1);
	monoms1.AddLast(m2);
	Polinom p1(monoms1);
	cout << p1 << endl;
	Monom m3(1, 1, 0, 0);
	Monom m4(-1, 0, 1, 0);
	List<Monom> monoms2;
	monoms2.AddLast(m3);
	monoms2.AddLast(m4);
	Polinom p2(monoms2);
	cout << p2 << endl;
	Polinom p3;
	p3 = p1 * p2;
	cout << p3;*/

	/*string monom = "12.5x^-10z^5";
	string polinom = "12.5x^10z^5-2.6x^2y^5+10";
	Monom m1;
	istringstream m_in(monom);
	m_in >> m1;
	cout << m1;*/

	/*Polinom p1;
	cin >> p1;
	cout << endl;
	cout << p1;*/

	/*Polinom p1;
	istringstream m_in(monom);
	m_in >> p1;*/
	/*List<Monom> l1;
	List<Monom> l2;
	Monom m1(3, toConv(525));
	Monom m2(-5, toConv(433));
	Monom m3(7, toConv(351));
	Monom m4(-3, toConv(525));
	Monom m5(-6, toConv(218));
	l1.OrderedInsert(m1);
	l1.OrderedInsert(m2);
	l1.OrderedInsert(m3);
	l2.OrderedInsert(m4);
	l2.OrderedInsert(m5);
	Polinom p1(l1);
	Polinom p2(l2);
	cout << p1 << endl;
	cout << p2 << endl;
	Polinom p3;
	p3 = p1 + p2;
	cout << p3;*/
	return 0;
}