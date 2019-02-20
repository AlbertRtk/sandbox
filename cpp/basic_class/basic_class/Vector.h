#pragma once

class Vector {
private:
	int x, y;
public:
	Vector();
	Vector(int, int);
	void set(int, int);
	int getx();
	int gety();
	Vector operator+(const Vector&);
};