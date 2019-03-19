

#include <iostream>
#include "Node.h"
#include "AVLInterface.h"

using namespace std;


class AVL : public AVLInterface {
public:
	AVL();
	~AVL();

	int size();

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	NodeInterface * getRootNode() const;

	Node* insert(Node* &T, int value);

	bool find(int value);

	bool has(Node* curr, int value);

	/*
	* Attempts to add the given int to the AVL tree
	* Rebalances the tree if data is successfully added
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool add(int data);

	Node* balanceHelp(Node* help, Node* curr);

	Node* unInsert(Node* &T, int x);

	void RR(Node* a, Node* b);
	void RL(Node* a, Node* b, Node* c);
	void LL(Node* a, Node* b);
	void LR(Node* a, Node* b, Node* c);

	/*
	* Attempts to remove the given int from the AVL tree
	* Rebalances the tree if data is successfully removed
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool remove(int data);

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void clear();

	Node* balance(Node* node);

private:
	int treeSize = 0;
	Node* root = NULL;
};



