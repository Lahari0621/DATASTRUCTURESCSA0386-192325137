#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node* insert(struct node* head,int p,int n)
{
	struct node* newnode=malloc(sizeof(struct node));
	newnode->data=p;
	if(n==0)
    {
    	newnode->next=head;
    	return newnode;
	}	
	struct node* temp=head;
	int i=0;
	while(i<n-1 && temp!=NULL)
	{
		temp=temp->next;
		i++;
	}
	if(temp==NULL)
	{
		printf("\nposotion is beyond the list length,node cannot be iserted\n");
		return head;
	}
	newnode->next=temp->next;
	temp->next=newnode;
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
	printf("->NULL");
}
int main()
{
	struct node* head=malloc(sizeof(struct node));
	head->data=1;
	head->next=malloc(sizeof(struct node));
	head->next->data=3;
	head->next->next=malloc(sizeof(struct node));
	head->next->next->data=2;
	head->next->next->next=malloc(sizeof(struct node));
	head->next->next->next->data=3;
	head->next->next->next->next=malloc(sizeof(struct node));
	head->next->next->next->next->data=4;
	head->next->next->next->next->next=malloc(sizeof(struct node));
	head->next->next->next->next->next->data=5;
	head->next->next->next->next->next->next=NULL;
	printf("original linkedlist is \n");
	print(head);
	printf("\nnew linkedlist is \n");
	head=insert(head,3,2);
	print(head);
}
