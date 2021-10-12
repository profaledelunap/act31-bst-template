// =================================================================
//
// File: bst.h
// Author:
// Date:
//
// =================================================================
#ifndef NODEBST_H
#define NODEBST_H

// =================================================================
// Definition of the Node class
// =================================================================
class NodeBST
{
public:
	NodeBST(int data);
	NodeBST(int data, NodeBST *left, NodeBST *right);
	int getData() const;
	NodeBST *getLeft() const;
	NodeBST *getRight() const;
	void setData(int data);
	void setLeft(NodeBST *left);
	void setRight(NodeBST *right);

private:
	int data;
	NodeBST *left;
	NodeBST *right;
};

// =================================================================
// Constructor. Initializes the value of the node. The variables
// left and right a initialized to null.
//
// @param val, stored value in the node.
// =================================================================
NodeBST::NodeBST(int val) : data(val), left(nullptr), right(nullptr)
{
}

// =================================================================
// Constructor. Initializes all instances variables.
//
// @param val, stored value in the node.
// =================================================================
NodeBST::NodeBST(int val, NodeBST *lft, NodeBST *rght) : data(val), left(lft), right(rght)
{
}

// =================================================================
// Gets the data stored in the node.
//
// returns data
// =================================================================
int NodeBST::getData() const
{
	return data;
}

// =================================================================
// Gets the left child of the node.
//
// returns node, corresponding to the left child.
// =================================================================
NodeBST *NodeBST::getLeft() const
{
	return left;
}

// =================================================================
// Gets the right child of the node.
//
// returns node, corresponding to the right child.
// =================================================================
NodeBST *NodeBST::getRight() const
{
	return right;
}

// =================================================================
// Sets the data of the node to val.
//
// @param val, value to be stored in the node.
// =================================================================
void NodeBST::setData(int val)
{
	data = val;
}

// =================================================================
// Sets the left child of the node to lft.
//
// @param lft, new left child of the node.
// =================================================================
void NodeBST::setLeft(NodeBST *lft)
{
	left = lft;
}

// =================================================================
// Sets the left child of the node to rght.
//
// @param rght, new right child of the node.
// =================================================================
void NodeBST::setRight(NodeBST *rght)
{
	right = rght;
}
#endif /* NODEBST_H */
