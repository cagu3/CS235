

#include <iostream>
#include "NodeInterface.h"

class Node : public NodeInterface {

public:
	int value;
	Node *left, *right;

	Node(int data) {
		value = data;
		left = NULL;
		right = NULL;
	}
	~Node() {

	}

	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	int getData() const {
		return value;
	}

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	NodeInterface * getLeftChild() const {
		if (left == NULL) {
			return NULL;
		}
		else {
			return left;
		}
	}

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	NodeInterface * getRightChild() const {
		if (right == NULL) {
			return NULL;
		}
		else {
			return right;
		}
	}

private:
	void setValue(int data) {
		value = data;
	}

	void setLeftChild(Node* data) {
		left = data;
	}

	void setRightChild(Node* data) {
		right = data;
	}

};





