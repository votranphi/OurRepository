// 22120165 - Le Anh Khoi
#include <iostream>
#include <time.h>

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

void init(List &list)
{
    list.head = list.tail = nullptr;
}

bool isEmpty(List list)
{
    return list.head == nullptr && list.tail == nullptr;
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

void addToEmpty(List &list, int x)
{
    Node *newNode = createNode(x);
    list.head = list.tail = newNode;
}

void addHead(List &list, int x)
{
    if (isEmpty(list))
        addToEmpty(list, x);
    else
    {
        Node *newNode = createNode(x);
        newNode->next = list.head;
        list.head = newNode;
    }
}

void addTail(List &list, int x)
{
    if (isEmpty(list))
    {
        addToEmpty(list, x);
    }
    else
    {
        Node *newNode = createNode(x);
        list.tail->next = newNode;
        list.tail = newNode;
    }
}

void printList(List &list)
{
    if (isEmpty(list))
    {
        cout << "List is empty!";
        return;
    }
    Node *temp = list.head;
    while (temp != nullptr)
    {
        cout << temp->data << ' ';
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

void addMid(List &list, int target, int value)
{
    Node *runner = list.head;
    Node *newNode = createNode(value);

    while (runner->data != target)
    {
        runner = runner->next;
    }

    newNode->next = runner->next;
    runner->next = newNode;
}

void printMaxima(List list)
{
    if (isEmpty(list))
    {
        cout << "List is empty!";
        return;
    }

    if (list.head->next == nullptr)
    {
        cout << list.head->data;
        return;
    }

    if (list.head->data > list.head->next->data)
    {
        cout << list.head->data << ' ';
    }

    Node *prevI = list.head;
    Node *i = list.head->next;
    Node *nextI = list.head->next->next;

    while (nextI != nullptr)
    {
        if (prevI->data < i->data && i->data > nextI->data)
        {
            cout << i->data << ' ';
        }

        nextI = nextI->next;
        i = i->next;
        prevI = prevI->next;
    }
}

void changeToNearestRightLargest(List &list)
{
    Node *i = list.head;

    while (i != nullptr)
    {

        Node *j = i;
        while (j != nullptr)
        {
            if (j->data > i->data)
            {
                i->data = j->data;
                break;
            }
            j = j->next;
        }

        i = i->next;
    }
}

void printMaximaAroundFourElements(List list)
{
    return;
}

int main()
{
    srand(time(NULL));
    List list;
    init(list);

    addToEmpty(list, rand() % 100 + 20);

    for (int i = 0; i < rand() % 20 + 1; ++i)
    {
        addTail(list, rand() % 100 + 20);
    }

    printList(list);

    cout << '\n';

    printMaxima(list);

    cout << '\n';

    changeToNearestRightLargest(list);

    printList(list);
    destroyList(list);

    return 0;
}