// basic_class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Cuboid.h"
#include "Vector.h"

using namespace std;

int main()
{
	Cuboid cubo(3, 4, 5);
    cout << "V = " << cubo.volume() << endl; 

	Vector v;
	v.set(2, 2);
	cout << "vector = " << v.getx() << ", " << v.gety() << endl;
	v = v + v;
	cout << "vector = " << v.getx() << ", " << v.gety() << endl;

	return 0;
}

