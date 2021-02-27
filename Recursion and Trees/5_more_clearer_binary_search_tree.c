#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

// Initially setting root node to NULL
struct Node* root = NULL;

// Create a new node
struct Node* createNode(int data){
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

// To search items in a binary search tree
// Returns the address of node that contains the item
// If item does not exist in any node then it returns NULL
struct Node* search(int item, struct Node** parent){
	struct Node* current = root;
	while (current != NULL){
		if (item == current->data){
			return current;
		}
		else if (item < current->data){
			*parent = current;
			current = current->left;
		}
		// If item is greater than current node
		else{
			*parent = current;
			current = current->right;
		}
	}
	return NULL;
}

// To build the binary search tree
void insertNode(int data){
	// Searching if data exists in the BST
	// search expects two arguments: (1) item to search (2) a pointer to pointer to struct Node type
	struct Node* parent = NULL;
	struct Node* search_status = search(data, &parent);
	// If data exists in the BST
	if (search_status != NULL){
		printf("data already exists in the binary tree\n");
		return;
	}
	// If data does not exist in the BST (actual insertion)
	else{
		if (parent == NULL){
			root = createNode(data);
		}
		else if (data < parent->data){
			parent->left = createNode(data);
		}
		else{
			parent->right = createNode(data);
		}
	}
}


// Implementing a queue data structure to store struct Node* types
// Global queue array of struct Node* type

struct Node** queue = NULL;
int front = -1, rear = -1;
// Allocating memeory to queue to store 50 struct Node* types
void allocateQueue(){
	printf("Allocating memory to queue...\n");
	queue = (struct Node**)malloc(sizeof(struct Node*)*50);
	printf("Memory allcated successfully.\n");
}

void enqueue(struct Node* node){
	if (front == -1 && rear == -1){
		front++;
		rear++;
	}
	else if (rear + 1 == front || rear-front == 49){
		printf("Queue is full!\n");
		return;
	}
	else if (rear == 49){
		rear = 0;
	}
	else{
		rear++;
	}
	*(queue + rear) = node;
}

struct Node* dequeue(){
	struct Node* temp = NULL;
	if (front == -1 && rear == -1){
		printf("List is empty\n");
		return temp;
	}
	else if (front == rear){
		temp = *(queue + front);
		front = -1, rear = -1;
		return temp;
	}
	else{
		temp = *(queue + front);
		front += 1;
		return temp;
	}
}

int empty(){
	if (front == -1 && rear == -1){
		return 1;
	}
	else{
		return 0;
	}
}


// Tree traversals
// Pre-order: first process the current node and then left and right
void preOrder(struct Node* root){
	if (root != NULL){
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

// In-order: first visit the left node and then current and right
void inOrder(struct Node* root){
	if (root != NULL){
		inOrder(root->left);
		printf("%d ", root->data);
		inOrder(root->right);
	}
}

// Post-order: first visit left and the right child and then current
void postOrder(struct Node* root){
	if (root != NULL){
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->data);
	}
}

// Level-order: Breadth-First Search
void levelOrder(struct Node* root){
	struct Node* temp = NULL;
	enqueue(root);
	while (!empty()){
		temp = dequeue();
		printf("%d ", temp->data);
		if (temp->left != NULL){
			enqueue(temp->left);
		}
		if (temp->right != NULL){
			enqueue(temp->right);
		}
	}
}

int main(){
	int choice;
	int temp;
	while (1){
		printf("Enter 1 to insert into BST\nEnter 2 to print BST\nEnter any other key to exit the program\nEnter: ");
		scanf("%d", &choice);
		if (choice == 1){
			while (1){
				printf("\tEnter data (Enter -99 to exit options): ");
				scanf("%d", &temp);
				if (temp != -99){
					insertNode(temp);
				}
				else{
					printf("\t\tDo you want to stop giving input (1 for yes, any key for no): ");
					scanf("%d", &temp);
					if (temp == 1){
						break;
					}
					else{
						insertNode(-99);
					}
				}
			}
		}
		else if (choice == 2){
			while (1){
				printf("\n\tEnter 1 for pre-order traversal (DFS)\n\tEnter 2 for in-order traversal (DFS)\n\tEnter 3 for post-order traversal (DFS)\n\tEnter 4 for level-order traversal (BFS)\n\tEnter any other to go back: ");
				scanf("%d", &temp);
				if (temp == 1){
					preOrder(root);
				}
				else if (temp == 2){
					inOrder(root);
				}
				else if (temp == 3){
					postOrder(root);
				}
				else if (temp == 4){
					allocateQueue();
					levelOrder(root);
					free(queue);
				}
				else{
					break;
				}
			}
		}
		else{
			break;
		}
	}
	return 0;
}