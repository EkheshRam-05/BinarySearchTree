#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define COUNT 10

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

typedef struct node *tree;

tree createnode(int);
tree Insert(tree, int);
tree Delete(tree, int);
tree Find(tree, int);
tree FindMin(tree);
tree FindMax(tree);
void Display(tree);
void print2DUtil(tree, int);

int main(){
	
	int ch, val;
	tree root = NULL;
	tree temp;
	while (1)
	{	
		printf("1.Insert\n2.Delete\n3.Find Min\n4.Find Max\n5.Find\n6.Display\n(0 to exit)\nEnter Your choice: ");
		scanf("%d", &ch);

		if (ch == 0){
			return 0;
		}

		switch (ch)
		{
		case 1:
			printf("Enter the Element: ");
			scanf("%d", &val);
			root = Insert(root, val);
			break;
		case 2:
			printf("Enter the Element: ");
			scanf("%d", &val);
			root = Delete(root, val);
			Display(root);
			break;
		case 3:
			temp = FindMin(root);
			printf("\n\nMinimum Element: %d\n\n", temp->data);
			break;
		case 4:
			temp = FindMax(root);
			printf("\n\nMaximum Element: %d\n\n", temp->data);
			break;
		case 5:
			printf("Enter the Element to Find: ");
			scanf("%d", &val);
			temp = Find(root, val);
			if (temp == NULL){
				printf("\n\nElement Not Found\n\n");
			}
			else{
				printf("\n\nElement Found\n\n");
			}
			Display(temp);
			break;	
		case 6:
			Display(root);
			break;
		default:
			printf("Wrong Choice!!!");
			break;
		}
	}
}

tree createnode(int key){
	tree newnode = malloc(sizeof(struct node));
	newnode->data = key;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

tree Insert(tree root, int key){

	if (root == NULL){
		return createnode(key);
	}

	if (root->data > key){
		root->left = Insert(root->left, key);
	}
	else if (root->data < key){
		root->right = Insert(root->right, key);
	}
	return root;
}

tree Delete(tree root, int key){
	tree temp;
	if(temp == NULL){
		return temp;
	}
	if (root->data > key){
		root->left = Delete(root->left, key);
	}
	else if (root->data < key){
		root->right = Delete(root->right, key);
	}
	else{
		if (root->left == NULL){
			temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL){
			temp = root->left;
			free(root);
			return temp;
		}	
		temp = FindMin(root->right);
		root->data = temp->data;
		root->right = Delete(root->right, temp->data);
	}
	return root;
}

tree Find(tree t, int key){
	tree temp = t;
	if(t == NULL){
		return NULL;
	}
	if(key < t->data){
		temp = Find(t->left, key);
	}
	if(key > t->data){
		temp = Find(t->right, key);
	}
	return temp;
}

tree FindMin(tree t){
	tree temp = t;
	while(temp->left != NULL){
		temp = temp->left;
	}
	return temp;
}

tree FindMax(tree t){
	tree temp = t;
	while(temp->right != NULL){
		temp = temp->right;
	}
	return temp;
}


void print2DUtil(tree root, int space)
{
    // Base case
    if (root == NULL){
		return;}
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void Display(tree t)
{
   // Pass initial space count as 0
   print2DUtil(t, 0);
}

/*
// Program to print binary tree in 2D
#include<stdio.h>
#include<malloc.h>
#define COUNT 10
 
// A binary tree node
struct Node
{
    int data;
    struct Node* left, *right;
};
 
// Helper function to allocates a new node
struct Node* newNode(int data)
{
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
 
// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(tree *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(tree *root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}
 
// Driver program to test above functions
int main()
{
    struct Node *root   = newNode(1);
    root->left   = newNode(2);
    root->right  = newNode(3);
 
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);
 
    root->left->left->left  = newNode(8);
    root->left->left->right  = newNode(9);
    root->left->right->left  = newNode(10);
    root->left->right->right  = newNode(11);
    root->right->left->left  = newNode(12);
    root->right->left->right  = newNode(13);
    root->right->right->left  = newNode(14);
    root->right->right->right  = newNode(15);
     
    print2D(root);
 
    return 0;
}
*/