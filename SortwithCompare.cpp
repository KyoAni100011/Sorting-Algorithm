#include <iostream>
#include <vector>
using namespace std;
void countingSort(int a[], int n, int &count)
{
    int max = a[0];
    for(int i = 1; i < n; i++ && ++count)
	{
        if(a[i] > max && ++count)
		{
            max = a[i];
        }
    }
    max = max + 1;
    int b[max] ={0}, c[max] , d[n];
    for(int i = 0; i < n; i++ && ++count)
	{
        b[a[i]]++;
    }
    
    int sum = 0;
    for(int i = 0; i < max; i++ && ++count)
	{
        sum = sum + b[i];
        c[i] = sum;
    }
   
    for(int i = 0; i < n; i++ && ++count)
	{
        d[c[a[i]] - b[a[i]]] = a[i];
        b[a[i]] -- ;
    }

}

void radixSort(int a[], int n, int &count)
{
	int exp = 1;
    
    for (int it = 0; it < 9; it++ && ++count) 
	{
        vector<int> buckets[10];
        
        for (int i = 0; i < n; i++  && ++count) 
		{
            buckets[(a[i] / exp) % 10].push_back(a[i]);
        }
        
        n = 0;
        for (vector<int> bucket : buckets && ++count) 
		{
            for (int v : bucket &&  ++count) 
			{
                a[n++] = v;
            }
        }
        
        exp *= 10;
    }
}
void shellSort(int arr[], int n, int &count)
{
    for (int gap = n/2; gap > 0; gap /= 2 && ++count)
    {
       
        for (int i = gap; i < n; i += 1 && ++count)
        {
            int temp = arr[i];
 
            int j;           
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap && ++count)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void insertionSort(int a[], int n, long long int &count_compares)
{
    for (int unsorted = 1; ++count_compares && unsorted < n; unsorted++)
    {
        int nextItem = a[unsorted];
        int loc = unsorted;
        while ((++count_compares && (loc > 0)) && (++count_compares && (a[loc - 1] > nextItem)))
        {
            a[loc] = a[loc - 1];
            loc--;
        }
        a[loc] = nextItem;
    }
}

int partition(int a[], int l, int r, long long int &count_compares)
{
    int pivot = a[l];
    int i = l - 1;
    int j = r + 1;

    while (1)
    {
        do
        {
            i++;
        } while (++count_compares && a[i] < pivot);
        
        do
        {
            j--;
        } while (++count_compares && a[j] > pivot);
        
        if (++count_compares && (i < j))
            swap(a[i], a[j]);
        else
            return j;    
    }
}

void quickSort(int a[], int l, int r, long long int &count_compares)
{
    if (++count_compares && l >= r)
        return;

    if (++count_compares && l < r)
    {
        int m = partition(a, l, r, count_compares);
        quickSort(a, l, m, count_compares);
        quickSort(a, m + 1, r, count_compares);
    }
}

void flashSort(int a[], int n, long long int &count_compares)
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
    for (int i = 1; ++count_compares && i < n; i++)
    {
        if (++count_compares && a[i] < minVal)
            minVal = a[i];
        if (++count_compares && a[i] > a[max])
            max = i;
    }

    if (++count_compares && a[max] == minVal)
    {
        cout << "All the numbers are identical, the list is sorted\n";
        return;
    }
    
    c1 = (double)(m - 1) / (a[max] - minVal);

    l[0]=-1; /* since the base of the "a" (data) array is 0 */
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
			k = floor(c1*(a[j] - minVal));
		}
		flash = a[j];
		while (++count_compares && j <= l[k])
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
    for (int unsorted = 1; ++count_compares &&  unsorted < n; unsorted++)
    {
        int nextItem = a[unsorted];
        int loc = unsorted;
        while ((++count_compares && (loc > 0)) && (++count_compares && (a[loc - 1] > nextItem)))
        {
            a[loc] = a[loc - 1];
            loc--;
        }
        a[loc] = nextItem;
    }
    delete[] l;
}

int main()
{
    int n = 10;
    int a[n] = {5,9,4,7,0,6,8,1,2,3};
    int countCS = 0;
    int countRS = 0;
    int countSS = 0;
    countingSort(a,n,countCS);
    radixSort(a,n,countRS);
    shellSort(a,n,countSS);
    cout << "num of compare in Counting Sort: " << countCS << endl;
    cout << "num of compare in Radix Sort: " << countRS << endl;
    cout << "num of compare in Shell Sort: " << countSS << endl;

}