#include "bubble_sort.h"

void swapValue (int &a, int &b){
    int c = a;
    a = b; 
    b = c;
}

void bubbleSort (int *a, int n, long long int &count_compares){
    count_compares = 0;

    for (int j = 1; ++count_compares && j < n; j++){
        bool flag = 0; ;

        for (int i = n - 1 ; ++count_compares && i >= j;  i--){
            if (++count_compares && a[i] < a[i-1]) {
                swapValue (a[i], a[i-1]);
                flag = 1; ;
            }
        }
        
        if (++count_compares  && !flag) break;
    }
}
