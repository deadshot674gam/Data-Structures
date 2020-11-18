#include<stdio.h>
int stack[100];
int top=-1;
int isFull(){
	if(top>=99){
		return 1;
	}
	else{
		return 0;
	}
}
int isEmpty(){
	if(top<=-1){
		return 1;
	}
	else{
		return 0;
	}
}
int pop(){
	if(isEmpty()){
		printf("Stack Underflow");
		
	}
	else{
		int temp=stack[top];
		top--;
		return temp;
		
	}
}
void push(int x){
	if(isFull()){
		printf("Stack Overflow");
		
	}
	else{
		top++;
		stack[top]=x;
	}
}
int peek(){
	if(isEmpty()){
		printf("Stack Underflow");
		
	}
	else{
		return stack[top];
	}
}
void display(){
	int i;
	for(i=top;i>-1;i--){
		printf("%d\t",stack[i]);
	}
}
void main(){
	int n,i,x;
	printf("How many numbers into stack?(not exceeding 100)");
	scanf("%d",&n);
	printf("Enter them:\n");
	for(i=0;i<n;i++){
		scanf("%d",&x);
		push(x);
	}
	printf("\n%d",pop());
	display();
}
