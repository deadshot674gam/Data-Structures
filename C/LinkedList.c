#include<stdio.h>
#include<stdlib.h>
int len(); // for defining the length of linkedlist
void addAtBegin(int a); // for adding the element at the start of the linkedlist
void append(int a); // for adding the element at the end of the linkedlist
void addAfter(int a, int loc); // for adding the element at the certain position in the linkedlist
void delFirst(); // for deleting the first element of the linkedlist
void delLast(); // for deleting the last element of the linkedlist
void delAt(int loc); // for deleting the element at a certain position in the linkedlist
void display();

struct node{
	int data;
	struct node* link;
};
struct node* root=NULL;
//root=(struct node*)malloc(sizeof(struct node));
//root->data=5;
//root->link=NULL;
int len(){
	int length=0;
	if(root==NULL){
		return length;
	}
	else{
		struct node* ptr=root;
		while(ptr!=NULL){
			ptr=ptr->link;
			length++;
		}
		return length;
	}
	
}
void addAtBegin(int a){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=a;
	if(root==NULL){
		root=temp;
		temp->link=NULL;
	}
	else{
		temp->link=root;
		root=temp;  
	}
}

void addAfter(int a, int loc){
	if(loc>len()-1){
		printf("Out of Bound: Size is %d\n",len());
	}
	else{
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		temp->data=a;
		int i=0;
		struct node* ptr1;
		struct node* ptr=root;
		while(i<loc){
			ptr=ptr->link;
			i++;
		}
		temp->link=ptr->link;
		ptr->link=temp;
	}
	
}

void append(int a){
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=a;
	temp->link=NULL;
	if(root==NULL){
		root=temp;
	}
	else{
		struct node* ptr=root;
		while(ptr->link!=NULL){
			ptr=ptr->link;
		}
		ptr->link=temp;
	}
	
}



void delFirst(){
	if(root==NULL){
		printf("No node present\n");
	}
	else{
		root=root->link;
	}
}

void delLast(){
	if(root==NULL){
		printf("NO Node present");
	}
	else{
		struct node* ptr=root;
		struct node* loc;
		while(ptr->link!=NULL){
			loc=ptr;
			ptr=ptr->link;
		}
		loc->link=NULL;
	}
}
void del(int a){
	if(root==NULL){
		printf("List already empty");
	}
	else{
		struct node* loc;
		struct node* ptr=root;
		while(ptr->data!=a){
			loc=ptr;
			ptr=ptr->link;
			
		}
		loc->link=ptr->link;
		
	}
}

void display(){
	if(root==NULL){
		printf("NO Node present");
	}
	else{
		struct node* ptr=root;
		while(ptr!=NULL){
			printf("%d ", ptr->data);
			ptr=ptr->link;
		}
		printf("\n");
		
	}
}

// driver's code
void main(){
	addAtBegin(10);
	append(25);
	append(12);
	display();
	printf("%d\n", len());
	delFirst();
	display();
	printf("%d\n", len());
	append(9);
	display();
	printf("%d\n", len());
	delLast();
	display();
	printf("%d\n", len());
	addAfter(10,2);
	display(); 
	del(12);
	display();
}
