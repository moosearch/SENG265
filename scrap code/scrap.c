#include<stdio.h>
#include<stdlib.h>

typedef struct Person{
	char *name;
	int age;
}Person;

int main(){
	
	char t[5] = "John";
	Person x;
	x.age = 15;
	x.name = t;
	
	printf("Name: %s\nAge: %d\n",x.name,x.age);
	return 0;
}
