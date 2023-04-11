#pragma once
#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void quickSort(int *a, int left, int right)
{
    int x = a[(left + right) / 2];
    int i = left, j = right;

    while (i <= j)
    {
        while (a[i] < x)
        {
            i++;
        }
        while (a[j] > x)
        {
            j--;
        }
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (left < j)
    {
        quickSort(a, left, j);
    }
    if (i < right)
    {
        quickSort(a, i, right);
    }
}
void merge(int *a, int left, int mid, int right) //more easy to understand
{   
    int i = left, j = mid + 1, k = left;
    int *temp = new int [right + 1];

    for (int i = left; i <= right; i++)
    {
        temp[i] = a[i];
    }

    while (i <= mid && j <= right)
    {
        if (temp[i] <= temp[j])
        {
            a[k++] = temp[i++];
        }
        else
        {
            a[k++] = temp[j++];
        }
    }

    while (i <= mid)
    {
        a[k++] = temp[i++];
    }
    while (j <= right)
    {
        a[k++] = temp[j++];
    }

    delete[] temp;
    temp = nullptr;
}
void mergeSort(int *a, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}
void merge1(int *a, int left, int mid, int right) //more memory-efficent
{
    int i = 0, j = 0, k = left;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *subArray1 = new int [n1];
    int *subArray2 = new int [n2];

    for (int i = 0; i < n1; i++)
    {
        subArray1[i] = a[i + left];
    }
    for (int i = 0; i < n2; i++)
    {
        subArray2[i] = a[i + mid + 1];
    }

    while (i < n1 && j < n2)
    {
        if (subArray1[i] <= subArray2[j])
        {
            a[k++] = subArray1[i++];
        }
        else
        {
            a[k++] = subArray2[j++];
        }
    }

    while (i < n1)
    {
        a[k++] = subArray1[i++];
    }
    while (j < n2)
    {
        a[k++] = subArray2[j++];
    }

    delete[] subArray1;
    subArray1 = nullptr;
    delete[] subArray2;
    subArray2 = nullptr;
}
void mergeSort1(int *a, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort1(a, left, mid);
        mergeSort1(a, mid + 1, right);
        merge1(a, left, mid, right);
    }
}
int binarySearch(int *a, int n, int x) //not using recursion
{
    int left = 0, right = n - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (a[mid] == x)
        {
            return mid;
        }
        if (a[mid] <= x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}
int binarySearch(int *a, int n, int left, int right, int x) //using recursion
{
    if (left > right)
    {
        return -1;
    }
    int mid = (left + right) / 2;
    if (a[mid] == x)
    {
        return mid;
    }
    if (a[mid] <= x)
    {
        return binarySearch(a, n, mid + 1, right, x);
    }
    else
    {
        return binarySearch(a, n, left, mid - 1, x);
    }
}
void insertionSort(int *a, int n)
{
    int temp, j;
    for (int i = 1; i < n; i++)
    {
        temp = a[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (temp < a[j])
            {
                a[j+1] = a[j];
            }
            else
            {
                break;
            }
        }
        a[j+1] = temp;
    }
}
void binaryInsertionSort(int *a, int n)
{
    int x;
    for (int i = 1; i < n; i++)
    {
        x = a[i];

        int left = 0, right = i - 1, mid;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (a[mid] <= x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        for (int j = i - 1; j >= left; j--)
        {
            a[j+1] = a[j];
        }

        a[left] = x;
    }
}
void selectionSort(int *a, int n)
{
    int minIndex;

    for (int i = 0; i < n - 1; i++)
    {
        minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }

        swap(a[i], a[minIndex]);
    }
}
void bubbleSort(int *a, int n)
{
    bool flag; //use to stop sorting when "step" is not "n - 1" and the array has already sorted.

    for (int step = 1; step < n; step++)
    {
        flag = false;

        for (int j = 0; j < n - step; j++)
        {
            if (a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
                flag = true;
            }
        }

        if (flag == false)
        {
            break;
        }
    }
}
void shellSort(int *a, int n)
{
    int temp, j;

    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            temp = a[i];
            for (j = i; j >= gap; j -= gap)
            {
                if (temp < a[j - gap])
                {
                    a[j] = a[j - gap];
                }
                else
                {
                    break;
                }
            }
            a[j] = temp;
        }
    }
}
void interchangeSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                swap(a[i], a[j]);
            }
        }
    }
}
void cocktailSort(int *a, int n) //or shakerSort
{
    bool flag; //use to stop sorting when "step" is not "n / 2" and the array has already sorted.
    int j;

    for (int step = 1; step <= n / 2; step++)
    {
        flag = false;

        for (j = step - 1; j < n - step; j++)
        {
            if (a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
                flag = true;
            }
        }

        if (flag == false)
        {
            break;
        }

        for (j; j > step - 1; j--)
        {
            if (a[j] < a[j-1])
            {
                swap(a[j], a[j-1]);
            }
        }
    }
}
int minElement(int *a, int n)
{
    int minElement = a[0];

    for (int i = 1; i < n; i++)
    {
        if (minElement > a[i])
        {
            minElement = a[i];
        }
    }

    return minElement;
}
int maxElement(int *a, int n)
{
    int maxElement = a[0];

    for (int i = 1; i < n; i++)
    {
        if (maxElement < a[i])
        {
            maxElement = a[i];
        }
    }

    return maxElement;
}
void countingSort(int *a, int n)
{
    int min = minElement(a, n);
    int max = maxElement(a, n);
    int range = max - min + 1;

    int *count = new int [range];
    int *temp = new int [n];

    for (int i = 0; i < range; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        count[a[i] - min]++;
    }

    for (int i = 1; i < range; i++)
    {
        count[i] += count[i-1];
    }

    for (int i = 0; i < n; i++) //visualize to understand.
    {
        temp[count[a[i] - min]-- - 1] = a[i];
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = temp[i];
    }

    delete[] count;
    count = nullptr;
    delete[] temp;
    temp = nullptr;
}
void countingSortByDigit(int *a, int n, int digitPlace)
{
    int min = -9;
    int max = 9;
    int range = max - min + 1;

    int *count = new int [range];
    int *temp = new int [n];

    for (int i = 0; i < range; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        count[(a[i] / digitPlace) % 10 - min]++;
    }

    for (int i = 1; i < range; i++)
    {
        count[i] += count[i-1];
    }

    for (int i = n - 1; i >= 0; i--) //visualize to understand.
    {
        temp[count[(a[i] / digitPlace) % 10 - min]-- - 1] = a[i];
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = temp[i];
    }

    delete[] count;
    count = nullptr;
    delete[] temp;
    temp = nullptr;
}
void radixSort(int *a, int n)
{
    int absMin = abs(minElement(a, n));
    int absMax = abs(maxElement(a, n));
    int max = absMax > absMin ? absMax : absMin;

    for (int digitPlace = 1; max / digitPlace > 0; digitPlace *= 10)
    {
        countingSortByDigit(a, n, digitPlace);
    }
}
void heapify(int *a, int n, int i)
{
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[max])
    {
        max = left;
    }

    if (right < n && a[right] > a[max])
    {
        max = right;
    }

    if (max != i)
    {
        swap(a[i], a[max]);
        heapify(a, n, max);
    }
}
void heapSort(int *a, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}
int getNextGap(int gap)
{
    gap = (gap * 10) / 13; //shrink factor k = 1.3
  
    if (gap < 1)
    {
        return 1;
    }

    return gap;
}
void combSort(int *a, int n)
{
    int gap = n;

    bool flag = true; //use to stop sorting when gap = 1.

    while (gap != 1 || flag == true)
    {
        gap = getNextGap(gap);

        flag = false;

        for (int i = 0; i < n - gap; i++)
        {
            if (a[i] > a[i+gap])
            {
                swap(a[i], a[i+gap]);
                flag = true;
            }
        }
    }
}