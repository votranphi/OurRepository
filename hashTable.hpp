#pragma once
#include <iostream>
#define MAX 1000
using namespace std;

// Hash Table using Link List with Direct chaining Method
struct node
{
    int key;
    node *next;
    node(const int &value) : key(value), next(nullptr) {}
    node(const int &value, node* next) : key(value), next(next) {}
};
struct Hash
{
    node* bucket[MAX];
    int m; // size of the bucket
};

void initHash(Hash &H)
{
    for (int i = 0; i < MAX; i++)
    {
        H.bucket[i] = nullptr;
    }
}
void insertHash(Hash &H, const int &x)
{
    node *temp = H.bucket[x % H.m];
    if (H.bucket[x % H.m] == nullptr)
    {
        H.bucket[x % H.m] = new node (x);
        return;
    }

    if (x <= temp->key)
    {
        node *temp = H.bucket[x % H.m];
        H.bucket[x % H.m] = new node (x, temp);
        return;
    }

    while (temp->next != nullptr && x > temp->next->key)
    {
        temp = temp->next;
    }

    node *newNode = new node (x);
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteHash(Hash &H, const int &x)
{
    node* temp = H.bucket[x % H.m];
    if (temp == nullptr) // the list at "bucket[x % H.m]" is null
    {
        cout<<"\nKhong co phan tu co khoa "<< x;
        return;
    }

    node* prevTemp = nullptr;
    while (temp != nullptr && temp->key != x) // find the node with value "x"
    {
        prevTemp = temp;
        temp = temp->next;
    }

    if (temp == nullptr)  // "x" is not found
    {
        cout<<"\nKhong co phan tu co khoa "<< x;
        return;
    }

    if (prevTemp == nullptr) // "x" is at the head of the list
    {
        H.bucket[x % H.m] = temp->next;
        temp->next = nullptr;
        delete temp;
        return;
    }

    if (temp->next == nullptr) // "x" is at the tail of the list
    {
        prevTemp->next = nullptr;
        delete temp;
        return;
    }

    // "x" is in the middle of the list
    prevTemp->next = temp->next;
    temp->next = nullptr;
    delete temp;
}
void traverseAllHash(const Hash &H)
{
    for (int i = 0; i < H.m; i++)
    {
        cout << "Bucket " << i <<": ";
        node *temp = H.bucket[i];
        while (temp != nullptr)
        {
            cout << temp->key << ' ';
            temp = temp->next; 
        }
        cout << '\n';
    }
}

// Hash Table using Array with Linear Probing Method

// Hash Table using Array with Quadratic Probing Method

// Hash Table using Array with Double Hash Method