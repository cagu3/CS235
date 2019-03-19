#include <string>
#include <iostream>
#include <sstream>
#include "LinkedListInterface.h"

using namespace std;

template<typename T>
class LinkedList : public LinkedListInterface<T>
{

public:


	class Node {
	public:
		T valor;
		Node *next;

		Node(T value) {
			valor = value;
			next = NULL;
		}
		
		~Node() {
		}
	};



	LinkedList(void) {
		head = NULL;
		temano = 0;
	}
	~LinkedList(void) {
		clear();
	}

	/*
	insertHead

	A node with the given value should be inserted at the beginning of the list.

	Do not allow duplicate values in the list.
	*/
	void insertHead(T value) {
		if (dupe(value) == true) {
			return;
		}

		if (head == NULL) {
			head = new Node(value);
			temano++;
			return;
		}
		else {
			Node *n = new Node(value);
			n->next = head;
			head = n;

			temano++;
			return;
		}
	}

	/*
	insertTail

	A node with the given value should be inserted at the end of the list.

	Do not allow duplicate values in the list.
	*/
	void insertTail(T value) {
		if (head == NULL) {
			insertHead(value);
			return;
		}

		if (dupe(value) == true) {
			return;
		}

		Node *curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		if (curr->next == NULL) {
			Node *newNode = new Node(value);
			curr->next = newNode;
			newNode->next = NULL;
		}
		temano++;
	}

	/*
	insertAfter

	A node with the given value should be inserted immediately after the
	node whose value is equal to insertionNode.

	A node should only be added if the node whose value is equal to
	insertionNode is in the list. Do not allow duplicate values in the list.
	*/
	void insertAfter(T value, T insertionNode) {
		if (dupe(value) == true) {
			return;
		}

		Node *curr = head;
		while (curr != NULL) {
			if (curr->valor == insertionNode) {
				Node *newNode = new Node(value);
				newNode->next = curr->next;
				curr->next = newNode;
				temano++;
			}
			curr = curr->next;
		}
	}

	/*
	remove

	The node with the given value should be removed from the list.

	The list may or may not include a node with the given value.
	*/
	void remove(T value) {
		Node *curr = head;
		Node *remove = head;

		if (head == NULL) {
			return;
		}

		if (head->valor == value) {
			curr = curr->next;
			delete remove;
			head = curr;
			temano--;
			return;
		}

		while (curr->next != NULL) {
			if (curr->next->valor == value) {
				remove = curr->next;
				curr->next = remove->next;
				remove->next = NULL;
				delete remove;
				temano--;
				return;
			}
			curr = curr->next;
		}
	}



	/*
	clear

	Remove all nodes from the list.
	*/
	void clear() {
		temano = 0;
		while (head != NULL) {
			Node *n = head->next;
			delete head;
			head = n;
		}
	}

	/*
	at

	Returns the value of the node at the given index. The list begins at
	index 0.

	If the given index is out of range of the list, throw an out of range exception.
	*/
	T at(int index) {
		if (index < 0 || index >= temano) {
			throw std::out_of_range("blah");
		}

		else {
			Node *curr = head;
			int i = 0;

			while (curr != NULL) {
				if (i == index) {
					return curr->valor;
				}
				i++;
				curr = curr->next;
			}
		}
	}

	/*
	size

	Returns the number of nodes in the list.
	*/
	int size() {
		return temano;
	}

	bool dupe(T value) {
		Node *check = head;
		while (check != NULL) {
			if (check->valor == value) {
				return true;
			}
			check = check->next;
		}
		return false;
	}

	/*
	toString
	
	Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
	There should be no trailing space at the end of the string

	For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
	"1 2 3 4 5"
	*/
	string toString() {
		string list = "";
		Node *curr = head;
		int i = 0;

		if (temano == 0) {
			return list;
		}

		while (curr != NULL) {
			stringstream ss;
			ss << curr->valor;
			list.append(ss.str());
			if (i < temano - 1) {
				list.append(" ");
			}
			curr = curr->next;
			i++;
		}
		return list;
	}

private:
	Node *head;
	int temano;

};


