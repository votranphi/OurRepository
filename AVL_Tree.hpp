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

void rotateLeft(Tree &root)
{
    if (root == nullptr)
    {
        cout<< "Can't rotate left bcuz the tree is fucking empty!";
        return;
    }
    if (root->right == nullptr)
    {
        cout<< "Can't rotate left bcuz there is no node right of the root!";
        return;
    }

    Node *oldRoot = root;
    root = root->right;
    oldRoot->right = root->left;
    root->left = oldRoot;
}
void rotateRight(Tree &root)
{
    if (root == nullptr)
    {
        cout<< "Can't rotate left bcuz the tree is fucking empty!";
        return;
    }
    if (root->left == nullptr)
    {
        cout<< "Can't rotate left bcuz there is no node left of the root!";
        return;
    }

    Node *oldRoot = root;
    root = root->left;
    oldRoot->left = root->right;
    root->right = oldRoot;
}
int depthOfTree(const Tree &root)
{
    int depth = 0;

    if (root == nullptr)
    {
        return -1;
    }
    else
    {
        depth++;
        depth += max(depthOfTree(root->left), depthOfTree(root->right));
    }

    return depth;
}
bool isAVL(const Tree &root)
{
    if (root == nullptr)
    {
        return true;
    }

    if (abs(depthOfTree(root->left) - depthOfTree(root->right)) > 1)
    {
        return false;
    }
    else
    {
        return isAVL(root->left) && isAVL(root->right);
    }
}