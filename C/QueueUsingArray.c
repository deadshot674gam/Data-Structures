#include<stdio.h>
int queue[100];
int rear=0;
int front=0;

void enqueue(int x){
	queue[rear]=x;
	rear++;
}

int dequeue(){
	if(front==rear){
		printf("%s\n","Queue is empty" );
		return;
	}
	int temp=queue[front];
	int i;
	for (i = 0; i < rear-1; ++i)
	{
		queue[i]=queue[i+1];
	}
	rear--;
	return temp;
}

void display(){
	int i;
	if (front==rear)
	{
		printf("Queue is empty");
		return;
		/* code */
	}
	for (i = 0; i <rear; ++i)
	{
		printf("%d\t", queue[i]);
	}
}
void main(){
	int n,i,x;
	printf("How many numbers into queue?(not exceeding 100)");
	scanf("%d",&n);
	if(n>0){
		printf("Enter them:\n");
		for(i=0;i<n;i++){
			scanf("%d",&x);
			enqueue(x);
		}
		
	}
	
//	printf("\n%d",dequeue());
//	printf("\n%d",dequeue());
//	printf("\n%d",dequeue());
	display();
}
