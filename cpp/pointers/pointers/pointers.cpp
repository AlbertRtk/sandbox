// pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

void add_one(int * i) {
	(*i)++;
}

int sum(int a, int b) {
	return (a + b);
}

int diff(int a, int b) {
	return (a - b);
}

int operation(const int * a, const int * b, int(*func)(int, int)) {
	return (*func)(*a, *b);
}

int main()
{
	int v[5] = {0, 1, 2, 3, 4};
	int * p = v;

    cout << "v = " << v << endl;
	cout << "p = " << p << endl;
	cout << "*p = " << *p << endl;
	cout << "*(v+2) = " << *(v+2) << endl;
	cout << "&p = " << &p << endl;

	cout << "-----" << endl;
	
	cout << "*v = " << *v << endl;
	add_one(p);
	cout << "*v = " << *v << endl;

	cout << "-----" << endl;

	int a = 15;
	int b = 5;
	cout << "operation sum: " << operation(&a, &b, sum) << endl;
	cout << "operation diff: " << operation(&a, &b, diff) << endl;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
