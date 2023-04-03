#pragma once
#include <iostream>

struct Node
{
    int data;
    Node *next;
};
struct List
{
    Node *head;
    Node *tail;
};
void initiateList(List &list)
{
    list.head = list.tail = nullptr;
}
bool isEmpty(List &list)
{
    return list.head == nullptr && list.tail == nullptr;
}
Node *createNode(int value)
{
    Node *result = new Node;

    if (result == nullptr)
    {
        std::cout<<"Create node unsuccessfully!";
        return nullptr;
    }

    result->data = value;
    result->next = nullptr;
    return result;
}
void addToEmpty(List &list, int value)
{
    Node *newNode = createNode(value);
    list.head = list.tail = newNode;
}
void addHead(List &list, int value)
{
    if (isEmpty(list))
    {
        addToEmpty(list, value);
    }
    else
    {
        Node *newNode = createNode(value);

        newNode->next = list.head;
        list.head = newNode;
    }
}
void addTail(List &list, int value)
{
    if (isEmpty(list))
    {
        addToEmpty(list, value);
    }
    else
    {
        Node *newNode = createNode(value);

        list.tail->next = newNode;
        list.tail = newNode;
    }
}
void addAfter(List &list, int target, int value)
{
    Node *temp = list.head;
    Node *newNode = createNode(value);

    if (isEmpty(list))
    {
        std::cout<<"List is empty!";
        return;
    }

    while (temp->data != target)
    {
        if (temp != list.tail)
        {
            temp = temp->next;
        }
        else
        {
            std::cout<<"List doesn't have "<<target;
            return;
        }
    }

    if (temp == list.tail)
    {
        addTail(list, value);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}
void addBefore(List &list, int target, int value) //incomplete
{
    Node *temp = list.head;
    Node *newNode = createNode(value);

    if (temp->data == target)
    {
        addHead(list, value);
        return;
    }

    while (temp->next->data != target)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteHead(List &list)
{
    Node *temp = list.head;

    if (isEmpty(list))
    {
        std::cout<<"List is empty!";
        return;
    }

    if (list.head == list.tail)
    {
        delete temp;
        initiateList(list);
        return;
    }

    list.head = list.head->next;
    temp->next = nullptr;
    delete temp;
}
void deleteTail(List &list)
{
    Node *temp = list.head;

    if (isEmpty(list))
    {
        std::cout<<"List is empty!";
        return;
    }

    if (list.head == list.tail)
    {
        delete temp;
        initiateList(list);
        return;
    }
    
    while (temp->next != list.tail)
    {
        temp = temp->next;
    }

    Node *temp1 = list.tail;
    temp->next = nullptr;
    list.tail = temp;
    delete temp1;
}
void deleteNode(List &list, int target)
{
    Node *temp = list.head;

    if (isEmpty(list))
    {
        std::cout<<"List is empty!";
        return;
    }

    if (list.head == list.tail)
    {
        if (list.head->data == target)
        {
            delete temp;
            initiateList(list);
            return;
        }
        else
        {
            std::cout<<"There's no number "<<target<<" to delete";
            return;
        }
    }

    if (temp->data == target)
    {
        deleteHead(list);
        return;
    }

    while (temp->next->data != target)
    {
        if (temp->next != list.tail)
        {
            temp = temp->next;
        }
        else
        {
            std::cout<<"There's no number "<<target<<" to delete";
            return;
        }
    }

    if (temp->next == list.tail)
    {
        deleteTail(list);
        return;
    }

    Node *temp1 = temp->next;
    temp->next = temp->next->next;
    delete temp1;
}
void printList(List &list)
{
    if (isEmpty(list))
    {
        std::cout<<"List is empty!";
        return;
    }

    Node *temp = list.head;
    while (temp != nullptr)
    {
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
}
void destroyList(List &list)
{
    Node *temp = list.head;

    while (list.head != nullptr)
    {
        list.head = list.head->next;
        delete temp;
        temp = list.head;
    }
}