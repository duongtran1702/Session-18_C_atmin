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
	printf("Enter age:");
	scanf("%d",&sv.age);
	getchar();
	printf("Enter name :");
	fgets(sv.name,100,stdin);
	sv.name[strcspn(sv.name,"\n")]='\0';
	printf("Enter telephone number :");
	fgets(sv.telephone_number,100,stdin);
	sv.telephone_number[strcspn(sv.telephone_number,"\n")]='\0';
	printf("Tuoi :%d\n",sv.age);
	printf("Ten:%s\n",sv.name);
	printf("SDT:%s",sv.telephone_number);
}