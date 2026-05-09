#include<stdio.h>
int queue[100];
int max=4,rear=-1,front=-1;
void enqueue();
void dequeue();
int main()
{
	int i;
	printf("\nenter the elements in queue");
	for(i=0;i<=5;i++)
	enqueue();
    for(i=0;i<=5;i++)
	dequeue();
}
void enqueue()
{
	int a;
	if (rear==max)
	  printf("\nqueue overflow");
	else
	{
		scanf("%d",&a);
		if(front==-1)
		 front=0;
		queue[++rear]=a;
		printf("\nthe element is enqueue into queue %d",a);
	}
}
void dequeue()
{
	int item;
	if (rear==-1)
	printf("\nqueue underflow");
	else
	{
		item=queue[front];
		front++;
		if(front>rear)
		  {front=rear=-1;}
		printf("\nthe element is dequeue %d",item);
	}
}
/*#include<stdio.h>
int queue[100]={0};
int max=4,rear=-1;
void enqueue();
void dequeue();
int main()
{
	int i;
	printf("\nenter the elements in queue");
	for(i=0;i<=5;i++)
	enqueue();
    for(i=0;i<=5;i++)
	dequeue();
}
void enqueue()
{
	int a;
	if (rear==max)
	  printf("\nqueue overflow");
	else
	{
		scanf("%d",&a);
		queue[++rear]=a;
		printf("\nthe element is enqueue into queue %d",a);
	}
}
void dequeue()
{
	if (rear==-1)
	printf("\nqueue underflow");
	else
	{
		printf("\nthe element is dequeue %d",queue[rear--]);
	}
}*/
