#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	int id;
	char name[30];
	int age;
	char tel[11];
}student;
void enter_list(student **sv,int *n){
	printf("Enter the number of student :");
	scanf("%d",n);
	if(*n<1){
		printf("Invalid number of student !\n");
		exit(1);
	}
	getchar();
	*sv=(student*)malloc(*n*sizeof(student));
	if(*sv==NULL){
		printf("Memory allocation failed !\n");
		exit(1);
	}
	for(int i=0;i<*n;i++){
		(*sv)[i].id=i+1;
		printf("Id student 0%d:\n",(*sv)[i].id);
		printf("Enter name :");
		fgets((*sv)[i].name,30,stdin);
		(*sv)[i].name[strcspn((*sv)[i].name,"\n")]='\0';
		printf("Enter age:");
		scanf("%d",&(*sv)[i].age);
		getchar();
		printf("Enter telephone number:");
		fgets((*sv)[i].tel,11,stdin);
		(*sv)[i].tel[strcspn((*sv)[i].tel,"\n")]='\0';
		printf("\n");
	}
}

void print_list(student *sv,int n){
	printf("List of student:\n");
	for(int i=0;i<n;i++){
		printf("Id sudent 0%d:\n",sv[i].id);
		printf("Name :%s\n",(*(sv+i)).name);
		printf("Age :%d\n",(*(sv+i)).age);
		printf("Tel :%s\n",(*(sv+i)).tel);
		printf("\n");
	}
}
int main(){
	int n;
	student *hs=NULL;
	enter_list(&hs,&n);
	print_list(hs,n);
	free(hs);
	return 0;
}
