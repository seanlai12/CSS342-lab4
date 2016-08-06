//
//  lab4test.cpp
//  lab04
//
// @author Sean Lai
// @author Sai Badey
// @section ASSIGNEMT Lab4
// @section DUE_DATE 23 Feb 2014

#include <iostream>
#include <sys/time.h>
#include <ctime>
#include <assert.h>
#include "recursivemergesort.cpp"
#include "iterativemergesort.cpp"
#include "heapsort.cpp"
#include "quicksort.cpp"
using namespace std;

int main(int argc, const char * argv[]){
    int zeroTest[0] = {};
    // Insertion test through quickSort
    int testArray[10] = {-2,3222,322,4,1,-2,-12, 120,99,9999};
    cout << "Before Sort: " << endl;
    for (int i = 0; i < 10; i++){
        cout << testArray[i] << endl;
    }
    cout << endl;
    cout << "After Sort: " << endl;
    quickSort(testArray, 0, 10);
    for (int i = 0; i < 10; i++){
        cout << testArray[i] << endl;
    }
    cout << endl;
    int testArray2[10] = {-2,3222,322,4,1,-2,-12, 120,99,9999};
    cout << "Before Sort: " << endl;
    for (int i = 0; i < 10; i++){
        cout << testArray2[i] << endl;
    }
    cout << endl;
    cout << "After Sort: " << endl;
    insertionSort(testArray2, 10);
    for (int i = 0; i < 10; i++){
        cout << testArray2[i] << endl;
    }
    cout << endl;
    

    // Test cases for array size of 0
    insertionSort(zeroTest, 0);
    heapSort(zeroTest, 0);
    iterativeMergeSort(zeroTest, 0);
    quickSort(zeroTest, 0, 0);
    recursiveMergeSort(zeroTest, 0, 0);
    
    // Test cases for first index > last index
    quickSort(zeroTest, 1, 0);
    recursiveMergeSort(zeroTest, 1, 0);
    
    insertionSort(testArray, -1);
    heapSort(testArray, -1);
    iterativeMergeSort(testArray, -1);
    quickSort(testArray, -1, -1);
    recursiveMergeSort(testArray, -1, -1);
    
    return 0;
}

