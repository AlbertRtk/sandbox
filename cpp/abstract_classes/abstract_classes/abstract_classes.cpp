// abstract_classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

class Shape {
public:
	virtual int area() = 0;
	void print_base() { cout << "Shape" << endl; }
	virtual void print() { cout << "Undef. shape" << endl; }
};

class Rectangle : public Shape {
	int length, width;
public:
	Rectangle(int l, int w) { length = l; width = w; }
	int area() { return length * width; }
	void print() { cout << "Rectangle" << endl; }
};

void shape_type(Shape *sh) {
	sh->print();
}

int main()
{
	Shape * p;
	Rectangle rect (2, 3);
	p = &rect;

	Rectangle * pr = new Rectangle(4, 5);

	p->print_base();
	p->print();
	cout << p->area() << endl;
	
	rect.print_base();
	rect.print();
	cout << rect.area() << endl;

	pr->print_base();
	shape_type(pr);
	cout << pr->area() << endl;	
}
