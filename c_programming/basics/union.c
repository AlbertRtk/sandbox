#include<stdio.h>
#include<string.h>


union No {
	int i;
	float f;
	char str[20];
};


int main() {
	union No n;
	n.i = 10;
	printf("%d\n\n", n.i);
	
	n.f = 10.0;
	printf("%d\n", n.i);
	printf("%f\n\n", n.f);
	
	strcpy(n.str, "Ten");
	printf("%d\n", n.i);
	printf("%f\n", n.f);
	printf("%s\n\n", n.str);
	
	return 0;
}
