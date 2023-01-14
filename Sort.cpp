#include "sort.h"

void activateSort(char *sort_type, int *a, int n)
{
    if (!strcmp(sort_type, "selection-sort"))
        selectionSort(a, n);
    else if (!strcmp(sort_type, "insertion-sort"))
        insertionSort(a, n);
    else if (!strcmp(sort_type, "bubble-sort"))
        bubbleSort(a, n);
    else if (!strcmp(sort_type, "shaker-sort"))
        shakerSort(a, n);
    else if (!strcmp(sort_type, "shell-sort"))
        shellSort(a, n);
    else if (!strcmp(sort_type, "heap-sort"))
        heapSort(a, n);
    else if (!strcmp(sort_type, "merge-sort"))
        mergeSort(a, 0, n - 1);
    else if (!strcmp(sort_type, "quick-sort"))
        quickSort(a, 0, n - 1);
    else if (!strcmp(sort_type, "counting-sort"))
        countingSort(a, n);
    else if (!strcmp(sort_type, "radix-sort"))
        radixSort(a, n);
    else if (!strcmp(sort_type, "flash-sort"))
        flashSort(a, n);
    else if (!strcmp(sort_type, "binary-insertion-sort"))
        binaryInsertionSort(a, n);
}

void selectionSort(int *a, int n)
{
    int max;
    for (int i = n - 1; i > 0; i--)
    {
        max = i;
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[j] > a[max])
            {
                max = j;
            }
        }
        if (max != i)
        {
            swap(a[max], a[i]);
        }
    }
}

int binarySearch(int *a, int x, int l, int r)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (x == a[mid])
            return mid + 1;
        else if (x > a[mid])
            l = mid + 1;
        else if (x < a[mid])
            r = mid - 1;
    }

    return l;
}

void binaryInsertionSort(int *a, int n)
{
    int loc, j, k, key;

    for (int i = 1; i < n; i++)
    {
        j = i - 1;
        key = a[i];

        loc = binarySearch(a, key, 0, j);

        while (j >= loc)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void insertionSort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i;
        while ((j > 0) && (a[j - 1] > key))
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = key;
    }
}

void bubbleSort(int *a, int n)
{
    for (int j = 1; j < n; j++)
    {
        bool flag = false;
        for (int i = n - 1; i >= j; i--)
        {
            if (a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                flag = true;
            }
        }
        if (!flag)
            break;
    }
}

void shakerSort(int *a, int n)
{
    int left = 0, right = n - 1, k = -1;

    while (left < right)
    {
        int tmp_k = k;

        for (int i = right; i > left; i--)
        {
            if (a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                k = i - 1;
            }
        }

        if (tmp_k == k)
            break;

        left = k + 1;

        for (int i = left; i < right; i++)
        {
            if (a[i + 1] < a[i])
            {
                swap(a[i], a[i + 1]);
                k = i + 1;
            }
        }

        right = k - 1;
    }
}

void shellSort(int *a, int n)
{
    int j, temp;
    for (int gap = n / 2; gap > 0; gap /= 2)
    {

        for (int i = gap; i < n; i += 1)
        {
            temp = a[i];
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
            {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }
}

void heapify(int *a, int n, int i)
{
    int left = 2 * i + 1, right = 2 * i + 2, largest = i;
    if (left < n && a[left] > a[largest])
    {
        largest = left;
    }
    if (right < n && a[right] > a[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(a[largest], a[i]);
        heapify(a, n, largest);
    }
}

void heapSort(int *a, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[i], a[0]);
        heapify(a, i, 0);
    }
}

void merge(int *a, int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid + 1 - left, n2 = right - mid;
    int *L = new int[n1], *R = new int[n2];

    for (int m = 0; m < n1; m++)
        L[m] = a[left + m];
    for (int m = 0; m < n2; m++)
        R[m] = a[mid + 1 + m];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] >= R[j])
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

    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
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

int partition(int *a, int left, int right)
{
    swap(a[right], a[(left + right) / 2]);

    int j = left - 1;
    for (int i = left; i <= right - 1; i++)
    {
        if (a[i] < a[right])
        {
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[j + 1], a[right]);
    return j + 1;
}

void quickSort(int *a, int left, int right)
{
    if (left < right)
    {
        int pivot = partition(a, left, right);

        quickSort(a, left, pivot - 1);
        quickSort(a, pivot + 1, right);
    }
}

void countingSort(int *a, int n)
{
    int max = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    max = max + 1;

    int *b = new int[max]{0}, *c = new int[max]{0}, *d = new int[n]{0};
    for (int i = 0; i < n; i++)
    {
        b[a[i]]++;
    }

    int sum = 0;

    for (int i = 0; i < max; i++)
    {
        sum = sum + b[i];
        c[i] = sum;
    }

    for (int i = 0; i < n; i++)
    {
        d[c[a[i]] - b[a[i]]] = a[i];
        b[a[i]]--;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = d[i];
    }

    delete[] b;
    delete[] c;
    delete[] d;
}

int countDigitNumMax(int *a, int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    int count = 0;
    while (max > 0)
    {
        max = max / 10;
        count++;
    }
    return count;
}

void radixSort(int *a, int n)
{
    int c = countDigitNumMax(a, n);
    int f = 1;
    for (int d = 0; d < c; d++)
    {
        int **b = new int *[10];
        for (int i = 0; i < 10; i++)
        {
            b[i] = new int[n + 1];
        }

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                b[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++)
        {
            int k = (a[i] / f) % 10;
            b[k][0]++;
            b[k][b[k][0]] = a[i];
        }

        int k = 0;
        for (int i = 0; i < 10; i++)
        {
            if (b[i][0] != 0)
            {
                for (int j = 1; j <= b[i][0]; j++)
                {
                    a[k] = b[i][j];
                    k++;
                }
            }
        }

        f *= 10;
        for (int i = 0; i < 10; i++)
        {
            delete[] b[i];
        }
        delete[] b;
    }
}

void flashSort(int *a, int n)
{
    int m, minVal, max;
    int *l;
    double c1;

    m = int(0.45 * n);

    l = new int[m];
    for (int i = 1;i < m; i++)
        l[i] = 0;

    minVal = a[0];
    max = 0;

    for (int i = 1; i < n; i++)
    {
        if (a[i] < minVal)
            minVal = a[i];
        if (a[i] > a[max])
            max = i;
    }

    if (a[max] == minVal)
    {
        return;
    }

    c1 = (double)(m - 1) / (a[max] - minVal);

    l[0] = -1;

    for (int i = 0; i < n; i++)
    {
        int k = floor(c1 * (a[i] - minVal));
        l[k]++;
    }

    for (int i = 1; i < m; i++)
        l[i] += l[i - 1];

    swap(a[max], a[0]);

    int nmove = 0;
    int j = 0;
    int k = m - 1;
    float flash;

    while (nmove < n)
    {
        while (j > l[k])
        {
            j++;
            k = floor(c1 * (a[j] - minVal));
        }

        flash = a[j];

        while (j <= l[k])
        {
            k = floor(c1 * (flash - minVal));
            int hold = a[l[k]];
            a[l[k]] = flash;
            l[k]--;
            flash = hold;
            nmove++;
        }
    }

    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int loc = i;
        while ((loc > 0) && (a[loc - 1] > key))
        {
            a[loc] = a[loc - 1];
            loc--;
        }
        a[loc] = key;
    }

    delete[] l;
}
