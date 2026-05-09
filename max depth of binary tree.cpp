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
	struct node *node=(struct node *)malloc(sizeof(struct node));
	node->data=data;
	node->left=node->right=NULL;
	return node;
}
int maxdepth(struct node *node)
{
	if(node==NULL)
	return 0;
	else
	{
		int leftdepth=maxdepth(node->left);
		int rightdepth=maxdepth(node->right);
		return(leftdepth>rightdepth?leftdepth:rightdepth)+1;
	}
}
int main()
{
	struct node *root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	printf("max depth of the tree is: %d\n",maxdepth(root));
	return 0;
}
