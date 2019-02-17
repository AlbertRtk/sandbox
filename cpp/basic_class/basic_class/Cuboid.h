#pragma once
#include "Rectangle.h"

class Cuboid {
private:
	Rectangle base;
	int height;
public:
	Cuboid();
	Cuboid(int, int, int);
	void set_values(int, int, int);
	int volume(void);
};