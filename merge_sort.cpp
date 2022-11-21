#include "merge_sort.h"

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