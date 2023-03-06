#pragma once
#pragma once
#include <iostream>

using namespace std;

template <class T>
struct Link {
	T value;
	Link<T>* next;
	Link(T _value = {}, Link<T>* _next = nullptr) : value(_value), next(_next) {}
};

template <class T>
class Iterator {
public:
	virtual bool hasNext() = 0;
	virtual T Next() = 0;
};

template <class T>
class ListIterator :public Iterator<T> {
	Link<T>* temp;
	Link<T>* head;
public:
	ListIterator(Link<T>* _head) {
		head = _head;
		temp = head->next;
	}
	bool hasNext() { return temp != head; }
	T Next() {
		if (temp == head) throw - 1;
		T value = temp->value;
		temp = temp->next;
		return value;
	}
};

template <class T>
class List {
	Link<T>* head;
	Link<T>* tail;
public:
	List() {
		Link<T>* link = new Link<T>;
		link->next = link;
		head = link;
		tail = link;
	}
	List(const List& list) {
		head = new Link<T>;
		head->next = head;
		tail = head;
		Link<T>* t = list.head->next;
		while (t != list.head) {
			AddLast(t->value);
			t = t->next;
		}
	}
	List& operator=(const List& list) {
		if (this == &list) {
			return *this;
		}
		Clear();
		Link<T>* t = list.head->next;
		while (t != list.head) {
			AddLast(t->value);
			t = t->next;
		}
		return *this;
	}
	void AddFirst(T value) {
		Link<T>* link = new Link<T>(value, head->next);
		if (head->next == head) tail = link;
		head->next = link;
	}
	void AddLast(T value) {
		Link<T>* link = new Link<T>(value, head);
		tail->next = link;
		tail = tail->next;
	}
	void DelFirst() {
		if (head->next == head) throw - 1;
		if (head->next == tail) tail = head;
		Link<T>* link = head->next;
		head->next = link->next;
		delete link;
	}
	void DelLast() {
		if (head->next == head) throw - 1;
		if (head->next == tail) {
			DelFirst();
			return;
		}
		Link<T>* link_1 = tail;
		Link<T>* link_2 = head;
		while (link_2->next != tail) link_2->next;
		link_2->next = head;
		tail = link_2;
		delete link_1;
	}
	bool Contain(T value) {
		for (Link<T>* current = head->next; current != head; current = current->next) {
			if (current->value == value) {
				return true;
			}
		}
		return false;
	}
	void Clear() {
		while (head->next != head) {
			DelFirst();
		}
	}
	void OrderedInsert(T value) {
		Link<T>* link = head;
		while (link->next != head) {
			if (link->next->value > value) {
				Link<T>* new_link = new Link<T>(value, link->next);
				link->next = new_link;
				return;
			}
			link = link->next;
		}
		Link<T>* new_link = new Link<T>(value, head);
		link->next = new_link;
	}
	friend ostream& operator << (ostream& out, List& list) {
		Link<T>* current = list.head->next;
		while (current != list.head) {
			out << current->value << endl;
			current = current->next;
		}
		out << "$ ";
		return out;
	}
	friend istream& operator >> (istream& in, List& list) {
		list.Clear();
		string tmp;
		in >> tmp;
		string sep = "$";
		while (tmp != sep) {
			list.OrderedInsert(atoi(tmp.c_str()));
			in >> tmp;
		}
		return in;
	}
	List IncSort(List<T>& list) {
		List<T> new_list;
		Link<T>* current_1 = head->next;
		Link<T>* current_2 = list.head->next;
		while ((current_1 != head) && (current_2 != list.head)) {
			if (current_1->value == current_2->value) {
				new_list.AddLast(current_1->value);
				current_1 = current_1->next;
				current_2 = current_2->next;
			}
			else if (current_1->value < current_2->value) {
				current_1 = current_1->next;
			}
			else if (current_1->value > current_2->value) {
				current_2 = current_2->next;
			}
		}
		return new_list;
	}
	T& operator[](const int& index) {
		int counter = 0;
		Link<T>* current = head;
		while (current != nullptr) {
			if (counter == index) {
				return current->value;
			}
			current = current->next;
			counter++;
		}
	}
	Iterator<T>* Iterator() {
		return new ListIterator<T>(head);
	}
	Link<T>* getHead() {
		return head;
	}
};