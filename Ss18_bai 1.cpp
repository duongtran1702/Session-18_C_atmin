#include<stdio.h>
#include<string.h>
typedef struct {
	char name[100];
	int age;
	char telephone_number[100];
}Student;

int main(){
	int age=18;
	Student sv;
	sv.age=age;
	strcpy(sv.telephone_number,"0123456789");
	strcpy(sv.name,"Mynato Admin");
	printf("Tuoi :%d\n",sv.age);
	printf("Ten:%s\n",sv.name);
	printf("SDT:%s",sv.telephone_number);
}