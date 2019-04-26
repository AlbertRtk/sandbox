#include <stdio.h>

int main() {
	unsigned char a = 0b1110;
	unsigned char b = 0b0101;
	unsigned char c;
	
	printf("a = %d \nb = %d \n", a, b);
	
	c = a & b;
	printf("c = a & b = %d \n", c);
	
	c = a | b;
	printf("c = a | b = %d \n", c);
	
	c = a ^ b;
	printf("c = a ^ b = %d \n", c);
	
	c = ~c;
	printf("c = ~c = %d \n", c);
	
	a = a << 1;
	printf("a << 1 = %d \n", a);
	
	b = b >> 1;
	printf("b >> 1 = %d \n", b);
	
	printf("1 << 3 = %d \n", 1 << 3);

    return 0;
}
