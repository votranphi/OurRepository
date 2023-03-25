// 22120165 - Le Anh Khoi
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

void init(List &l)
{
    l.head = l.tail = nullptr;
}

bool isEmpty(List l)
{
    return l.head == nullptr && l.tail == nullptr;
}

Node *createNode(int value)
{
    Node *result = new Node;
    result->data = value;
    result->next = nullptr;
    if (result == nullptr)
    {
        cout << "Create node unsuccessfully!";
        return nullptr;
    }
    return result;
}

void addToEmpty(List &l, int x)
{
    Node *newNode = createNode(x);
    l.head = l.tail = newNode;
}

void addToHead(List &l, int x)
{
    if (isEmpty(l))
        addToEmpty(l, x);
    else
    {
        Node *newNode = createNode(x);
        newNode->next = l.head;
        l.head = newNode;
    }
}

void addToTail(List &l, int x)
{
    if (isEmpty(l))
    {
        addToEmpty(l, x);
    }
    else
    {
        Node *newNode = createNode(x);
        l.tail->next = newNode;
        l.tail = newNode;
    }
}

void print(List &l)
{
    Node *temp = l.head;
    while (temp != nullptr)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
}

int main()
{
    List l;
    addToHead(l, 5);
    addToTail(l, 11);
    addToTail(l, 9);
    addToTail(l, 10);
    print(l);
    return 0;
}