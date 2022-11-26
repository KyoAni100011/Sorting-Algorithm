#include <iostream>
#include <vector>
using namespace std;
void countingSort(int a[], int n, int &count)
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

void radixSort(int a[], int n, int &count)
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
void shellSort(int arr[], int n, int &count)
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