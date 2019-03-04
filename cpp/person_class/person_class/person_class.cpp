// person_class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;





class Person {
private:
	string name, surname;
	static int count;
public:
	Person();
	Person(const string &, const string &);
	virtual void print();
	static int get_count();
	~Person();
};

Person::Person() : name("unknown"), surname("unknown") {
	count++;
	cout << "New person: ";
	this->print();
}

Person::Person(const string &fname, const string &sname) : name(fname), surname(sname) {
	count++;
	cout << "New person: ";
	this->print();
}

Person::~Person() {
	cout << "Deleted: ";
	this->print();
	count--;
}

void Person::print() {
	cout << name << " " << surname << endl;
}

int Person::count = 0;

int Person::get_count() { return count; }





class Employee : public Person {
private:
	string position;
public:
	Employee() : Person(), position("unknown") { cout << "Position: " << position << endl; };
	Employee(const string &, const string &, const string &);
	void print();
};

Employee::Employee(const string &fname, const string &sname, const string &pos) : Person(fname, sname) {
	position = pos;
	cout << "Position: " << position << endl;
}

void Employee::print() {
	Person::print();
	cout << position << endl;
}





int main()
{
	cout << "Count " << Person::get_count() << endl << endl;

	Person me("Albert", "Ratajczak");
	cout << "Count " << Person::get_count() << endl << endl;

	Person someone("Zenon", "Nowak");
	cout << "Count " << Person::get_count() << endl << endl;

	Person* someone1 = new Person;
	cout << "Count " << Person::get_count() << endl << endl;
	delete(someone1);
	cout << "Count " << Person::get_count() << endl << endl;

	Employee someone2("Jan", "Kowalski", "developer");
	cout << "Count " << Person::get_count() << endl << endl;

	Person* someone3;
	someone3 = &someone2;
	someone3->print();
	cout << "Count " << Person::get_count() << endl << endl;

	cout << "THE END" << endl << endl;
}
