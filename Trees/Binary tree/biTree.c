#include <stdio.h>
#include <stdlib.h>

// Structure defination
struct Node{
	int data;
	struct Node *left;
	struct Node *right;
}*root;

// Prototypes of all the functions
struct Node *createNode(int);
int displayTree(struct Node *);   // Not complete
int attach(struct Node *);
void search(int);
void menuSystem();

int main()
 {
// 	menuSystem();
	int arr[] = {40, 20, 45, 2, 50, 30, 90};
	int i;
	for(i=0;i<sizeof(arr)/4;i++){
		attach(createNode(arr[i]));
	}
	displayTree(root);
 	return 0;
 }
 
 struct Node *createNode(int data){
 	/*
		* Creating an pointer of the type 'Node'
		* Allocating memory to it
		* Assigning values to the specific memory location
		* Returning the pointer 
	*/
 	struct Node *child = (struct Node *) malloc(sizeof(struct Node));
 	child->data = data;
 	child->left = NULL;
 	child->right = NULL;
 	return child;
 }
 
int attach(struct Node *child){
	/*
		* Using the typical binary tree insertion algorithm. Nothing different
		* May seem a little complex. Read it a few time, and you will get it.
		* Trick is to play with pointers only. No objects. Because the changes 
		  made to the objects will only be local and will not affect the actual tree
	*/
 	if(root == NULL){  // Checking if the tree is empty
 			root = child;
 			return;
		 }
 	struct Node *parent = root;  // Creating a temporary reference to the root
 	while(1){   // Infinate loop
		if(child->data <= parent->data){  // Checking for binary tree conditions
			if(parent->left == NULL){
				parent->left = child;  // If the present node is NULL, then the new node will be placed there
				return;  // Exitting the function
			}
			parent = parent->left; // Incrementing the pointer
		}
		else{
			if(parent->right == NULL){
				parent->right = child; // Samething for the right side of the tree
				return;
			}
			parent = parent->right;  // Incrementing the pointer
		}
	 }
 }
 
 
void search(int data){
	/*
		* We go to each node and compare the value of the node with the argument.
		* If its greater we go to the right side of the node and ignore the whole left side
		  and vice versa
		* If we reach the leaf node and still found no match. Then the element does not exist.
	*/
	printf("\nInitiating search..\n");
	struct Node *current = root;  // reference to the root node
 	while(1){  // Infinate loop
 		if(current == NULL){  // Checking if we have reached the leaf node
 			printf("Not found..\n");
 			break;
		 }
 		else if(current->data == data){  // Comparing the node data with the arguement
 			printf("Found!\n");
 			break;
		 }
		else if(data < current->data){  // Refer point 2 in the above comment block
			printf("Checking left of %d..\n", current->data);
		 	current = current->left;  // Incrementing the pointer
		 }
		else{
			printf("Checking right of %d..\n", current->data);
			current = current->right;  // Incrementing the pointer
		}
		
	 }
 }
 
int displayTree(struct Node *rootRef){
	/*
		Function to traverse through the tree using 
		a simple DFS algorithm and print all the nodes.
	*/
	if(rootRef != NULL){
		printf("%d ", rootRef->data);
		displayTree(rootRef->left);
		displayTree(rootRef->right);
	}
}

void menuSystem(){
	int val;
 	char ch;
 	A:
 		system("cls");  // clear screen alternative for clrscr()
 		printf("MENU : \n\n 1. Insert element\n 2. Search element\n 3. Display tree\n 4. Exit\n  choice : ");  // Menu
 		scanf("%c", &ch);
 		switch(ch){
 			case '1': {  // the case where the user chooses to insert an element
 				system("cls");
 				printf("Enter the element to be inserted : ");
 				scanf("%d", &val);
 				attach(createNode(val));
 				printf("\nElement attached..");
 				getch();
				goto A;
			}
			case '2': {  // The case where the user chooses to search for an element
			 	system("cls");
			 	printf("Enter the element to be searched : ");
			 	scanf("%d", &val);
			 	search(val);
			 	getch();
				goto A;
			}
			case '3': {
				system("cls"); 
				displayTree(root); 
				getch(); 
				goto A;
			}
			case '4': exit(0);
			default : printf("\nEnter a valid choice! "); getch(); goto A;  // Validation
		}
}
