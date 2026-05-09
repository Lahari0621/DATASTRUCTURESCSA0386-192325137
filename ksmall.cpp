#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *newnode(int data)
{ 
	struct node *Node=(struct node*)malloc(sizeof(struct node));
	Node->data=data;
	Node->left=Node->right=NULL;
	return Node;
}
void inorder(struct node *root,int *k,int *result)
{
	if(root==NULL||*k<=0)
	return ;
	inorder(root->left,k,result);
	(*k)--;
	if(*k==0)
	{
		*result=root->data;
		return;
	}
	inorder(root->right,k,result);
}
int ksmall(struct node *root,int k)
{
	int result=-1;
	inorder(root,&k,&result);
	return result;
}
int main()
{
	struct node* root=newnode(5);
	root->left=newnode(3);
	root->right=newnode(6);
	root->left->left=newnode(2);
	root->left->right==newnode(4);
	root->left->left->left=newnode(1);
	int k=3;
	int result=ksmall(root,k);
	printf("the %dth smallest element is: %d\n",k,result);
	return 0;
}
