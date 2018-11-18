//============================================================================
// Name        : SelectionSort.cpp
// Author      : Sue
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include "Student.h"

using namespace std;

template<typename T>

void selectionSort( T arr[], int n ){
	//find min in [i, n)
	for(int i = 0; i < n; i++ ){
		int minIndex = i;
		for(int j = i; j < n; j++){
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}

//		std::swap(arr[i], arr[minIndex]);


		T tp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = tp;

	}

}

int main() {
	//	cout<<"into main"<<endl;
	int a[10] = {10,9,8,7,6,5,4,3,2,1};
	selectionSort(a, 10);

	for(int i = 0; i < 10; i++){
		cout << a[i] << " ";
	}
	cout << endl;


	//float
	float b[4] = {4.4, 3.4, 2.2, 1.1};
	selectionSort(b, 4);

	for(int i = 0; i < 4; i++){
		cout << b[i] << " ";
	}
	cout << endl;


	//string
	string c[4] = {"D", "C", "B", "A"};
	selectionSort(c, 4);

	for(int i = 0; i < 4; i++){
		cout << c[i] << " ";
	}
	cout << endl;

	//Student
	Student d[4] = {{"D", 90}, {"C", 100}, {"B", 95}, {"A", 95}};
	selectionSort(d, 4);
	for(int i = 0; i < 4; i++){
		cout << d[i] << " ";
	}
	cout << endl;

	return 0;


}
