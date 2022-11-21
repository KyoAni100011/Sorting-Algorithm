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
int main()
{
	return 0;
}
