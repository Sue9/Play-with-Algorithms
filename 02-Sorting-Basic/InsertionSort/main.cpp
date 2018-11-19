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

int main() {

    int n = 10000;
    int *arr = SortTestHelper::generateNearlyOrderedArray(n, 100);
    int *arr2= SortTestHelper::copyIntArray(arr, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n);
    SortTestHelper::testSort("Selection Sort", SortTestHelper::selectionSort, arr2, n);

    delete[] arr;
    delete[] arr2;

    return 0;
}