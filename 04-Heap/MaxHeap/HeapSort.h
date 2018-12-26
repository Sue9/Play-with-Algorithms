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
