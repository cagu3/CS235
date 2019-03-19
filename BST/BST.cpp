


#include "BST.h"

using namespace std;

	BST::BST() {
		root = NULL;
		size = 0;
	}
	BST::~BST() {
		clear();
	}


	bool find(Node *T, int val) {
		if (T == NULL) {
			return false;
		}
		if (T->value == val) {
			return true;
		}
		if (val < T->value) {
			return find(T->left, val);
		}
		if (val > T->value) {
			return find(T->right, val);
		}
	}


	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	NodeInterface * BST::getRootNode() const {
		return root;
	}





	bool BST::insert(Node* &T, int val) {
		if (find(T, val)) {
			return false;
		}
		if (T == NULL) {
			T = new Node(val);
			size++;
			return true;
		}
		if (T->value == val) {
			return false;
		}
		else if (T->value > val) {
			return insert(T->left, val);
		}
		else {
			return insert(T->right, val);
		}
	}
	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool BST::add(int data) {
		return insert(root, data);
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
	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool BST::unInsert(Node* &deletion, int data) {
		if (!find(deletion, data)) {
			return false;
		}
		if (deletion == NULL) {
			return false;
		}
		if (deletion->value < data) {
			return unInsert(deletion->right, data);
		}
		else if (deletion->value > data) {
			return unInsert(deletion->left, data);
		}
		else {
			if (hasNoChildren(deletion)) {
				delete deletion;
				deletion = NULL;
				size--;
				return true;
			}
			else if (hasTwoChildren(deletion)) {
				int n = getHighest(deletion->left);
				unInsert(deletion->left, n);
				deletion->value = n;
				size--;
				return true;
			}
			else if (hasLeftChild(deletion)) {
				Node *curr = deletion;
				deletion = curr->left;
				delete curr;
				size--;
				return true;
			}
			else if (hasRightChild(deletion)) {
				Node *curr = deletion;
				deletion = curr->right;
				delete curr;
				size--;
				return true;
			}
		}
	}

	bool BST::remove(int data) {
		return unInsert(root, data);
	}

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void BST::clear() {
		while (root != NULL) {
			remove(root->value);
		}
	}










