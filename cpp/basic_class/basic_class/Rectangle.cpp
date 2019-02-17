#include "pch.h"
#include "Rectangle.h"

Rectangle::Rectangle() {
	width = 0;
	height = 0;
}

Rectangle::Rectangle(int a, int b) {
	width = a;
	height = b;
}

void Rectangle::set_values(int a, int b) {
	width = a;
	height = b;
}

int Rectangle::area(void) {
	return width * height; 
}