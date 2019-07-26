#include<stdio.h>
#include<stdlib.h>
#define queueSize 100
int myQueue[queueSize],front=0,rear=-1;

void enqueue(int value)
{
	if(rear==queueSize)
	{
		printf("Queue is full:\n");
	}
	else
	{
		myQueue[++rear]=value;
	}
}

void dequeue()
{
	if(front==queueSize)
	{
		printf("Queue is empty:\n");
	}
	else
	{
		printf("Dequeued Value is:%d\n",myQueue[front++]);
	}
}

void Display()
{
	int i;
	for(i=front;i<=rear;i++)
	{
		printf("%d\t",myQueue[i]);
	}
}

int main()
{
	for(int i=10;i<=100;i=i+10)
	{
		enqueue(i);
	}
	printf("Full Queue is:\n");
	Display();
	printf("\n");
	dequeue();
	dequeue();
	printf("Updated Queue is :\n");
	Display();
	printf("\n");
	enqueue(999);
	enqueue(50);
	printf("\n Updated Queue is:\n");
	Display();
	printf("\n");
	return 0;
}
