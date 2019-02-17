#include "pch.h"
#include "Cuboid.h"

Cuboid::Cuboid() {
	base.set_values(0, 0);
	height = 0;
}

Cuboid::Cuboid(int a, int b, int c) {
	base.set_values(a, b);
	height = c;
}

void Cuboid::set_values(int a, int b, int c) {
	base.set_values(a, b);
	height = c;
}

int Cuboid::volume(void) {
	return height * base.area();
}
