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
void initializeStack(Stack &top)
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
        cout << "Stack is empty!" << endl;
        return;
    }

    Node *temp = top;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int peek(Stack &top)
{
    if (isEmpty(top))
    {
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
        cout << "Stack is empty!" << endl;
        return;
    }

    Node *temp = top;

    if (top->next == nullptr)
    {
        initializeStack(top);
        delete temp;
        return;
    }

    top = top->next;
    temp->next = nullptr;
    delete temp;
}



struct Queue
{
    int data;
    Node *front;
    Node *back;
};

bool isEmpty(Queue &queue)
{
    return queue.front == nullptr && queue.back == nullptr;
}
void initializeQueue(Queue &queue)
{
    queue.front = queue.back = nullptr;
}
void push(Queue &queue, const int &value)
{
    Node *newNode = createNode(value);

    if (isEmpty(queue))
    {
        queue.front = queue.back = newNode;
    }
    else
    {
        queue.back->next = newNode;
        queue.back = newNode;
    }
}
void printQueue(Queue &queue)
{
    if (isEmpty(queue))
    {
        cout << "Queue is empty!" << endl;
        return;
    }

    Node *temp = queue.front;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int front(Queue &queue)
{
    if (isEmpty(queue))
    {
        return -1;
    }

    return queue.front->data;
}
int back(Queue &queue)
{
    if (isEmpty(queue))
    {
        return -1;
    }

    Node *temp = queue.front;

    while (temp != queue.back)
    {
        temp = temp->next;
    }

    return temp->data;
}
void pop(Queue &queue)
{
    Node *temp = queue.front;

    if (isEmpty(queue))
    {
        cout << "Queue is empty!" << endl;
        return;
    }

    if (queue.front == queue.back)
    {
        initializeQueue(queue);
        delete temp;
        return;
    }

    queue.front = queue.front->next;
    temp->next = nullptr;
    delete temp;
}