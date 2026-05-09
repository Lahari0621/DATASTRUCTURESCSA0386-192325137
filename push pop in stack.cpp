#include<stdio.h>
int stack[100];
int max=4,top=-1;
void push();
void pop();
int main()
{
	int i;
	printf("\nenter the elements in stack");
    for(i=0;i<=5;i++)
	push();
	for(i=0;i<=5;i++)
	pop();
}
void push()
{
	int a;
	if (top==max)
	  printf("\nstack overflow");
	else
	{
		scanf("%d",&a);
		stack[++top]=a;
		printf("\nthe element is pushed into stack %d",a);
	}
}
void pop()
{
	if (top==-1)
	printf("\nstack underflow");
	else
	{
		printf("\nthe element is popped %d",stack[top--]);
	}
}
