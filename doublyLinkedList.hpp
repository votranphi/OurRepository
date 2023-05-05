#pragma once
#include <iostream>
using namespace std;

struct DNode
{
    int info;
    DNode *pNext;
    DNode *pPrev;
};
struct DList
{
    DNode *pHead;
    DNode *pTail;
};

void init(DList &list)
{
    list.pHead = list.pTail = nullptr;
}
DNode *createNode(const int &value)
{
    DNode *result = new DNode;

    result->info = value;
    result->pNext = nullptr;
    result->pPrev = nullptr;
    return result;
}
bool isEmpty(DList &list)
{
    return list.pHead == nullptr && list.pTail == nullptr;
}
void addToEmpty(DList &list, const int &value)
{
    DNode *newNode = createNode(value);
    list.pHead = list.pTail = newNode;
}
void addHead(DList &list, const int &value)
{
    if (isEmpty(list))
    {
        addToEmpty(list, value);
    }
    else
    {
        DNode *newNode = createNode(value);
        newNode->pNext = list.pHead;
        list.pHead->pPrev = newNode;
        list.pHead = newNode;
    }
}
void addTail(DList &list, const int &value)
{
    if (isEmpty(list))
    {
        addToEmpty(list, value);
    }
    else
    {
        DNode *newNode = createNode(value);
        list.pTail->pNext = newNode;
        newNode->pPrev = list.pTail;
        list.pTail = newNode;
    }
}
void addAfter(DList &list, const int &target, const int &value)
{
    if (isEmpty(list))
    {
        cout << "\nCan't find the value "<<target;
        return;
    }

    DNode *temp = list.pHead;

    while (temp->info != target && temp != nullptr)
    {
        temp = temp->pNext;
    }

    if (temp == nullptr)
    {
        cout << "\nCan't find the value "<<target;
        return;
    }

    if (temp == list.pTail)
    {
        addTail(list, value);
        return;
    }

    DNode *newNode = createNode(value);
    newNode->pNext = temp->pNext;
    temp->pNext->pPrev = newNode;
    temp->pNext = newNode;
    newNode->pPrev = temp;
}
void addBefore(DList &list, const int &target, const int &value)
{
    if (isEmpty(list))
    {
        cout << "\nCan't find the value "<<target;
        return;
    }

    DNode *temp = list.pHead;

    while (temp->info != target && temp != nullptr)
    {
        temp = temp->pNext;
    }

    if (temp == nullptr)
    {
        cout << "\nCan't find the value "<<target;
        return;
    }

    if (temp == list.pHead)
    {
        addHead(list, value);
        return;
    }

    DNode *newNode = createNode(value);
    newNode->pPrev = temp->pPrev;
    temp->pPrev->pNext = newNode;
    newNode->pNext = temp;
    temp->pPrev = newNode;
}
DNode *searchNode(DList &list, const int &value)
{
    if (isEmpty(list))
    {
        cout << "List is empty!" << endl;
        return nullptr;
    }

    DNode *temp = list.pHead;
    while (temp != nullptr && temp->info != value)
    {
        temp = temp->pNext;
    }

    if (temp == nullptr)
    {
        cout << "There's no number " << value << " in the list!" << endl;
        return nullptr;
    }

    return temp;
}
void deleteHead(DList &list)
{
    if (isEmpty(list))
    {
        cout << "List is empty" << endl;
        return;
    }

    DNode *temp = list.pHead;

    if (list.pHead == list.pTail)
    {
        init(list);
        delete temp;
        return;
    }

    list.pHead = list.pHead->pNext;
    list.pHead->pPrev = nullptr;
    temp->pNext = nullptr;
    delete temp;
}
void deleteTail(DList &list)
{
    if (isEmpty(list))
    {
        cout << "List is empty" << endl;
        return;
    }

    DNode *temp = list.pTail;

    if (list.pHead == list.pTail)
    {
        init(list);
        delete temp;
        return;
    }

    list.pTail = list.pTail->pPrev;
    list.pTail->pNext = nullptr;
    temp->pPrev = nullptr;
    delete temp;
}
void deleteNode(DList &list, const int &target)
{
    if (isEmpty(list))
    {
        cout<<"List is empty!"<<endl;
        return;
    }

    DNode *temp = list.pHead;

    if (list.pHead == list.pTail)
    {
        if (list.pHead->info == target)
        {
            init(list);
            delete temp;
            return;
        }
        else
        {
            cout<<"There's no number "<<target<<" to delete!"<<endl;
            return;
        }
    }

    while (temp != nullptr && temp->info != target)
    {
        temp = temp->pNext;
    }

    if (temp == nullptr)
    {
        cout<<"There's no number "<<target<<" to delete!"<<endl;
        return;
    }
    if (temp == list.pHead)
    {
        deleteHead(list);
        return;
    }
    if (temp == list.pTail)
    {
        deleteTail(list);
        return;
    }

    temp->pPrev->pNext = temp->pNext;
    temp->pNext->pPrev = temp->pPrev;
    temp->pPrev = nullptr;
    temp->pNext = nullptr;
    delete temp;
}
void destroyList(DList &list)
{
    DNode *temp = list.pHead;

    while (list.pHead != nullptr)
    {
        list.pHead = list.pHead->pNext;
        delete temp;
        temp = list.pHead;
    }
}
void printList(DList &list)
{
    if (isEmpty(list))
    {
        cout<<"List is empty";
        return;
    }

    DNode *temp = list.pHead;
    while (temp != nullptr)
    {
        cout<<temp->info<<" ";
        temp = temp->pNext;
    }
}