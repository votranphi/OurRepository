#pragma once
#include <iostream>

using namespace std;

template <class T>
struct Node
{
    T data;
    Node *next;
};

template <class T>
class stack
{
    Node<T> *head;

public:
    stack()
    {
        head = nullptr;
    }

    ~stack()
    {
        while (head != nullptr)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void push(T value)
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    T top()
    {
        return head->data;
    }

    void pop()
    {
        T *temp = head;
        head = head->next;
        delete temp;
    }
};

template <class T>
class queue
{
    Node<T> *head;
    Node<T> *tail;

public:
    queue()
    {
        head = nullptr;
        tail = nullptr;
    }

    ~queue()
    {
        while (head != nullptr)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void push(T value)
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    void pop()
    {
        if (head == nullptr)
        {
            return;
        }

        if (head == tail)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            tail = nullptr;
        }
        else
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }

    T front()
    {
        return head->data;
    }

    bool isEmpty()
    {
        return (head == nullptr) && (tail == nullptr);
    }
};