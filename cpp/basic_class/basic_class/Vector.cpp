#include "pch.h"
#include "Vector.h"

Vector::Vector() {
	x = 0;
	y = 0;
}

Vector::Vector(int i, int j) {
	x = i;
	y = j;
}

void Vector::set(int i, int j) {
	x = i;
	y = j;
}

int Vector::getx() {
	return x;
}

int Vector::gety() {
	return y;
}

Vector Vector::operator+(const Vector& v) {
	Vector temp(x+v.x, y+v.y);
	return temp;
}