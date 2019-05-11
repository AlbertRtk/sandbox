#include<stdio.h>
#include<string.h>


typedef struct People {
	char name[20];
	char surname[20];
	int id;
} Person;


int main() {
	Person man;
	strcpy(man.name, "Jan");
	strcpy(man.surname, "Kowalski");
	man.id = 1;
	
	printf("Name: %s\nSurname: %s\nID: %d", man.name, man.surname, man.id);
	
	return 0;
}
