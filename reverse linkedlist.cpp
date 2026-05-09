#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node* reverse(struct node* head,int left,int right)
{
	if(head!=NULL && left==right)
	return head;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->next=head;
	struct node* pre=temp;
	for(int i=0;i<left;i++)
	{
		pre=pre->next;
	}
	struct node* start=pre->next;
	struct node* then=start->next;
	for(int i=0;i<right-left;i++)
	{
		start->next=then->next;
		then->next=pre->next;
		pre->next=then;
		then=start->next;
	}
	head=temp->next;
	free(temp);
	return head;
}
void print(struct node* head)
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
	struct node* head=malloc(sizeof(struct node));
	head->data=1;
	head->next=malloc(sizeof(struct node));
	head->next->data=2;
	head->next->next=malloc(sizeof(struct node));
	head->next->next->data=3;
	head->next->next->next=malloc(sizeof(struct node));
	head->next->next->next->data=4;
	head->next->next->next->next=malloc(sizeof(struct node));
	head->next->next->next->next->data=5;
	head->next->next->next->next->next=NULL;
	printf("the original linkedlist is ");
	print(head);
	printf("\nthe reversed linkedlist is ");
	head=reverse(head,2,4);
	print(head);
	return 0;
}
