// KevinsRange.cpp 
/*
use case a
 range1:   [-------]
 range2:   [---------]

use case b
 range1:   [-------]
 range2:   [---]

use case c
 range1:   [------]
 range2:          [----]

use case d
 range1:   [------]
 range2:            [--]

 Hint: since the ranges are sorted, the following use case  is not possible
 range1:              [------]
 range2:            [--]
*/


#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void Merger(int arr[], int arr2[], int lo, int  mi, int hi) {
    int* temp = new int[hi - lo + 1];//temporary merger array
    int* temp2 = new int[hi - lo + 1];//temporary merger array

    int i = lo, j = mi + 1;//i is for left-hand,j is for right-hand
    int k = 0;//k is for the temporary array
    while (i <= mi && j <= hi) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            temp2[k] = arr2[i];
            k = k + 1;
            i = i + 1;
        }
        else {
            temp[k] = arr[j];
            temp2[k] = arr2[j];
            k = k + 1;
            j = j + 1;
        }
    }
    //rest elements of left-half
    while (i <= mi) {
        temp[k] = arr[i];
        temp2[k] = arr2[i];
        k = k + 1;
        i = i + 1;
    }
    //rest elements of right-half
    while (j <= hi) {
        temp[k] = arr[j];
        temp2[k] = arr2[j];
        k = k + 1;
        j = j + 1;

    }
    //copy the mergered temporary array to the original array
    for (k = 0, i = lo; i <= hi; ++i, ++k) {
        arr[i] = temp[k];
        arr2[i] = temp2[k];
    }

    delete[]temp;
    delete[]temp2;
}
void MergeSortHelper(int arr[], int arr2[], int lo, int hi) {
    int mid;
    if (lo < hi) {
        mid = (lo + hi) >> 1;
        MergeSortHelper(arr, arr2, lo, mid);
        MergeSortHelper(arr, arr2, mid + 1, hi);
        Merger(arr, arr2, lo, mid, hi);
    }
}
void MergeSort(int arr[], int arr2[], int arr_size) {
    MergeSortHelper(arr, arr2, 0, arr_size - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    int* start = NULL;
    int* end = NULL;
    int result[10];
    int i = 0, k = 0, l = 0, z = 0, t = 0, n = 0;
    cin >> t;
    for (z = 0; z < t; z++)
    {
        n = 0;
        cin >> n;
        start = new int[n];
        end = new int[n];
        for (i = 0; i < n; i++) {
            cin >> start[i] >> end[i];
        }

        MergeSort(start, end, n);

        // Calculate result
        result[z] = end[0] - start[0] + 1;
        for (k = 1; k < n; k++) {
            if ((start[k] <= end[k - 1] && end[k] > end[k - 1]) || start[k] == end[k - 1] + 1) {
                result[z] = result[z] + end[k] - end[k - 1]; // use case a or c
            }
            else {
                if (start[k] >= start[k - 1] && end[k] <= end[k - 1]) {  //use case b
                    end[k] = end[k - 1];
                }
                else {
                    if (start[k] > end[k - 1] + 1) {
                        result[z] = result[z] + end[k] - start[k] + 1; //use case d
                    }
                    else {
                        cout << "Not covered use case found. " << start[k] << " " << end[k] << endl;
                    }
                }
            }
        }
        delete[] start;
        delete[] end;
    }
    for (l = 0; l < t; l++)
    {
        cout << result[l] << endl;
    }
    return 0;
}
