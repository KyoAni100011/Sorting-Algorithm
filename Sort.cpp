#include <isotream>
#include <algorithm>

void selectionSort(int *a, int n)
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

void insertionSort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int loc = i;
        while ((loc > 0) && (a[loc - 1] > key))
        {
            a[loc] = a[loc - 1];
            loc--;
        }
        a[loc] = nextItem;
    }
}


