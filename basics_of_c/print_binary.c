/* Albert Ratajczak, 2019 */

#include <stdio.h>
#include <stdlib.h>


void printb(unsigned int);
char * binary(unsigned int);


int main() {
	printb(98);
	printf("\n");
	
	char * b;
	b = binary(98);
	printf("%s \n", b);
	
    return 0;
}


void printb(unsigned int num) {
	if(num>1) {				// if number is grater than 1:
		printb(num>>1);		// binary shift and recursion,
	}						// i.e., 0b0101 -> 0b0010 -> recursion
	printf("%d", num&1);	// prints 1 if binary number finishes with 1, i.e., 0b0101
}


char * binary(unsigned int num) {
	/* returns a pointer to array with binary representation of num */
	
	char * b;							// pointer to array with binary representation
	int i, n = 1;						// loop iterator, array length
	b = (char *) malloc(n);				// initaial memory allocation 
	b[0] = '\0';						// last element of the array
	
	do {
		n += 1;							// increasing array length
		b = (char *) realloc(b, n);		// memory reallocation
		for(i=n-1; i>0; i--) {
			b[i] = b[i-1];				// right-shifting of array elements
		}
		b[0] = num&1 ? '1' : '0';		// setting value of 1st [0] array element
		num >>= 1;						// binary right shift of the number
	} while(num>0);						// repeating until the num > 0
	
	return b;	
}
