//
// Created by zhaoxu on 2018/11/28.
//
#include <iostream>
#include "InsertionSort.h"

#ifndef QUICKSORT_QUICKSORT_H
#define QUICKSORT_QUICKSORT_H


// //////////////////////////////////////////////////////////////////////////////
//  Quick Sort Three Ways
// //////////////////////////////////////////////////////////////////////////////



template <typename T>
void __quickSort3Ways(T arr[], int l, int r){
    if( r - l <= 15){
        insertionSort(arr, l, r);
        return;
    }


    //partition
    swap(arr[l], arr[rand()%(r-l+1)+l]);
    T v = arr[l];
    int lt = l;     //arr[l+1...lt] < v
    int gt = r+1;   //arr[gt... r]  > v
    int i = l + 1;  //arr[lt+1...i) ==v

    while(i < gt){
        if(arr[i] < v){
            swap(arr[i], arr[lt+1]);
            lt ++;
            i ++;
        }
        else if(arr[i] > v){
            swap(arr[i], arr[gt-1]);
            gt --;
        }
        else{ // arr[i] == v
            i++;
        }

    }

    swap(arr[l], arr[lt]);


    __quickSort3Ways(arr, l, lt-1);
    __quickSort3Ways(arr, gt, r);

}


template <typename T>
void quickSort3Ways(T arr[], int n){
    srand(time(NULL));
    __quickSort3Ways(arr, 0, n-1);
}



// //////////////////////////////////////////////////////////////////////////////
// Quick Sort Two Pointers
// //////////////////////////////////////////////////////////////////////////////

template <typename T>
int __partition2(T arr[], int l, int r){
    swap(arr[l], arr[rand()%(r-l+1)+l]);

    T v = arr[l];

    // arr[l+1...j) <= v ; arr(j...r] >= v
    int i = l+1 ,j = r;

    while(true){
        while(i <= r && arr[i] < v) i++;
        while(j >= l+1 && arr[j] > v) j--;

        if(i > j) break;

        swap(arr[i], arr[j]);
        i ++;
        j --;
    }

    swap(arr[l], arr[j]);

    return j;
}

template <typename T>
void __quickSort2(T arr[], int l, int r){
    if(r - l <= 15)
    {
        insertionSort(arr, l, r);
        return;
    }

    int p2 = __partition2(arr, l, r);
    __quickSort2(arr, l, p2-1);
    __quickSort2(arr, p2+1, r);

    return;
}

template <typename T>
void quickSort2(T arr[], int n){
    srand(time(NULL));
    __quickSort2(arr, 0, n-1);

}




// //////////////////////////////////////////////////////////////////////////////
// Quick sort basic idea
// //////////////////////////////////////////////////////////////////////////////



//do partition on arr[l...r]
//return index p, so that arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template <typename T>
int __partition(T arr[], int l, int r){

    swap( arr[l], arr[rand()% (r - l + 1) + l]);

    T v = arr[l];


    //arr[l+1...j] < v ; arr[j+1...i) > v
    //arr[i] is the current comparison
    int j = l;
    for(int i = l+1; i <= r; i++){
        if(arr[i] < v){
//            swap(arr[i], arr[j+1]);
//            j++;
            swap(arr[++j], arr[i]);
        }
    }

    swap( arr[l], arr[j] );

    return j;
}


//quick sort for arr[l...r]
template <typename T>
void __quickSort(T arr[], int l, int r){
//    if (l >= r)
//        return;

    if(r - l <= 15){
        insertionSort(arr, l, r);
        return;
    }

    int p = __partition(arr, l, r);
    __quickSort(arr, l, p-1);
    __quickSort(arr, p+1, r);
}

template <typename T>
void quickSort(T arr[], int n){
    srand(time(NULL));
    __quickSort(arr, 0, n-1);
}

#endif //QUICKSORT_QUICKSORT_H
