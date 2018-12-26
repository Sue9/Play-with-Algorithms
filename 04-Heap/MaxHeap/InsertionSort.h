//
// Created by zhaoxu on 2018/11/20.
//

#ifndef MERGESORT_INSERTIONSORT_H
#define MERGESORT_INSERTIONSORT_H
#include <iostream>
#include "SortTestHelper.h"

using namespace std;

template <typename T>
void insertionSort(T arr[], int n){
    for(int i = 1; i < n; i++){
//        for(int j = i; j > 0; j--){
//            if( arr[j] < arr[j - 1])
//                swap(arr[j], arr[j - 1]);
//            else
//                break;
//        }

        T e = arr[i];
        int j;
        for(j = i; j > 0 && arr[j - 1] > e; j--)
            arr[j] = arr[j - 1];
        arr[j] = e;
    }
}


template <typename T>
void insertionSort(T arr[], int l, int r){
    for(int i = l + 1; i <= r; i++){
        T e = arr[i];
        int j;
        for(j = i; j>l && arr[j-1] > e; j--){
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}

#endif //MERGESORT_INSERTIONSORT_H
