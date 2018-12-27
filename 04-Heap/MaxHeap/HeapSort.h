//
// Created by zhaoxu on 2018/12/25.
//

#ifndef MAXHEAP_HEAPSORT_H
#define MAXHEAP_HEAPSORT_H
#include <iostream>
#include <ctime>
#include <cassert>
#include <cmath>

#include "Heap.h"



template <typename T>
void __shiftDown(T arr[], int n, int k){
    while(2*k + 1 <= n - 1){
        int j = 2*k + 1;
        if(j+1 <= n-1 && arr[j] < arr[j+1])
            j += 1;
        if(arr[k] >= arr[j])
            break;

        swap(arr[k], arr[j]);
        k = j;
    }
}

template <typename T>
void heapSort(T arr[], int n){
    //heapify
    for(int i = (n-1) / 2; i >= 0; i--){
        __shiftDown(arr, n, i);
    }

    for(int i = n-1; i > 0; i--){
        swap( arr[0], arr[i] );
        __shiftDown(arr, i, 0);
    }
}



template <typename T>
void heapSort1(T arr[], int n){
    MaxHeap<T> maxheap = MaxHeap<T>(n);
    for(int i = 0; i < n; i++){
        maxheap.insert(arr[i]);
    }

    for(int i = n - 1; i >= 0; i--)
        arr[i] = maxheap.extractMax();
}


template <typename T>
void heapSort2(T arr[], int n){
    MaxHeap<T> maxheap = MaxHeap<T>(arr, n);
    for(int i = n - 1; i >= 0; i--)
        arr[i] = maxheap.extractMax();
}

#endif //MAXHEAP_HEAPSORT_H
