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