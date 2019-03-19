

#include <iostream>
#include "AVL.h"

using namespace std;

AVL::AVL() {
	root = NULL;
}
AVL::~AVL() {
	clear();
}

int AVL::size() {
	return treeSize;
}


NodeInterface * AVL::getRootNode() const {
	return root;
}

bool AVL::has(Node* curr, int data) {
	bool find = false;

	if (curr == NULL){
		return false;
	}

	if (data == curr->value) {
		find = true;
	}
	else if (data < curr->value){
		find = has(curr->left, data);
	}
	else if (data > curr->value){
		find = has(curr->right, data);
	}
	else {
		find = false;
	}
	return find;
}

bool AVL::find(int val){
	if (root == NULL)
	{
		return false;
	}
	else {
		bool find = AVL::has(root, val);
		return find;
	}
}



Node* AVL::insert(Node* &T, int val) {
	if (has(T, val)) {
		return false;
	}
	if (T == NULL) {
		return new Node(val);
	}
	else if (T->value > val) {
		T->left = insert(T->left, val);
		return balance(T);
	}
	else {
		T->right = insert(T->right, val);
		return balance(T);
	}
}

bool AVL::add(int data) {
	if (has(root,data)) {
		return false;
	}
	else {
		root = insert(root, data);
		return true;
	}
}


Node* AVL::balanceHelp(Node* help, Node* curr){
	if (help->right == NULL){
		int swap = curr->value;
		curr->value = help->value;
		help->value = swap;

		Node* savedNode = help->left;
		delete help;
		return balance(savedNode);
	}

	else {
		help->right = AVL::balanceHelp(help->right, curr);
		return balance(help);
	}
}



int getHighest(Node *T) {
	if (T->right == NULL) {
		return T->value;
	}
	else {
		return getHighest(T->right);
	}
}


bool hasNoChildren(Node* curr) {
	if (curr->left == NULL && curr->right == NULL) {
		return true;
	}
	else {
		return false;
	}
}


bool hasTwoChildren(Node* curr) {
	if (curr->left != NULL && curr->right != NULL) {
		return true;
	}
	else {
		return false;
	}
}


bool hasLeftChild(Node* curr) {
	if (curr->left != NULL && curr->right == NULL) {
		return true;
	}
	else {
		return false;
	}
}


bool hasRightChild(Node* curr) {
	if (curr->right != NULL && curr->left == NULL) {
		return true;
	}
	else {
		return false;
	}
}

Node* AVL::unInsert(Node* &deletion, int data) {
	if (data == deletion->value){
			if (deletion->left == NULL ){
				 Node* temp = deletion->right;
				 delete deletion;
				 return balance(temp);
			}
			else{
				deletion->left = AVL::balanceHelp(deletion->left, deletion);
				return balance(deletion);
			}
		}

		if (data < deletion->value){
			deletion->left = unInsert(deletion->left, data);
			return balance(deletion);
		}

		if (data > deletion->value){
			deletion->right = unInsert(deletion->right, data);
			return balance(deletion);
		}
}

bool AVL::remove(int data) {
	if (has(root, data)) {
		root = unInsert(root, data);
		return true;
	}
	else {
		return false;
	}
}


void AVL::RR(Node* first, Node* second) {
		first->right = second->left;
		second->left = first;

		first->updateHeight();
		second->updateHeight();
	}

	void AVL::RL(Node* first, Node* second, Node* third) {
		first->right = third;
		second->left = third->right;
		third->right = second;

		AVL::RR(first, third);

		first->updateHeight();
		second->updateHeight();
		third->updateHeight();
	}

	void AVL::LL(Node* first, Node* second) {
		first->left = second->right;
		second->right = first;

		first->updateHeight();
		second->updateHeight();
	}

	void AVL::LR(Node* first, Node* second, Node* third) {
		first->left = third;
		second->right = third->left;
		third->left = second;

		AVL::LL(first, third);

		first->updateHeight();
		second->updateHeight();
		third->updateHeight();
	}

	Node* AVL::balance(Node* T){
		if (T == NULL) return NULL;
		T->updateHeight();

		if (T->getBalance() > 1) {
			Node* curr = T->right;

			if (curr->getBalance() < 0) {
				Node* c = curr->left;
				AVL::RL(T, curr, c);
				return c;

			} else {
				AVL::RR(T, curr);
				return curr;
			}

		} else if (T->getBalance() < -1) {
			Node* curr = T->left;

			if (curr->getBalance() > 0) {
			 	Node* c = curr->right;
				AVL::LR(T, curr, c);
				return c;

			 } else {
				AVL::LL(T, curr);
				return curr;
			 }

		} else {

			return T;
		}

	}




void AVL::clear() {
	while (root != NULL) {
		remove(root->value);
	}
}















