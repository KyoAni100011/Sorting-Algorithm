#include "shaker_sort.h"

void swapValue1 (int &a, int &b){
    int c = a;
    a = b;
    b = c;
}

void shakerSort (int *a, int n, long long int &count_compares){
    int left = 0, right = n - 1, k = -1;   
    count_compares = 0;

    while (++count_compares && left < right){
        int tmp_k = k;

        for (int i = right; ++count_compares &&  i > left; i--){
            if (++count_compares && a[i] < a[i-1]){
                swapValue1 (a[i], a[i-1]);
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