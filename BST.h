// =================================================================
//
// File: bst.h
// Author:
// Date:
//
// =================================================================
#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;
#include "NodeBST.h"

// =================================================================
// Definition of the Binary Search Tree class
// =================================================================
class BST
{
public:
    BST();
    ~BST();
    bool search(int data);
    void add(int data);
    void remove(int data);
    void print(int recorrido);
    int size();
    int getLevel(int data);
    void ancestors(NodeBST *node);
    int height();

private:
    NodeBST *root;
    int howManyChildren(NodeBST *node);
    int succesor(NodeBST *node);
    int predecesor(NodeBST *node);
    void preOrder(NodeBST *node);
    void inOrder(NodeBST *node);
    void postOrder(NodeBST *node);
    void levelByLevel(NodeBST *node);
    void clear(NodeBST *node);
    int sizeHelper(NodeBST *node);
};

// =================================================================
// Constructor. Initializes the root to nullptr.
//
// =================================================================
BST::BST()
{
    root = nullptr;
}

// =================================================================
// Destructor. Deletes the nodes contained in the BST.
//
// =================================================================
BST::~BST()
{
    clear(root);
    root = nullptr;
}

void BST::clear(NodeBST *r)
{
    if (r != nullptr)
    {
        clear(r->getLeft());
        clear(r->getRight());
        delete r;
    }
}

// =================================================================
// Finds the correct successor of a node within the BST.
//
// returns the successor node of a node.
// =================================================================
int BST::succesor(NodeBST *r)
{
    NodeBST *curr = r->getRight();
    while (curr->getLeft() != nullptr)
    {
        curr = curr->getLeft();
    }
    return curr->getData();
}

// =================================================================
// Finds the predecessor of a node within the BST.
//
// returns the predecessor node of a node.
// =================================================================
int BST::predecesor(NodeBST *r)
{
    NodeBST *curr = r->getLeft();
    while (curr->getRight() != nullptr)
    {
        curr = curr->getRight();
    }
    return curr->getData();
}

// =================================================================
// Search for an element within the BST.
//
// @param data, the searched element.
// returns True, if the element is in the BST. False, otherwise.
// =================================================================
bool BST::search(int data)
{
    NodeBST *curr = root;

    while (curr != nullptr)
    {
        if (curr->getData() == data)
        {
            return true;
        }
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }

    return false;
}

// =================================================================
// Add an element within the bst.
//
// @param data, the element to be inserted.
// =================================================================
void BST::add(int data)
{

    NodeBST *curr = root;
    NodeBST *father = nullptr;
    while (curr != nullptr)
    {
        if (curr->getData() == data)
        {
            return;
        }
        father = curr;
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }

    if (father == nullptr)
    {
        root = new NodeBST(data);
    }
    else
    {
        (father->getData() > data) ? father->setLeft(new NodeBST(data)) : father->setRight(new NodeBST(data));
    }
}

// =================================================================
// Remove an elemento, putting a succesor node in its place.
//
// param @data, the element to be removed.
// =================================================================
void BST::remove(int data)
{
    NodeBST *curr = root;
    NodeBST *father = nullptr;

    while (curr != nullptr && curr->getData() != data)
    {
        father = curr;
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }
    if (curr == nullptr)
    {
        return;
    }

    int children = howManyChildren(curr);

    switch (children)
    {
    case 0:
        if (father == nullptr)
        {
            root = nullptr;
        }
        else
        {
            if (data < father->getData())
            {
                father->setLeft(nullptr);
            }
            else
            {
                father->setRight(nullptr);
            }
        }
        delete curr;
        break;
    case 1:
        if (father == nullptr)
        {
            if (curr->getLeft() != nullptr)
            {
                root = curr->getLeft();
            }
            else
            {
                root = curr->getRight();
            }
        }
        else
        {
            if (father->getData() > data)
            {
                if (curr->getLeft() != nullptr)
                {
                    father->setLeft(curr->getLeft());
                }
                else
                {
                    father->setLeft(curr->getRight());
                }
            }
            else
            {
                if (curr->getLeft() != nullptr)
                {
                    father->setRight(curr->getLeft());
                }
                else
                {
                    father->setRight(curr->getRight());
                }
            }
        }
        delete curr;
        break;
    case 2:
        int succ = succesor(curr);
        remove(succ);
        curr->setData(succ);
        break;
    }
}

// =================================================================
// Gets the number of children of a given node.
//
// @param node, the node to determine the number of children.
// =================================================================
int BST::howManyChildren(NodeBST *node)
{
    int children = 0;

    if (node->getLeft() != nullptr)
    {
        children++;
    }
    if (node->getRight() != nullptr)
    {
        children++;
    }
    return children;
}

// =================================================================
// Print the elements from the bst in preorder, inorder, or
// postorder.
//
// @param recorrido, type of traversal:
//          1 - preOrder
//          2 - inOrder
//          3 - postOrder
//          4 - levelByLevel
// =================================================================
void BST::print(int recorrido)
{
    switch (recorrido)
    {
    case 1:
        preOrder(root);
        break;
    case 2:
        inOrder(root);
        break;
    case 3:
        postOrder(root);
        break;
    case 4:
        levelByLevel(root);
        break;
    }
    cout << endl;
}

// =================================================================
// Print the tree in preorder.
//
// @param node, the node to be traversed.
// =================================================================
void BST::preOrder(NodeBST *node)
{
    if (node != nullptr)
    {
        cout << node->getData() << " ";
        preOrder(node->getLeft());
        preOrder(node->getRight());
    }
}

// =================================================================
// Print the tree in inorder.
//
// @param node, the node to be traversed.
// =================================================================
void BST::inOrder(NodeBST *node)
{
    if (node != nullptr)
    {
        inOrder(node->getLeft());
        cout << node->getData() << " ";
        inOrder(node->getRight());
    }
}

// =================================================================
// Print the tree in postorder.
//
// @param node, the node to be traversed.
// =================================================================
void BST::postOrder(NodeBST *node)
{
    if (node != nullptr)
    {
        postOrder(node->getLeft());
        postOrder(node->getRight());
        cout << node->getData() << " ";
    }
}

// =================================================================
// Gets the number of nodes in the BST.
//
// returns size of the BST.
// =================================================================
int BST::size()
{
    return sizeHelper(root);
}

// =================================================================
// Gets the number of nodes descendants of a node in the BST.
//
// returns the number of descendats of a node.
// =================================================================
int BST::sizeHelper(NodeBST *node)
{
    if (node != nullptr)
    {
        return 1 + sizeHelper(node->getLeft()) + sizeHelper(node->getRight());
    }
    else
    {
        return 0;
    }
}

// =================================================================
// Print the tree level by level.
//
// @param node, the node to be traversed.
// =================================================================
void BST::levelByLevel(NodeBST *node)
{
    if (node != nullptr)
    {
        cout << node->getData() << " ";
        postOrder(node->getLeft());
        postOrder(node->getRight());
    }
}

// =================================================================
// Gets the height of the BST.
//
// returns the height of the BST.
// =================================================================
int BST::height()
{
    return 0;
}

// =================================================================
// Prints the ancestros of a node in the BST.
//
// =================================================================
void BST::ancestors(NodeBST *node)
{
}

// =================================================================
// Gets the level of a value in the BST.
//
// returns the level at which the given data is stored, or -1
//         if the data was not found.
// =================================================================
int BST::getLevel(int data)
{
    return 0;
}

#endif /* BST_H */
