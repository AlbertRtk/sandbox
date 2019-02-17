#pragma once

class Rectangle {
private:
	int width, height;

public:
	Rectangle();
	Rectangle(int, int);
	void set_values(int, int);
	int area(void);
};