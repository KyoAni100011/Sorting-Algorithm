#include "sortCompare.h"

void activateSortCount(char *sort_type, int *a, int n, long long int &count_compares)
{
    if (!strcmp(sort_type, "selection-sort"))
        selectionSortCount(a, n, count_compares);
    else if (!strcmp(sort_type, "insertion-sort"))
        insertionSortCount(a, n, count_compares);
    else if (!strcmp(sort_type, "bubble-sort"))
        bubbleSortCount(a, n, count_compares);
    else if (!strcmp(sort_type, "shaker-sort"))
        shakerSortCount(a, n, count_compares);
    else if (!strcmp(sort_type, "shell-sort"))
        shellSortCount(a, n, count_compares);
    else if (!strcmp(sort_type, "heap-sort"))
        heapSortCount(a, n, count_compares);
    else if (!strcmp(sort_type, "merge-sort"))
        mergeSortCount(a, 0, n - 1, count_compares);
    else if (!strcmp(sort_type, "quick-sort"))
        quickSortCount(a, 0, n - 1, count_compares);
    else if (!strcmp(sort_type, "counting-sort"))
        countingSortCount(a, n, count_compares);
    else if (!strcmp(sort_type, "radix-sort"))
        radixSortCount(a, n, count_compares);
    else if (!strcmp(sort_type, "flash-sort"))
        flashSortCount(a, n, count_compares);
    else if (!strcmp(sort_type, "binary-insertion-sort"))
        binaryInsertionSortCount(a, n, count_compares);
}

void selectionSortCount(int *a, int n, long long int &count_compares)
{
    
    int max;

    for (int i = n - 1; ++count_compares && i > 0; i--)
    {
        max = i;
        for (int j = i - 1; ++count_compares && j >= 0; j--)
        {
            if (++count_compares && a[j] > a[max])
            {
                max = j;
            }
        }
        if (++count_compares && max != i)
        {
            swap(a[max], a[i]);
        }
    }
}
int binarySearchCount(int *a, int x, int l, int r, long long int &count_compares)
{
    while (++count_compares && l <= r)
    {
        int mid = (l + r) / 2;
        if (++count_compares && x == a[mid])
            return mid + 1;
        else if (++count_compares && x > a[mid])
            l = mid + 1;
        else if (++count_compares && x < a[mid])
            r = mid - 1;
    }

    return l;
}

void binaryInsertionSortCount(int *a, int n, long long int &count_compares)
{
    int loc, j, k, key;

    for (int i = 1; ++count_compares && i < n; i++)
    {
        j = i - 1;
        key = a[i];

        loc = binarySearchCount(a, key, 0, j, count_compares);

        while (++count_compares && j >= loc)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void insertionSortCount(int a[], int n, long long int &count_compares)
{
    

    for (int i = 1; ++count_compares && i < n; i++)
    {
        int key = a[i];
        int loc = i;
        while ((++count_compares && (loc > 0)) && (++count_compares && (a[loc - 1] > key)))
        {
            a[loc] = a[loc - 1];
            loc--;
        }
        a[loc] = key;
    }
}

void bubbleSortCount(int *a, int n, long long int &count_compares)
{
    

    for (int j = 1; ++count_compares && j < n; j++)
    {
        bool flag = false;

        for (int i = n - 1; ++count_compares && i >= j; i--)
        {
            if (++count_compares && a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                flag = true;
            }
        }

        if (++count_compares && !flag)
            break;
    }
}

void shakerSortCount(int *a, int n, long long int &count_compares)
{
    int left = 0, right = n - 1, k = -1;
    

    while (++count_compares && left < right)
    {
        int tmp_k = k;

        for (int i = right; ++count_compares && i > left; i--)
        {
            if (++count_compares && a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                k = i - 1;
            }
        }

        if (++count_compares && tmp_k == k)
            break;

        left = k + 1;

        for (int i = left; ++count_compares && i < right; i++)
        {
            if (++count_compares && a[i + 1] < a[i])
            {
                swap(a[i], a[i + 1]);
                k = i + 1;
            }
        }

        right = k - 1;
    }
}

void shellSortCount(int arr[], int n, long long int &count_compares)
{
    
    int temp;
    int j;

    for (int gap = n / 2; gap > 0 && ++count_compares; gap /= 2)
    {

        for (int i = gap; i < n && ++count_compares; i += 1)
        {
            temp = arr[i];

            for (j = i; (++count_compares && j >= gap) && (++count_compares && arr[j - gap] > temp); j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void mergeCount(int *a, int left, int mid, int right, long long int &count_compares)
{
    int i, j, k;
    int n1 = mid + 1 - left, n2 = right - mid;
    int *L = new int[n1], *R = new int[n2];

    for (int m = 0; ++count_compares && m < n1; m++)
        L[m] = a[left + m];
    for (int m = 0; ++count_compares && m < n2; m++)
        R[m] = a[mid + 1 + m];

    i = 0;
    j = 0;
    k = left;

    while ((++count_compares && i < n1) && (++count_compares && j < n2))
    {
        if (++count_compares && L[i] >= R[j])
        {
            a[k] = R[j];
            j++;
        }
        else
        {
            a[k] = L[i];
            i++;
        }
        k++;
    }

    while (++count_compares && i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (++count_compares && j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSortCount(int *a, int l, int r, long long int &count_compares)
{
    if (++count_compares && l < r)
    {
        int m = (l + r) / 2;
        mergeSortCount(a, l, m, count_compares);
        mergeSortCount(a, m + 1, r, count_compares);
        mergeCount(a, l, m, r, count_compares);
    }
}

void heapifyCount(int *a, int n, int i, long long int &count_compares)
{
    int left = 2 * i + 1, right = 2 * i + 2, largest = i;
    if ((++count_compares && left < n) && (++count_compares && a[left] > a[largest]))
    {
        largest = left;
    }
    if ((++count_compares && right < n) && (++count_compares && a[right] > a[largest]))
    {
        largest = right;
    }
    if (++count_compares && largest != i)
    {
        swap(a[largest], a[i]);
        heapifyCount(a, n, largest, count_compares);
    }
}

void heapSortCount(int *a, int n, long long int &count_compares)
{
    
    for (int i = n / 2 - 1; ++count_compares && i >= 0; i--)
    {
        heapifyCount(a, n, i, count_compares);
    }

    for (int i = n - 1; ++count_compares && i >= 0; i--)
    {
        swap(a[i], a[0]);
        heapifyCount(a, i, 0, count_compares);
    }
}

int partitionCount(int *a, int left, int right, long long int &count_compares)
{
    swap(a[right], a[(left + right) / 2]);
    int j = left - 1;
    for (int i = left; ++count_compares && i <= right - 1; i++)
    {
        if (++count_compares && a[i] < a[right])
        {
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[j + 1], a[right]);
    return j + 1;
}

void quickSortCount(int *a, int left, int right, long long int &count_compares)
{
    if (++count_compares && left < right)
    {
        int pivot = partitionCount(a, left, right, count_compares);

        quickSortCount(a, left, pivot - 1, count_compares);
        quickSortCount(a, pivot + 1, right, count_compares);
    }
}

void countingSortCount(int *a, int n, long long int &count_compares)
{
    
    int max = a[0];

    for (int i = 1; i < n && ++count_compares; i++)
    {
        if (++count_compares && a[i] > max)
        {
            max = a[i];
        }
    }

    max = max + 1;
    int *b = new int[max]{0}, *c = new int[max]{0}, *d = new int[n]{0};

    for (int i = 0; i < n && ++count_compares; i++)
    {
        b[a[i]]++;
    }

    int sum = 0;

    for (int i = 0; i < max && ++count_compares; i++)
    {
        sum = sum + b[i];
        c[i] = sum;
    }

    for (int i = 0; i < n && ++count_compares; i++)
    {
        d[c[a[i]] - b[a[i]]] = a[i];
        b[a[i]]--;
    }
    for (int i = 0;++count_compares && i < n; i++)
    {
        a[i] = d[i];
    }

    delete[] c;
    delete[] b;
    delete[] d;
}

int countDigitNumMax(int *a, int n, long long int &count_compares)
{
    int max = a[0];
    for (int i = 1; i < n && ++count_compares; i++)
    {
        if (++count_compares && a[i] > max)
        {
            max = a[i];
        }
    }
    int count = 0;
    while (++count_compares && max > 0)
    {
        max = max / 10;
        count++;
    }
    return count;
}

void radixSortCount(int *a, int n, long long int &count_compares)
{
    int c = countDigitNumMax(a, n, count_compares);
    int f = 1;
    for (int d = 0; d < c && ++count_compares; d++)
    {
        int **b = new int *[10];
        for (int i = 0; i < 10 && ++count_compares; i++)
        {
            b[i] = new int[n + 1];
        }

        for (int i = 0; i < 10 && ++count_compares; i++)
        {
            for (int j = 0; j < n + 1 && ++count_compares; j++)
            {
                b[i][j] = 0;
            }
        }

        for (int i = 0; i < n && ++count_compares; i++)
        {
            int k = (a[i] / f) % 10;
            b[k][0]++;
            b[k][b[k][0]] = a[i];
        }

        int k = 0;
        for (int i = 0; i < 10 && ++count_compares; i++)
        {
            if (++count_compares && b[i][0] != 0)
            {
                for (int j = 1; j <= b[i][0] && ++count_compares; j++)
                {
                    a[k] = b[i][j];
                    k++;
                }
            }
        }
        f *= 10;
        for (int i = 0; i < 10 && ++count_compares; i++)
        {
            delete[] b[i];
        }
        delete[] b;
    }
}

void flashSortCount(int a[], int n, long long int &count_compares)
{
    int m, minVal, max;
    int *l;
    double c1;

    m = int(0.45 * n);

    l = new int[m];
    for (int i = 1;++count_compares && i < m; i++)
        l[i] = 0;
        
    minVal = a[0];
    max = 0;

    for (int i = 1; ++count_compares && i < n; i++)
    {
        if (++count_compares && a[i] < minVal)
            minVal = a[i];
        if (++count_compares && a[i] > a[max])
            max = i;
    }

    if (++count_compares && a[max] == minVal)
    {
        return;
    }

    c1 = (double)(m - 1) / (a[max] - minVal);

    l[0] = -1;

    for (int i = 0; ++count_compares && i < n; i++)
    {
        int k = floor(c1 * (a[i] - minVal));
        l[k]++;
    }

    for (int i = 1; ++count_compares && i < m; i++)
        l[i] += l[i - 1];

    swap(a[max], a[0]);

    int nmove = 0;
    int j = 0;
    int k = m - 1;
    float flash;

    while (++count_compares && nmove < n)
    {
        while (++count_compares && j > l[k])
        {
            j++;
            k = floor(c1 * (a[j] - minVal));
        }
        flash = a[j];
        while (++count_compares && j <= l[k])
        {
            k = floor(c1 * (flash - minVal));
            int hold = a[l[k]];
            a[l[k]] = flash;
            l[k]--;
            flash = hold;
            nmove++;
        }
    }

    for (int i = 1; ++count_compares && i < n; i++)
    {
        int key = a[i];
        int loc = i;
        while ((++count_compares && (loc > 0)) && (++count_compares && (a[loc - 1] > key)))
        {
            a[loc] = a[loc - 1];
            loc--;
        }
        a[loc] = key;
    }

    delete[] l;
}
