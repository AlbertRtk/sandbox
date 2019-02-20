// fizzbuzz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Write a program that prints the numbers from 1 to 100. 
But for multiples of three print “Fizz” instead of the number 
and for the multiples of five print “Buzz”. For numbers which
are multiples of both three and five print “FizzBuzz”.
*/

#include "pch.h"
#include <iostream>

using namespace std;

void fizzbuzz(int i) {
	if ( (i % 3 == 0) && (i % 5 ==0) ) { cout << "FizzBuzz"; }
	else if (i % 3 == 0) { cout << "Fizz"; }
	else if (i % 5 == 0) { cout << "Buzz"; }
	else { cout << i; }
	cout << endl;
}

void fizzbuzz2(int i) {
	cout << i << ": " << ((i % 3 == 0 && i % 5 == 0) ? "FizzBuzz" : (i % 3 == 0) ? "Fizz" : (i % 5 == 0) ? "Buzz" : "") << endl;
}

int main()
{
	for (int i = 1; i <= 100; i++) {
		fizzbuzz2(i);
	}
	return 0;
}

