#include <iostream>
#include <deque>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* root = NULL;
Node* parent = NULL;

Node* search(int item){
	Node* ptr = NULL;
	Node* save = NULL;
	if (root == NULL){
		parent = NULL;
		return NULL;
	}
	else if (item == root->data){
		parent = NULL;
		return root;
	}
	else if (item < root->data){
		ptr = root->left;
		save = root;
	}
	else{
		ptr = root->right;
		save = root;
	}
	while (ptr != NULL){
		if (item == ptr->data){
			parent = save;
			return ptr;
		}
		else if (item < ptr->data){
			save = ptr;
			ptr = ptr->left;
		}
		else{
			save = ptr;
			ptr = ptr->right;
		}
	}
	parent = save;
	return ptr;
}

void insert(int item){
	Node* status = search(item);
	if (status != NULL){
		return;
	}
	else{
		Node* new_node = new Node;
		new_node->data = item;
		new_node->left = NULL;
		new_node->right = NULL;
		if (parent == NULL){
			root = new_node;
		}
		else if (item < parent->data){
			parent->left = new_node;
		}
		else{
			parent->right = new_node;
		}
	}
}

// delete if there is zero or one child node
void del1(Node* n, Node* par){
	Node* child = NULL;
	if (n->left == NULL && n->right == NULL){
		child = NULL;
	}
	else if (n->left != NULL){
		child = n->left;
	}
	else{
		child = n->right;
	}
	if (par != NULL){
		if (n == par->left){
			par->left = child;
		}
		else{
			par->right = child;
		}
	}
	else{
		root = child;
	}
}

// delete if there are two child nodes
void del2(Node* n, Node* par){
	Node* suc = NULL;
	Node* parsuc = NULL;
	Node* save = NULL;
	Node* ptr = n->right;
	while (ptr->left != NULL){
		save = ptr;
		ptr = ptr->left;
	}
	suc = ptr;
	parsuc = save;
	del1(suc, parsuc);
	if (par != NULL){
		if (n == par->left){
			par->left = suc;
		}
		else{
			par->right = suc;
		}
	}
	else{
		root = suc;
	}
	suc->left = n->left;
	suc->right = n->right;
}

void del(int item){
	Node* status = search(item);
	if (status == NULL){
		cout << "Didn't find the item!" << endl;
	}
	else if (status->left != NULL && status->right != NULL){
		del2(status, parent);
	}
	else{
		del1(status, parent);
	}
}

void preOrder(Node* root){
	if (root != NULL){
		cout << root->data << endl;
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(Node* root){
	if (root != NULL){
		inOrder(root->left);
		cout << root->data << endl;
		inOrder(root->right);
	}
}

void postOrder(Node* root){
	if (root != NULL){
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data << endl;
	}
}

void levelOrder(Node* root){
	Node* ptr = NULL;
	deque<Node*> myqueue;
	myqueue.push_back(root);
	while (!myqueue.empty()){
		ptr = myqueue.front();
		cout << ptr->data << " ";
		myqueue.push_back(root->left);
		myqueue.push_back(root->right);
		myqueue.pop_front();
	}
	cout << endl;
}

int height(Node* root){
	if (root == NULL){
		return -1;
	}
	int left_height = height(root->left);
	int right_height = height(root->right);
	int height = max(left_height, right_height) + 1;
	return height;
}

int countNodes(Node* root){
	if (root == NULL){
		return 0;
	}
	int left_count = countNodes(root->left);
	int right_count = countNodes(root->right);
	int count = left_count + right_count + 1;
	return count;
}

int main(){
	int option;
	while (true){
		cout << "1. To insert into the tree" << endl;
		cout << "2. preOrder traversal" << endl;
		cout << "3. inOrder traversal" << endl;
		cout << "4. postOrder traversal" << endl;
		cout << "5. To delete an item" << endl;
		cout << "6. To calculate the height of the tree" << endl;
		cout << "7. To count the nodes" << endl;
		cout << "8. To quit the program" << endl;
		cout << "Enter: ";
		cin >> option;
		if (option == 1){
			int item;
			cout << "Enter item to insert: ";
			cin >> option;
			insert(option);
		}
		else if (option == 2){
			preOrder(root);
		}
		else if (option == 3){
			inOrder(root);
		}
		else if (option == 4){
			postOrder(root);
		}
		else if (option == 5){
			int item;
			cout << "Enter the item to delete: ";
			cin >> item;
			del(item);
		}
		else if (option == 6){
			cout << "Height: " << height(root) << endl;
		}
		else if (option == 7){
			cout << "No. of nodes: " << countNodes(root) << endl;
		}
		else if (option == 8){
			break;
		}
		else{
			cout << "Invalid option. Try again..." << endl;
		}
	}
	return 0;
}