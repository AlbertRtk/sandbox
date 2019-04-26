#include <stdio.h>


void printb(unsigned int);


int main() {
	printb(98);
    return 0;
}


void printb(unsigned int num) {
	if(num>1) {
		printb(num>>1);
	}
	printf("%d", num&1);
}
