#include <iostream>
#include "MergeSort.h"
#include "SortTestHelper.h"
#include "QuickSort.h"

using namespace std;



int main() {
    int n = 100000;

    cout << "Test for Random Array, size = " << n << ", random range [0, "<< n <<"]"<< endl;
    int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);
    int* arr3 = SortTestHelper::copyIntArray(arr1, n);
    int* arr4 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
//    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 2 pointers", quickSort2, arr3, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr4, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    cout << endl;

    //nearly ordered array
    int swapTimes = 100;
    cout<<"Test for Nearly Ordered Array, size = " << n <<" , swap time = " << swapTimes << endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);


    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
//    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 2 pointers", quickSort2, arr3, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr4, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    cout << endl;

    //have a large amount of same elements
    cout << "Test for Random Array, size = " << n << ", random range [0, "<< 10 <<"]"<< endl;
    arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
//    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 2", quickSort2, arr3, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr4, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    cout << endl;


    return 0;
}