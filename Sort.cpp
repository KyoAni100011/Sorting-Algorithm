#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void selectionSort(int a[], int n)
{
	int max;
	for(int i = n-1; i > 0; i--)
	{
		max = i;
		for(int j = i-1; j >= 0; j--)
		{
			if(a[j] > a[max])
			{
				max = j;
			}
		}
		if(max != i)
		{
			swap(a[max],a[i]);
		}
	}
}

void heapify(int a[], int n, int i)
{
	int left = 2*i + 1, right = 2*i + 2, largest = i;
	if(left < n && a[left] > a[largest])
	{
		largest = left;
	}
	if(right < n && a[right] > a[largest])
	{
		largest = right;
	}
	if(largest != i)
	{
		swap(a[largest],a[i]);
		heapify(a,n,largest);
	}
}

void heapSort(int a[], int n)
{
	for(int i = n/2 - 1; i >= 0; i--)
	{
		heapify(a,n,i);
	}
	
	for(int i = n - 1; i >= 0; i--)
	{
		swap(a[i],a[0]);
		heapify(a,i,0);
	}
}

void countingSort(int a[], int n)
{
    int max = a[0];
    for(int i = 1; i < n; i++)
	{
        if(a[i] > max)
		{
            max = a[i];
        }
    }
    max = max + 1;
    int b[max] ={0}, c[max] , d[n];
    for(int i = 0; i < n; i++)
	{
        b[a[i]]++;
    }

    cout << endl;
    int sum = 0;
    for(int i = 0; i < max; i++)
	{
        sum = sum + b[i];
        c[i] = sum;
    }
    cout << endl;
    for(int i = 0; i < n; i++)
	{
        d[c[a[i]] - b[a[i]]] = a[i];
        b[a[i]] -- ;
    }

}

void radixSort(int a[], int n)
{
	int exp = 1;
    
    for (int it = 0; it < 9; it++) 
	{
        vector<int> buckets[10];
        
        for (int i = 0; i < n; i++) 
		{
            buckets[(a[i] / exp) % 10].push_back(a[i]);
        }
        
        n = 0;
        for (vector<int> bucket : buckets) 
		{
            for (int v : bucket) 
			{
                a[n++] = v;
            }
        }
        
        exp *= 10;
    }
}

void shellSort(int arr[], int n)
{
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;           
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
			{
                arr[j] = arr[j - gap];
			}
            arr[j] = temp;
        }
    }
}

template<class ItemType>
void insertionSort(ItemType a[], int n)
{
    for (int unsorted = 1; unsorted < n; unsorted++)
    {
        ItemType nextItem = a[unsorted];
        int loc = unsorted;
        while ((loc > 0) && (a[loc - 1] > nextItem))
        {
            a[loc] = a[loc - 1];
            loc--;
        }
        a[loc] = nextItem;
    }
}

int partition(int a[], int l, int r)
{
    int pivot = a[l];
    int i = l - 1;
    int j = r + 1;

    while (1)
    {
        do
        {
            i++;
        } while (a[i] < pivot);
        
        do
        {
            j--;
        } while (a[j] > pivot);
        
        if (i < j)
            swap(a[i], a[j]);
        else
            return j;    
    }
}

// quickSort(a, 0, n - 1);
void quickSort(int a[], int l, int r)
{
    if (l >= r)
        return;

    if (l < r)
    {
        int m = partition(a, l, r);
        quickSort(a, l, m);
        quickSort(a, m + 1, r);
    }
}

void flashSort(int a[], int n)
{
    /* declare variables */
    int m, minVal, max;
    int *l;
    double c1;

    m = int(0.45 * n);   
  
    /* allocate space for the l vector */
    l = new int[m]{};

    /***** CLASS FORMATION ****/

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
        cout << "All the numbers are identical, the list is sorted\n";
        return;
    }
    
    c1 = (double)(m - 1) / (a[max] - minVal);

    l[0]=-1; /* since the base of the "a" (data) array is 0 */
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
			k = floor(c1*(a[j] - minVal));
		}
		flash = a[j];
		while (j <= l[k])
		{
			k = floor(c1*(flash - minVal));
			int hold = a[l[k]];
			a[l[k]] = flash;
            l[k]--;
			flash = hold;
			nmove++;
		}
	}

    /* use insertion sort */
    for (int unsorted = 1; unsorted < n; unsorted++)
    {
        int nextItem = a[unsorted];
        int loc = unsorted;
        while ((loc > 0) && (a[loc - 1] > nextItem))
        {
            a[loc] = a[loc - 1];
            loc--;
        }
        a[loc] = nextItem;
    }
    
    delete[] l; /* need to free the memory we grabbed for the l vector */
}

int main()
{
	return 0;
}
