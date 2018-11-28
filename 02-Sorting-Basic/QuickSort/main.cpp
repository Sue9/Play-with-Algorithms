#include <iostream>
#include "MergeSort.h"
#include "SortTestHelper.h"
#include "QuickSort.h"

using namespace std;


template <typename T>
void __quickSort2(T arr[], int l, int r){
    if(r - l <= 15)
    {
        insertionSort(arr, l, r);
        return;
    }

    int v = __partition()

    return;
}

template <typename T>
void quickSort2(T arr[], int n){
    srand(time(NULL));
    __quickSort2(arr, 0, n-1);

}


int main() {
    int n = 50000;

    cout << "Test for Random Array, size = " << n << ", random range [0, "<< n <<"]"<< endl;
    int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

    delete[] arr1;
    delete[] arr2;

    cout << endl;

    int swapTimes = 100;
    cout<<"Test for Nearly Ordered Array, size = " << n <<" , swap time = " << swapTimes << endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

    delete[] arr1;
    delete[] arr2;

    cout << endl;


    cout << "Test for Random Array, size = " << n << ", random range [0, "<< n <<"]"<< endl;
    arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
    arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

    delete[] arr1;
    delete[] arr2;

    cout << endl;


    return 0;
}