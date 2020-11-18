#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct Node{
	int data;
	struct Node* link;
};
typedef struct Node Node;
Node* top=NULL;


void push(int a){
	Node* temp=(Node*)malloc(sizeof(Node));
	temp->data=a;
	if(top==NULL){
		top=temp;
		temp->link=NULL;
	}
	else{
		temp->link=top;
		top=temp;  
	}
}

void pop(){
	if(top==NULL){
		printf("No element present\n");
	}
	else{
		printf("%d\n",top->data);
		top=top->link;
	}
}

void peek(){
	if(top==NULL){
		printf("No element present\n");
	}
	else{
		printf("%d\n",top->data);
	}
}

void display(){
	if(top==NULL){
		printf("NO Node present");
	}
	else{
		Node* ptr=top;
		while(ptr!=NULL){
			printf("%d ", ptr->data);
			ptr=ptr->link;
		}
		printf("\n");
		
	}
}

void main(){
	push(5);
	push(22);
	push(21);
	push(23);
	pop();
	peek();
	display();
}



