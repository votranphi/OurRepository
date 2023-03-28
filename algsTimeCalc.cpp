#include <iostream>
#include <chrono>
#include <math.h>
#include "myAlgs.hpp"
using namespace std;

int getInteger()
{
    return 1000000 + rand()%1000001;
}
void generateArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = pow(-1, rand() % 2) * rand();
    }
}
void arrayCopy(int *a, int *b, int n) //copy array b[] to array a[].
{
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}
void menu()
{
    cout<<"\n-----------MENU-----------"<<endl;
    cout<<"01. Quick Sort."<<endl;
    cout<<"02. Merge Sort."<<endl;
    cout<<"03. Binary Insertion Sort."<<endl;
    cout<<"04. Insertion Sort."<<endl;
    cout<<"05. Bubble Sort."<<endl;
    cout<<"06. Selection Sort."<<endl;
    cout<<"07. Shell Sort."<<endl;
    cout<<"08. Interchange Sort."<<endl;
    cout<<"09. Cocktail/Shaker Sort."<<endl;
    cout<<"10. Counting Sort."<<endl;
}

int main()
{
    string s;
    clock_t start, end;
    short choose;
    int n = getInteger();
    int *a = new int [n];
    int *b = new int [n];
    generateArray(b, n);
    
    do
    {
        arrayCopy(a, b, n);
        menu();

        cout<<"Please choose one algorithm which you want to calculate the processing time: ";
        cin>>choose;
        while (choose != 1 && choose != 2 && choose != 3 && choose != 4 && choose != 5 && choose != 6 && choose != 7 && choose != 8 && choose != 9 && choose != 10)
        {
            cout<<"There's no algorithm number "<<choose<<". Please choose again: ";
            cin>>choose;
        }

        cout<<"Sorting "<<n<<" elements in the array..."<<endl;

        switch (choose)
        {
            case 1:
                start = clock();
                quickSort(a, 0, n - 1);
                end = clock();
                break;
            case 2:
                start = clock();
                mergeSort(a, 0, n - 1);
                end = clock();
                break;
            case 3:
                start = clock();
                binaryInsertionSort(a, n);
                end = clock();
                break;
            case 4:
                start = clock();
                insertionSort(a, n);
                end = clock();
                break;
            case 5:
                start = clock();
                bubbleSort(a, n);
                end = clock();
                break;
            case 6:
                start = clock();
                selectionSort(a, n);
                end = clock();
                break;
            case 7:
                start = clock();
                shellSort(a, n);
                end = clock();
                break;
            case 8:
                start = clock();
                interchangeSort(a, n);
                end = clock();
                break;
            case 9:
                start = clock();
                cocktailSort(a, n);
                end = clock();
                break;
            case 10:
                start = clock();
                countingSort(a, n);
                end = clock();
                break;
        }

        cout<<"Processing time: "<<(double)(end - start) / 1000<<"s"<<endl;

        cout<<"Do you want to continue (type Y or N): ";
        cin.ignore();
        getline(cin, s);
        while (s != "Y" && s != "y" && s != "N" && s != "n")
        {
            cout<<"Please type Y or N: ";
            getline(cin, s);
        }
    }
    while (s == "y" || s == "Y");

    delete[] a;
    a = nullptr;
    delete[] b;
    b = nullptr;
}