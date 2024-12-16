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
		printf("Enter student 0%d:\n",i+1);
		printf("Enter id:");
		scanf("%d",&(*sv)[i].id);
		getchar();
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

void update_list(student *sv,int n,int id){
	int flag=0;
	for(int i=0;i<n;i++){
		if(sv[i].id==id){
			flag=1;
			printf("Id sudent %d:\n",sv[i].id);
			printf("Name :%s\n",(*(sv+i)).name);
			printf("Age :%d\n",(*(sv+i)).age);
			printf("Tel :%s\n",(*(sv+i)).tel);
			printf("\n");
			printf("Update information of student id %d:\n",id);
			printf("Update name :");
			fgets(sv[i].name,30,stdin);
			sv[i].name[strcspn(sv[i].name,"\n")]='\0';
			printf("Update age:");
			scanf("%d",&sv[i].age);
			getchar();
			printf("Update telephone number:");
			fgets(sv[i].tel,11,stdin);
			sv[i].tel[strcspn(sv[i].tel,"\n")]='\0';
			printf("\n");
		}
	}
	if(flag==0){
		printf("ID does not exist!\n");
		printf("\n");
	}
}

void print_list(student *sv,int n){
	printf("List of student:\n");
	for(int i=0;i<n;i++){
		printf("Id sudent %d:\n",sv[i].id);
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
	printf("Enter the id you want to fix information:");
	int id;
	scanf("%d",&id);
	getchar();
	update_list(hs,n,id);
	print_list(hs,n);
	free(hs);
	return 0;
}
