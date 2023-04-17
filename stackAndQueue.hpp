#pragma once
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
typedef Node* Stack;

bool isEmpty(Stack &top)
{
    return top == nullptr;
}
void initiateStack(Stack &top)
{
    top = nullptr;
}
Node *createNode(const int &value)
{
    Node *result = new Node;

    if (result == nullptr)
    {
        cout << "Create node unsuccessfully!" << endl;
        return nullptr;
    }

    result->data = value;
    result->next = nullptr;

    return result;
}
void push(Stack &top, const int &value)
{
    Node *newNode = createNode(value);

    if (isEmpty(top))
    {
        top = newNode;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
}
void printStack(Stack &top)
{
    if (isEmpty(top))
    {
        cout << "Stack is empty";
        return;
    }

    Node *temp = top;
    while (temp != nullptr)
    {
        cout << temp->data;
        temp = temp->next;
    }
}
int top(Stack &top)
{
    if (isEmpty(top))
    {
        cout << "Stack is empty";
        return -1;
    }
    else
    {
        return top->data;
    }
}
void pop(Stack &top)
{
    if (isEmpty(top))
    {
        cout << "Stack is empty";
        return;
    }

    Node *temp = top;

    if (top->next == nullptr)
    {
        initiateStack(top);
        delete temp;
        return;
    }

    top = top->next;
    temp->next = nullptr;
    delete temp;
}