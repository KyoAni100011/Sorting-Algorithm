#include "sortCompare.h"

// selection, heap sort
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

void bubbleSort (int *a, int n, long long int &count_compares){
    count_compares = 0;

    for (int j = 1; ++count_compares && j < n; j++){
        bool flag = 0; ;

        for (int i = n - 1 ; ++count_compares && i >= j;  i--){
            if (++count_compares && a[i] < a[i-1]) {
                swap(a[i], a[i-1]);
                flag = 1; ;
            }
        }
        
        if (++count_compares  && !flag) break;
    }
}

void shakerSort (int *a, int n, long long int &count_compares){
    int left = 0, right = n - 1, k = -1;   
    count_compares = 0;

    while (++count_compares && left < right){
        int tmp_k = k;

        for (int i = right; ++count_compares &&  i > left; i--){
            if (++count_compares && a[i] < a[i-1]){
                swap(a[i], a[i-1]);
                k = i - 1;
            }
        }

        if (++count_compares && tmp_k == k) break;

        left = k + 1;   

        for (int i = left; ++count_compares &&  i < right; i++){
            if (++count_compares && a[i+1] < a[i]){
                swapValue1 (a[i], a[i+1]);
                k = i + 1; 
            }
        }

        right = k - 1; 
    }
}

void shellSort(int arr[], int n, long long int &count)
{
    for (int gap = n/2; gap > 0 && ++count; gap /= 2 )
    {
       
        for (int i = gap; i < n && ++count; i += 1 )
        {
            int temp = arr[i];
 
            int j;           
            for (j = i; j >= gap && arr[j - gap] > temp && count += 2; j -= gap )
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}


void merge (int* a, int l, int m , int r, long long int &count_compares){
    int first1 = l, last1 = m, first2 = m + 1, last2 = r; 

    int *b = new int [100000];
    int index = l;

    while ((++count_compares && first1 <= last1) && (++count_compares && first2 <= last2)) {
        if (++count_compares && a[first1] < a[first2]) b[index] = a[first1++];
        else b[index] = a[first2++];
        index++;
    }

    while (++count_compares && first1 <= last1){
        b[index++] = a[first1++];   
    }

    while (++count_compares && first2 <= last2) {
        b[index++] = a[first2++];   
    }

    for (int i = l ; ++count_compares && i <= r; i++){
        a[i] = b[i];    
    }

    delete [] b;
}

void mergeSort (int* a, int l, int r, long long int &count_compares ){
    if (l < r){
        int m = (l + r)/2;
        mergeSort (a, l, m, count_compares);
        mergeSort (a, m + 1, r,count_compares);
        merge (a,l,m,r,count_compares);
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
        quickSort(a, l, m);
        quickSort(a, m + 1, r);
    }
}

void countingSort(int a[], int n, long long int &count)
{
    int max = a[0];
    for(int i = 1; i < n && ++count; i++ )
	{
        if( ++count && a[i] > max )
		{
            max = a[i];
        }
    }
    max = max + 1;
    int b[max] ={0}, c[max] , d[n];
    for(int i = 0; i < n && ++count; i++ )
	{
        b[a[i]]++;
    }
    
    int sum = 0;
    for(int i = 0; i < max && ++count; i++ )
	{
        sum = sum + b[i];
        c[i] = sum;
    }
   
    for(int i = 0; i < n && ++count; i++ )
	{
        d[c[a[i]] - b[a[i]]] = a[i];
        b[a[i]] -- ;
    }
}

void radixSort(int a[], int n, long long int &count)
{
	int exp = 1;
    
    for (int it = 0; it < 9 && ++count; it++ ) 
	{
        vector<int> buckets[10];
        
        for (int i = 0; i < n && ++count; i++  ) 
		{
            buckets[(a[i] / exp) % 10].push_back(a[i]);
        }
        
        n = 0;
        for (vector<int> bucket : buckets && ++count) 
		{
            for (int v : bucket && ++count) 
			{
                a[n++] = v;
            }
        }
        
        exp *= 10;
    }
}

void flashSortCount(int a[], int n, long long int &count_compares)
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