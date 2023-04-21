#pragma once
#include <iostream>
using namespace std;

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
Node *createNode(const int &value)
{
    Node *result = new Node;

    if (result == nullptr)
    {
        cout<<"Create node unsuccessfully!"<<endl;
        return nullptr;
    }

    result->data = value;
    result->next = nullptr;

    return result;
}
void addToEmpty(List &list, const int &value)
{
    Node *newNode = createNode(value);
    list.head = list.tail = newNode;
}
void addHead(List &list, const int &value)
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
void addTail(List &list, const int &value)
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
void addAfter(List &list, const int &target, const int &value)
{
    Node *temp = list.head;
    Node *newNode = createNode(value);

    if (isEmpty(list))
    {
        cout<<"List is empty!"<<endl;
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
            cout<<"There's no "<<target<<" in the list!"<<endl;
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
void addBefore(List &list, const int &target, const int &value) //incomplete
{
    return;
}
void deleteHead(List &list)
{
    Node *temp = list.head;

    if (isEmpty(list))
    {
        cout<<"List is empty!"<<endl;
        return;
    }

    if (list.head == list.tail)
    {
        initiateList(list);
        delete temp;
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
        cout<<"List is empty!"<<endl;
        return;
    }

    if (list.head == list.tail)
    {
        initiateList(list);
        delete temp;
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
void deleteNode(List &list, const int &target)
{
    Node *temp = list.head;

    if (isEmpty(list))
    {
        cout<<"List is empty!"<<endl;
        return;
    }

    if (list.head == list.tail)
    {
        if (list.head->data == target)
        {
            initiateList(list);
            delete temp;
            return;
        }
        else
        {
            cout<<"There's no number "<<target<<" to delete!"<<endl;
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
            cout<<"There's no number "<<target<<" to delete!"<<endl;
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
    temp1->next = nullptr;
    delete temp1;
}
Node *searchNode(List &list, const int &value)
{
    if (isEmpty(list))
    {
        cout << "List is empty!" << endl;
        return nullptr;
    }

    Node *temp = list.head;
    while (temp != nullptr && temp->data != value)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "There's no number " << value << " in the list!" << endl;
        return nullptr;
    }

    return temp;
}
void printList(List &list)
{
    if (isEmpty(list))
    {
        cout<<"List is empty!"<<endl;
        return;
    }

    Node *temp = list.head;
    while (temp != nullptr)
    {
        cout<<temp->data<<" ";
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

    initiateList(list); //for reusability
}