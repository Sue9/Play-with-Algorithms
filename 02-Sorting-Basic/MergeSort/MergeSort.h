//
// Created by zhaoxu on 2018/11/27.
//

#ifndef MERGESORT_MERGESORT_H
#define MERGESORT_MERGESORT_H



//this function merges two parts: arr[l...mid] and arr[mid+1...r]
template <typename T>
void __merge(T arr[], int l, int mid, int r){
    T aux[r - l + 1];
    for(int i = l; i < r+1; i++ ){
        aux[i-l] = arr[i];
    }

    int i = l, j = mid+1;
    for(int k = l; k <= r; k++){
        if(i > mid){
            arr[k] = aux[j - l];
            j++;
        }
        else if (j > r){
            arr[k] = aux[i - l];
            i++;
        }

        else if(aux[i - l] < aux[j - l]){
            arr[k] = aux[i - l];
            i++;
        }
        else{
            arr[k] = aux[j - l];
            j++;
        }

    }
}




//this function is used for recursive call in mergeSort() only
//it sorts on range [l...r]
//__ stands for private function
template <typename T>
void __mergeSort(T arr[], int l, int r){
//    if (l >= r)
//        return;
    if(r - l <= 15){
        insertionSort(arr, l, r);
        return;
    }


    int mid = (l + r)/ 2;

    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);

    if(arr[mid] > arr[mid+1])
        __merge(arr, l, mid, r);
}


template <typename T>
void mergeSort(T arr[], int n){
    __mergeSort(arr, 0, n - 1);

}


#endif //MERGESORT_MERGESORT_H
