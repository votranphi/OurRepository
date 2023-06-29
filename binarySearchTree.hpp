#pragma once
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
typedef Node* Tree;

Node *createNode(const int &value)
{
    Node *result = new Node;

    if (result == nullptr)
    {
        cout<<"Create node unsuccessfully!"<<endl;
        return nullptr;
    }

    result->data = value;
    result->left = nullptr;
    result->right = nullptr;

    return result;
}
void addNode(Tree &root, const int &value)
{
    if (root == nullptr)
    {
        root = createNode(value);
    }
    else
    {
        if (value < root->data)
        {
            addNode(root->left, value);
        }
        else
        {
            addNode(root->right, value);
        }
    }
}
void NLR(Tree root)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        cout<<root->data<<" ";
        NLR(root->left);
        NLR(root->right);
    }
}
void LRN(Tree root)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        LRN(root->left);
        LRN(root->right);
        cout<<root->data<<" ";
    }
}
void LNR(Tree root)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        LNR(root->left);
        cout<<root->data<<" ";
        LNR(root->right);
    }
}
void RNL(Tree root)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        RNL(root->right);
        cout<<root->data<<" ";
        RNL(root->left);
    }
}
void NRL(Tree root)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        cout<<root->data<<" ";
        NRL(root->right);
        NRL(root->left);
    }
}
Node *search(const Tree &tree, const int &target)
{
    if (tree == nullptr)
    {
        return nullptr;
    }

    if (target < tree->data)
    {
        return search(tree->left, target);
    }
    else if (target > tree->data)
    {
        return search(tree->right, target);
    }
    else
    {
        return tree;
    }
}
int countNodes(const Tree &root)
{
    int count = 0;

    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        count++;
        count += countNodes(root->left);
        count += countNodes(root->right);
    }

    return count;
}
bool isBST(const Tree &root)
{
    if (root->left != nullptr && root->right != nullptr)
    {
        if (root->left->data < root->data && root->right->data > root->data)
        {
            return isBST(root->left) && isBST(root->right);
        }
        else
        {
            return false;
        }
    }

    if (root->left != nullptr && root->right == nullptr)
    {
        if (root->left->data < root->data)
        {
            return isBST(root->left);
        }
        else
        {
            return false;
        }
    }

    if (root->left == nullptr && root->right != nullptr)
    {
        if (root->right->data > root->data)
        {
            return isBST(root->right);
        }
        else
        {
            return false;
        }
    }

    return true;
}
// The replacement node is located all the way to the left on the right subtree
void deleteRoot(Tree &root)
{
    if (root == nullptr)
    {
        return;
    }

    Node *temp = root;
    if (root->left == nullptr && root->right == nullptr)
    {
        delete temp;
        root = nullptr;
        return;
    }
    if (root->left != nullptr && root->right == nullptr)
    {
        root = root->left;
        temp->left = nullptr;
        delete temp;
        return;
    }
    if (root->left == nullptr && root->right != nullptr)
    {
        root = root->right;
        temp->right = nullptr;
        delete temp;
        return;
    }
    
    Node *replaceNode = root->right;
    Node *prevReplaceNode = root;
    while (replaceNode->left != nullptr)
    {
        prevReplaceNode = replaceNode;
        replaceNode = replaceNode->left;
    }

    if (prevReplaceNode->left == replaceNode)
    {
        prevReplaceNode->left = replaceNode->right;
    }
    else
    {
        prevReplaceNode->right = replaceNode->right;
    }

    replaceNode->left = root->left;
    replaceNode->right = root->right;
    root->left = root->right = nullptr;
    root = replaceNode;
    delete temp;
}
// The replacement node is located all the way to the left on the right subtree
void findAndReplaceNode(Tree &root, Tree &replaceNode)
{
    if (replaceNode->left != nullptr)
    {
        findAndReplaceNode(root, replaceNode->left);
    }
    else
    {
        root->data = replaceNode->data;
        root = replaceNode;
        replaceNode = replaceNode->right;
    }
}
void deleteNode(Tree &root, const int &target)
{
    if (root == nullptr)
    {
        return;
    }

    if (target < root->data)
    {
        deleteNode(root->left, target);
    }
    else if (target > root->data)
    {
        deleteNode(root->right, target);
    }
    else
    {
        Node *temp = root;
        if (root->left == nullptr)
        {
            root = root->right;
        }
        else if (root->right == nullptr)
        {
            root = root->left;
        }
        else
        {
            findAndReplaceNode(temp, root->right);
        }
        delete temp;
        return;
    }
}