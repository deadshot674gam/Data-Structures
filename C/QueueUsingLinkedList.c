#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* link;
};
typedef struct node Node;
Node* start=NULL;
Node* end=NULL;
void enqueue(int a){
	Node* temp;
	temp=(Node*)malloc(sizeof(Node));
	temp->data=a;
	temp->link=NULL;
	if(start==NULL){
		start=temp;
	}
	else{
		Node* ptr=start;
		while(ptr->link!=NULL){
			ptr=ptr->link;
		}
		ptr->link=temp;
	}
	end=temp;
	
}

void dequeue(){
	if(start==NULL){
		printf("No node present\n");
	}
	else{
		printf("%d \n", start->data);
		start=start->link;
	}
}

void display(){
	if(start==NULL){
		printf("NO Node present");
	}
	else{
		Node* ptr=start;
		while(ptr!=NULL){
			printf("%d ", ptr->data);
			ptr=ptr->link;
		}
		printf("\n");
		
	}
}

void main(){
	enqueue(5);
	enqueue(22);
	enqueue(21);
	enqueue(23);
	dequeue();
	display();
}
