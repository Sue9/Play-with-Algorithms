#include <iostream>
#include "MergeSort.h"
#include "SortTestHelper.h"
#include "QuickSort.h"

using namespace std;

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


int main() {
    int n = 100000;

    cout << "Test for Random Array, size = " << n << ", random range [0, "<< n <<"]"<< endl;
    int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);
    int* arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 2 pointers", quickSort2, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    cout << endl;

    int swapTimes = 100;
    cout<<"Test for Nearly Ordered Array, size = " << n <<" , swap time = " << swapTimes << endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 2 pointers", quickSort2, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    cout << endl;


    cout << "Test for Random Array, size = " << n << ", random range [0, "<< 10 <<"]"<< endl;
    arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 2", quickSort2, arr2, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    cout << endl;


    return 0;
}