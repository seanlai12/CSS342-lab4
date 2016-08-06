/**
 @file lab4performance.cpp
 This is the main function file for lab4. It will create an array of random
 int elements with a constant maximum and size, and will perform each four sorts
 to time the difference. The sort methods are iterative merge, recursive merge,
 heap, and quick.
 
 @author Sean Lai
 @author Sai Badey
 @section ASSIGNEMT Lab4
 @section DUE_DATE 23 Feb 2014
 */

#include <iostream>
#include <stdlib.h>
#include <sys/time.h>
#include <ctime>
#include <assert.h>
#include "recursivemergesort.cpp"
#include "iterativemergesort.cpp"
#include "heapsort.cpp"
#include "quicksort.cpp"
using namespace std;

void initArray( int* array, int randMax, int size);

// Constants to change the array initiation.
int const arraySize = 1000;
int const maxRandNumber = 10000;
int const printNumber = 9;

int main(int argc, const char * argv[]){
    
    clock_t clockTimeStart, clockTimeEnd, ticks;
    // Creates the int array and initialize the numbers
    int array[arraySize];
    initArray(array, maxRandNumber, arraySize);
    
    // Runs the recursive merge sort and reports the time.
    clockTimeStart = clock();
    recursiveMergeSort(array,0,arraySize-1);
    clockTimeEnd = clock();
    cout << "Recursive Merge Sort:\n";
    for (int traversal = 0; traversal < printNumber; traversal++){
        cout << array[traversal] << endl;
    }
    for (int traversal = arraySize - printNumber; traversal < arraySize; traversal++){
        cout << array[traversal] << endl;
    }
    
    ticks = clockTimeEnd - clockTimeStart;

    cout << "Recursive Merge Sort takes " << ticks << " clock ticks ~= "
    << (float)ticks / (float)CLOCKS_PER_SEC << " seconds\n";

    cout << endl;
    
    // Runs the iterative merge sort and reports the time.
    initArray(array, maxRandNumber, arraySize);
    clockTimeStart = clock();
    iterativeMergeSort(array, arraySize);
    clockTimeEnd = clock();
    cout << "Iterative Merge Sort:\n";
    for (int traversal = 0; traversal < printNumber; traversal++){
        cout << array[traversal] << endl;
    }
    for (int traversal = arraySize - printNumber; traversal < arraySize; traversal++){
        cout << array[traversal] << endl;
    }
    ticks = clockTimeEnd - clockTimeStart;
    
    cout << "Iterave Merge Sort takes " << ticks << " clock ticks ~= "
    << (float)ticks / (float)CLOCKS_PER_SEC << " seconds\n";
    
    cout << endl;
    
    // Runs the heap sort and reports the time.
    initArray(array, maxRandNumber, arraySize);
    clockTimeStart = clock();
    heapSort(array, arraySize);
    clockTimeEnd = clock();
    cout << "Heap Sort:\n";
    for (int traversal = 0; traversal < printNumber; traversal++){
        cout << array[traversal] << endl;
    }
    for (int traversal = arraySize - printNumber; traversal < arraySize; traversal++){
        cout << array[traversal] << endl;
    }
    
    ticks = clockTimeEnd - clockTimeStart;
    
    cout << "Heap Sort takes " << ticks << " clock ticks ~= "
    << (float)ticks / (float)CLOCKS_PER_SEC << " seconds\n";
    
    // Runs the quick/insertion sort and reports the time. It will run insertion
    // sort only if the array size is less than 100.
    initArray(array, maxRandNumber, arraySize);
    clockTimeStart = clock();
    quickSort(array, 0, arraySize-1);
    clockTimeEnd = clock();
    cout << "Quick/Insertion Sort:\n";
    for (int traversal = 0; traversal < printNumber; traversal++){
        cout << array[traversal] << endl;
    }
    for (int traversal = arraySize - printNumber; traversal < arraySize; traversal++){
        cout << array[traversal] << endl;
    }
    
    ticks = clockTimeEnd - clockTimeStart;
    
    cout << "Quick/Insertion Sort takes " << ticks << " clock ticks ~= "
    << (float)ticks / (float)CLOCKS_PER_SEC << " seconds\n";
    
    
}

/**
 * Array initialization method, copied from the lab4driver.cpp in the lab4files.
 * It will create an array with random numbers.
 * @param array - The array to be initialized.
 * @param randMax - Max element that random number can be reached.
 * @param size - size of the array.
 */
void initArray( int* array, int randMax, int size ) {
    
    for ( int i = 0; i < size; ) {
        int tmp = ( randMax == -1 ) ? rand( ) : rand( ) % randMax;
        bool hit = false;
        for ( int j = 0; j < i; j++ ) {
            if ( array[j] == tmp ) {
                hit = true;
                break;
            }
        }
        if ( hit )
            continue;
        array[i] = tmp;
        i++;
    }
}
