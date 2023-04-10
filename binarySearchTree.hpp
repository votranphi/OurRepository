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
int countNodes(Tree root)
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
int countLeafs(Tree root)
{
    int count = 0;

    if (root == nullptr)
    {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        count++;
    }
    else
    {
        count += countLeafs(root->left);
        count += countLeafs(root->right);
    }

    return count;
}
int countInternalNodesIncludeRoot(Tree root)
{
    int count = 0;

    if (root == nullptr)
    {
        return 0;
    }

    if (root->left != nullptr || root->right != nullptr)
    {
        count++;
        count += countInternalNodesIncludeRoot(root->left);
        count += countInternalNodesIncludeRoot(root->right);
    }

    return count;
}
int countInternalNodes(Tree root)
{
    int internalNodesIncludeRoot = countInternalNodesIncludeRoot(root);

    if (internalNodesIncludeRoot == 0)
    {
        return 0;
    }
    else
    {
        return internalNodesIncludeRoot - 1;
    }
}
int countOneChild(Tree root)
{
    int count = 0;

    if (root == nullptr)
    {
        return 0;
    }

    if (root->left != nullptr && root->right == nullptr)
    {
        count++;
        count += countOneChild(root->left);
    }

    if (root->left == nullptr && root->right != nullptr)
    {
        count++;
        count += countOneChild(root->right);
    }

    if (root->left != nullptr && root->right != nullptr)
    {
        count += countOneChild(root->left);
        count += countOneChild(root->right);
    }

    return count;
}
int countTwoChildren(Tree root)
{
    int count = 0;

    if (root == nullptr)
    {
        return 0;
    }

    if (root->left != nullptr && root->right != nullptr)
    {
        count++;
        count += countTwoChildren(root->left);
        count += countTwoChildren(root->right);
    }

    if (root->left != nullptr && root->right == nullptr)
    {
        count += countTwoChildren(root->left);
    }

    if (root->left == nullptr && root->right != nullptr)
    {
        count += countTwoChildren(root->right);
    }
    
    return count;
}