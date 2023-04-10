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
void initiateTree(Tree &root)
{
    root = nullptr;
}
Node *createNode(int value)
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
void addNode(Tree &root, int value)
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
void listLeafs(Tree root)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        cout<<root->data<<" ";
    }
    else
    {
        listLeafs(root->left);
        listLeafs(root->right);
    }
}
void listInternalNodes(Tree root, bool value)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->left != nullptr || root->right != nullptr)
    {
        if (value == 0)
        {
            value = 1;
        }
        else
        {
            cout<<root->data<<" ";
        }

        listInternalNodes(root->left, value);
        listInternalNodes(root->right, value);
    }
}
void listNodesWithOneChild(Tree root)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->left != nullptr && root->right == nullptr)
    {
        cout<<root->data<<" ";
        listNodesWithOneChild(root->left);
    }

    if (root->left == nullptr && root->right != nullptr)
    {
        cout<<root->data<<" ";
        listNodesWithOneChild(root->right);
    }

    if (root->left != nullptr && root->right != nullptr)
    {
        listNodesWithOneChild(root->left);
        listNodesWithOneChild(root->right);
    }
}
void listNodesWithTwoChildren(Tree root)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->left != nullptr && root->right != nullptr)
    {
        cout<<root->data<<" ";
        listNodesWithTwoChildren(root->left);
        listNodesWithTwoChildren(root->right);
    }

    if (root->left != nullptr && root->right == nullptr)
    {
        listNodesWithTwoChildren(root->left);
    }

    if (root->left == nullptr && root->right != nullptr)
    {
        listNodesWithTwoChildren(root->right);
    }
}