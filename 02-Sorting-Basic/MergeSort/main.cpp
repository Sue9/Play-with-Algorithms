#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "InsertionSort.h"
#include "MergeSort.h"

using namespace std;

//BU = bottom up
template <typename T>
void mergeSortBU(T arr[], int n){
    for(int size = 1; size <= n; size += size){
        for(int j = 0; j+size< n ; j += 2*size){
            //merge arr[i...i+size-1] and arr[i+size...i+2*size-1]
            __merge(arr, j, j+size-1, min(j+2*size-1, n-1));
        }
    }

}


int main() {


    int n = 50000;
    cout << "Test for Random Array, size = " << n << ", random range [0, "<< n <<"]"<< endl;
    int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);

    delete[] arr1;
    delete[] arr2;

    cout << endl;


    int swapTimes = 10;
    cout<<"Test for Nearly Ordered Array, size = " << n <<" , swap time = " << swapTimes << endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);

    delete[] arr1;
    delete[] arr2;

    cout << endl;

    return 0;
}