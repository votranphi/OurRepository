void swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
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
void merge(int *a, int left, int mid, int right)
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
    for (int i = 0; i < n; i++)
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
    bool flag;

    for (int i = 1; i < n; i++)
    {
        flag = false;

        for (int j = 0; j < n - i; j++)
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
    bool flag;
    int j;

    for (int i = 1; i <= n / 2; i++)
    {
        flag = false;

        for (j = i - 1; j < n - i; j++)
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

        for (j; j > i - 1; j--)
        {
            if (a[j] < a[j-1])
            {
                swap(a[j], a[j-1]);
            }
        }
    }
}