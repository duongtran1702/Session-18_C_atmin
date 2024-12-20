#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct Dish{
	int id;
	char food[50];
	int price;
}menu;
void print_menu(menu *menu,int n){
	printf("--------menu--------\n");
	for(int i=0;i<n;i++){
		printf("%d. %s:%dvnd\n",menu[i].id,menu[i].food,menu[i].price);
	}
}

void add_menu(menu *menu,int *n){
	*n+=1;
	printf("Enter the location(0-%d):",*n);
	int pos;
	scanf("%d",&pos);
	getchar();
	if(pos==0){
		pos=1;
	}
	if(pos<1||pos>*n+1){
		printf("Invalid location!\n");
		return;
	}
	for(int i=*n;i>=pos;i--){
		menu[i]=menu[i-1];
	}
	printf("New dish:\n");
	menu[pos-1].id=*n;
	printf("Enter name of dish :");
	fgets(menu[pos-1].food,50,stdin);
	menu[pos-1].food[strcspn(menu[pos-1].food,"\n")]='\0';
	printf("Enter price:");
	scanf("%d",&menu[pos-1].price);
	getchar();
	printf("Add dish successfully!\n");
}

void update_menu(menu *menu,int n){
	printf("Enter the location(1-%d):",n);
	int pos;
	scanf("%d",&pos);
	getchar();
	if(pos<1||pos>n){
		printf("Invalid location!\n");
		return;
	}
	printf("Update dish:\n");
	printf("Update name of dish :");
	fgets(menu[pos-1].food,50,stdin);
	menu[pos-1].food[strcspn(menu[pos-1].food,"\n")]='\0';
	printf("Update price:");
	scanf("%d",&menu[pos-1].price);
	getchar();
	printf("Update dish successfully!\n");
}

void delete_menu(menu *menu,int *n){
	printf("Enter the location(1-%d):",*n);
	int pos;
	scanf("%d",&pos);
	getchar();
	if(pos<1||pos>*n){
		printf("Invalid location!\n");
		return;
	}
	for(int i=pos-1;i<*n;i++){
		menu[i]=menu[i+1];
	}
	*n-=1;
	printf("Delete dish successfully!\n");
}

void swap(menu *x,menu*y){
	menu temp=*x;
	*x=*y;
	*y=temp;
}
void arrange_menu(menu *menu,int n){
	printf("a. Sort ascending.\n");
	printf("b. Sort descending.\n");
	char option;
	do{
		printf("Choose a or b:");
		scanf(" %c",&option);
	}while(option!='a'&&option!='b');
	if(option=='a'){
		printf("Sort in ascending order...\n");
		for(int i=0;i<n-1;i++){
			int temp=i;
			for(int j=i+1;j<n;j++){
				if(menu[j].price<menu[temp].price){
					temp=j;
				}
			}
			if(temp!=i){
				swap(&menu[i],&menu[temp]);
			}
		}
	}
	if(option=='b'){
		printf("Sort in descending order...\n");
		for(int i=0;i<n-1;i++){
			int temp=i;
			for(int j=i+1;j<n;j++){
				if(menu[j].price>menu[temp].price){
					temp=j;
				}
			}
			if(temp!=i){
				swap(&menu[i],&menu[temp]);
			}
		}
	}
	printf("Sorting the menu by price was successfully!\n");	
}

void format_name(char *name){
	int new_word=1;
	size_t len=strlen(name);
	for(int i=0;i<len;i++){
		if(isspace(*(name+i))){
			new_word=1;
		}
		else if(new_word==1){
			*(name+i)=toupper(*(name+i));
			new_word=0;
		}
		else{
			*(name+i)=tolower(*(name+i));
		}
	}
}

void search_menu(menu *menu,int n){
	printf("Enter name of dish :");
	char name[30];
	fgets(name,30,stdin);
	name[strcspn(name,"\n")]='\0';
	format_name(name);
	printf("a. Linear search.\n");
	printf("b. Binary search.\n");
	char option;
	do{
		printf("Choose a or b:");
		scanf(" %c",&option);
	}while(option!='a'&&option!='b');
	int flag=-1;
	if(option=='b'){
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n-i-1;j++){
				if(strcmp(menu[j].food,menu[j+1].food)>0){
					swap(&menu[j],&menu[j+1]);
				}
			}
		}
		int l=0;
		int r=n-1;
		while(l<=r){
			int m=(l+r)/2;
			int k=strcmp(menu[m].food,name);
			if(k==0){
				flag=m;
				break;
			}
			else if(k<0){
				l=m+1;
			}
			else{
				r=m-1;
			}
		}
	}
	if(option=='a'){
		for(int i=0;i<n;i++){
			if(strcmp(menu[i].food,name)==0){
				flag=i;
			}
		}
	}
	if(flag!=-1){
		printf("The dish at postion %d: ",flag+1);
		printf("%d.%s:%dvnd\n",menu[flag].id,menu[flag].food,menu[flag].price);
	}
	else {
		printf("Dish does not exist !\n");
	}
}

void show_menu() {
    printf("\n===== Menu =====\n");
    printf("1. Show menu of dish\n");
    printf("2. Add menu\n");
    printf("3. Update menu\n");
    printf("4. Delete menu\n");
    printf("5. Arrange menu\n");
    printf("6. Search menu\n");
    printf("7. Exit\n");
    printf("================\n");
}
int main(){
	Dish menu[100]={
	{1,"Grill meat",20000},
	{2,"Sweet and sour stir-fried ribs",30000},
	{3,"Braised carp with melon",35000},
	{4,"Rice",5000},
	{5,"Crab soup",15000}
	};
    int n=5;
    for(int i=0;i<n;i++){
    	format_name(menu[i].food);
	}
	do{
		show_menu();
		int choice;
		printf("Enter your choice :");
		scanf("%d",&choice);
		getchar();
		if(choice==1){
			print_menu(menu,n);
		}
		else if(choice==2){
			add_menu(menu,&n);
		}
		else if(choice==3){
			update_menu(menu,n);
		}
		else if(choice==4){
			delete_menu(menu,&n);
		}
		else if(choice==5){
			arrange_menu(menu,n);
		}
		else if(choice==6){
			search_menu(menu,n);
		}
		else if(choice==7){
			printf("Exit!\n");
			return 0;
		}
		else {
			printf("Invalid choice !\n");
		}
	}while(1);
	return 0;
}
