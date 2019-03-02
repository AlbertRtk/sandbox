// person_class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;


class Person {
private:
	string name, surname;
	int age;
public:
	Person();
	Person(const string&, const string&, int);
	void print();
};

Person::Person() : name(string("unknown")), surname(string("unknown")), age(0) {}
Person::Person(const string& p_name, const string& p_surname, int p_age) : name(p_name), surname(p_surname), age(p_age) {}

void Person::print() {
	cout << name << " " << surname << ", " << age << endl;
}



class Employee : public Person {
private:
	string department, position;
public:
	Employee(const string&, const string&, int e_age, const string&, const string&);
	void print();
};

Employee::Employee(const string& e_name, const string& e_surname, int e_age, const string& e_department, const string& e_position) 
	: Person(e_name, e_surname, e_age) {
		department = e_department;
		position = e_position;
	}

void Employee::print() {
	Person::print();
	cout << department << ", " << position << endl;
}



int main()
{
	string name("Jan"), surname("Kowalski"), department("IT"), position("developer");
	Employee e(name, surname, 30, department, position);
	e.print();
}

