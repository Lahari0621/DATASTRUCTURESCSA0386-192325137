#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *reverse(struct node *head)
{
	struct node *pre=NULL;
	struct node *current=head;
	struct node *next=NULL;
	while(current!=NULL)
	{
		next=current->next;
		current->next=pre;
		pre=current;
		current=next;
	}
	head=pre;
	return head;
}
void print(struct node *head)
{
	while(head!=NULL)
	{
		printf("%d",head->data);
		head=head->next;
		if(head!=NULL)
		printf("->");
	}
	printf("->NULL\n");
}
int main()
{
	struct node *head=(struct node *)malloc(sizeof(struct node));
	head->data=5;
	head->next=(struct node *)malloc(sizeof(struct node));
	head->next->data=6;
	head->next->next=(struct node *)malloc(sizeof(struct node));
	head->next->next->data=7;
	head->next->next->next=(struct node *)malloc(sizeof(struct node));
	head->next->next->next->data=8;
	head->next->next->next->next=NULL;
	printf("the original linkedlist is ");
	print(head);
	printf("\nthe reversed linkedlist is ");
	head=reverse(head);
	print(head);
	return 0;
}

