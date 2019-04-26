#include <stdio.h>

int factorial(unsigned int n) {
	return n<=1 ? 1 : n*factorial(n-1);
}

int main() {
	unsigned int n = 5;
	printf("n! = %d \n", factorial(n) );

    return 0;
}
