#include <iostream>

using namespace std;


//binary search: given a sorted array, find the target
// if the target exists, return its index
// else return -1
template <typename T>
int binarySearch(T arr[], int n, T target){

    //search scope arr[l...r]
    int l = 0, r = n-1;
    while( l <= r){
//        int mid = (l + r) / 2;
        int mid = l + (r - l)  / 2;
        if(arr[mid] == target)
            return mid;
        //search in arr[l...mid-1]
        if(target < arr[mid])
            r = mid - 1;
        //search in arr[mid+1...r]
        else
            l = mid + 1;
    }

    return -1;

}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}