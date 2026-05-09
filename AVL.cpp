#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
	int ht;
};
//global variable
struct node* root=NULL;
//fun declarartions
struct node* create(int);
struct node* insert(struct node*,int);
struct node* remove(struct node*,int);
struct node* search(struct node*,int);
struct node* rotateleft(struct node*);
struct node* rotateright(struct node*);
int balancefactor(struct node*);
int height(struct node*);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);

int main()
{
	int user=0,data;
	char user_continue='y';
	struct node* result=NULL;
	while(user_continue=='y'||user_continue=='Y')
	{
		printf("\ntype the number for the next process to continue the construct of AVL tree");
		printf("\n1.Insert\n2.Delete\n3.Search\n4.Inorder\n5.Preorder\n6.Postorder\n7.Exit");
        printf("\n\nEnter your choice number:");
        scanf("%d",&user);
        switch(user)
        {
        	case 1:
        		printf("\nenter data:");
        		scanf("%d",&data);
        		root=insert(root,data);
        		break;
        	
        	case 2:
        		printf("\nenter data:");
        		scanf("%d",&data);
        		root=remove(root,data);
        		break;
        	
        	case 3:
        		printf("\nenter data:");
        		scanf("%d",&data);
        		root=search(root,data);
        		if (result==NULL)
        		  printf("\nnode not found");
        		else
        			printf("\nnode found");
        		break; 
        		
        	case 4:
        		inorder(root);
        		break;
        	
			case 5:
        		preorder(root);
        		break;	
        	
        	case 6:
        		postorder(root);
        		break;
        		
        	case 7:
			printf("\n\nprogram terminated\n");
			return 1;
			
			default:
				printf("\n\ninvalid choice\n");
			
		}
		while((getchar())!='\n');
		printf("\n\nDo you want to continue?");
		scanf("%c",&user_continue);
	}
	return 0;
}

//create a new tree node
struct node* create(int data)
{
	struct node* new_node=(struct node*) malloc(sizeof(struct node));
    //memory error
    if(new_node==NULL)
    {
    	printf("\nmemory cant be allocated\n");
    	return NULL;
	}
	new_node->data=data;
	new_node->left=NULL;
	new_node->right=NULL;
	return new_node;
}

//rotate left
struct node* rotateleft(struct node* root)
{
	struct node* right_child=root->right;
	root->right=right_child->left;
	right_child->left=root;
	
	//height of node
	root->ht=height(root);
	right_child->ht=height(right_child);
	return right_child;
}

//rotate right
struct node* rotateright(struct node* root)
{
	struct node* left_child=root->left;
	root->left=left_child->right;
	left_child->right=root;
	
	//height of node
	root->ht=height(root);
	left_child->ht=height(left_child);
	return left_child;
}

//balance factor
int balancefactor(struct node* root)
{
	int lh,rh;
	if(root==NULL)
	  return 0;
	if(root->left==NULL)
	  lh=0;
	else
	  lh=root->left->ht;
	if(root->right==NULL)
	  rh=0;
	else
	  rh=root->left->ht;
	return lh-rh;
}

//height of node
int height(struct node* root)
{
	int lh,rh;
	if(root==NULL)
	  return 0;
	if(root->left==NULL)
	  lh=0;
	else
	  lh=root->left->ht;
	if(root->right==NULL)
	  rh=0;
	else
	  rh=root->left->ht;
	return (lh>rh)?lh+1:rh+1;
}

//insert
struct node* insert(struct node* root,int data)
{
	if(root==NULL)
	{
		struct node* new_node=create(data);
        if (new_node == NULL)  
        {  
            return NULL;  
        }  
        root = new_node;  
    }  
    else if (data > root->data)  
    {  
        // insert the new node to the right  
        root->right = insert(root->right, data);  
   
        // tree is unbalanced, then rotate it  
        if (balancefactor(root) == -2)  
        {  
            if (data > root->right->data)  
            {  
                root = rotateleft(root);  
            }  
            else  
            {  
                root->right = rotateright(root->right);  
                root = rotateleft(root);  
            }  
        }  
    }  
    else  
    {  
        // insert the new node to the left  
        root->left = insert(root->left, data);  
   
        // tree is unbalanced, then rotate it  
        if (balancefactor(root) == 2)  
        {  
            if (data < root->left->data)  
            {  
                root = rotateright(root);  
            }  
            else  
            {  
                root->left = rotateleft(root->left);  
                root = rotateright(root);  
            }  
        }  
    }  
    // update the heights of the nodes  
    root->ht = height(root);  
    return root;  
}  
   
// deletes 
struct node * remove(struct node *root, int x)  
{  
    struct node * temp = NULL;  
   
    if (root == NULL)  
    {  
        return NULL;  
    }   
   
    if (x > root->data)  
    {  
        root->right = remove(root->right, x);  
        if (balancefactor(root) == 2)  
        {  
            if (balancefactor(root->left) >= 0)  
            {  
                root = rotateright(root);  
            }  
            else  
            {  
                root->left = rotateleft(root->left);  
                root = rotateright(root);  
            }  
        }  
    }  
    else if (x < root->data)  
    {  
        root->left = remove(root->left, x);  
        if (balancefactor(root) == -2)  
        {  
            if (balancefactor(root->right) <= 0)  
            {  
                root = rotateleft(root);  
            }  
            else  
            {  
                root->right = rotateright(root->right);  
                root = rotateleft(root);  
            }  
        }  
    }  
    else  
    {  
        if (root->right != NULL)  
        {   
            temp = root->right;  
            while (temp->left != NULL)  
                temp = temp->left;  
   
            root->data = temp->data;  
            root->right = remove(root->right, temp->data);  
            if (balancefactor(root) == 2)  
            {  
                if (balancefactor(root->left) >= 0)  
                {  
                    root = rotateright(root);  
                } 
                else  
                {  
                    root->left = rotateleft(root->left);  
                    root = rotateright(root);  
                }  
            }  
        }  
        else  
            return (root->left);  
    }  
    root->ht = height(root);  
    return (root);  
}  
   
// search 
struct node* search(struct node* root, int key)  
{  
    if (root == NULL)  
        return NULL;  
    if(root->data == key)  
        return root;  
    if(key > root->data)  
        return search(root->right, key);  
    else  
        return search(root->left, key);   
}  
   
// inorder  tree  
void inorder(struct node* root)  
{  
    if (root == NULL)  
        return;  
    inorder(root->left);  
    printf("%d ", root->data);  
    inorder(root->right);  
}  
   
// preorder tree  
void preorder(struct node* root)  
{  
    if (root == NULL)  
        return;  
    printf("%d ", root->data);  
    preorder(root->left);  
    preorder(root->right);  
}  
   
// postorder tree  
void postorder(struct node* root)  
{  
    if (root == NULL)  
        return;   
    postorder(root->left);  
    postorder(root->right);  
    printf("%d ", root->data);  
}   
