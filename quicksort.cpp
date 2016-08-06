/*
 @file quicksort.cpp
 This is the source file for quicksort function for this lab assignment.
 It will sort an array of ints from lowest to highest order.
 The sorting method will use a pivot and recursively moves smaller element to
 left and bigger element to the right.
 This sort has an average O comparison cases of O(n log n), and O(n^2) for
 worst cases.
 
 @section ASSIGNEMT Lab4
 @section DUE_DATE 23 Feb 2014
 @source: http://gsamaras.wordpress.com/code/quicksort-c/
 @author: G. Samaras
 @edited by: Sean Lai and Sai Badey
 */


#include <iostream>

void quickSort( int array[], int first, int last);
void quickSort(int array[], int first, int last, bool insertion);
int pivot(int array[], int first, int last);
void swap(int& elementA, int& elementB);
void insertionSort(int array[], int arraySize);

using namespace std;

/**
 * quickSort function to be called by the main.
 * Will use the insertionSort instead of quicksort, if the index size is <= 100.
 * @param array - The array to be sorted.
 * @param first - The start index of the sequence to be sorted.
 * @param last - The end index of the sequence to be sorted.
 */
void quickSort(int array[], int first, int last)
{
    bool insertion = false;
    if (last - first <= 100) {
        insertion = true;
    }
    quickSort(array, first, last, insertion);
}

/**
 * Quicksort function, call this to sort an array of int.
 * @param array - The array to be sorted.
 * @param first - The start index of the sequence to be sorted.
 * @param last - The end index of the sequence to be sorted.
 * @param insertion - True if insertion sort is used, false if not.
 */
void quickSort(int array[], int first, int last, bool insertion)
{
    int pivotPoint;
    // It will use insertion sort if index is <= 100.
    if(last - first <= 100 && insertion) {
        insertionSort(array, last - first + 1);
    }
    if (first < last && !insertion) {
        pivotPoint = pivot(array, first, last);
        quickSort(array, first, pivotPoint-1, insertion);
        quickSort(array, pivotPoint+1, last, insertion);
    }
}

/**
 * Find and return the index of pivot element, and calls swap to initiate sort.
 * Then moves the pivot to the middle.
 * @param array - The array.
 * @param first - The start index of the sequence.
 * @param last - The end index of the sequence.
 * @return - the pivot element
 */
int pivot(int array[], int first, int last)
{
    int pivot = first;
    int pivotCheck = array[first];
    
    for(int traversal = first + 1 ; traversal <= last ; traversal++)
    {
        /* If you want to sort the list in the reverse order, change "<=" to ">" */
        if(array[traversal] <= pivotCheck)
        {
            pivot++;
            swap(array[traversal], array[pivot]);
        }
    }
    
    swap(array[pivot], array[first]);
    
    return pivot;
}


/**
 * Swap the parameters in an int array.
 * @param a - The first int.
 * @param b - The second int.
 */
void swap(int& elementA, int& elementB)
{
    int tempElement = elementA;
    elementA = elementB;
    elementB = tempElement;
}

/**
 * The insertion sort, which has an average O comparison of O(n^2)
 * This sort will be used when the index of elements are less than 100, to save
 * time since this method will be faster than quicksort.
 * @param array - The array to be sorted.
 * @param arraySize - the size of the array.
 */
void insertionSort(int array[], int arraySize) {
    if (arraySize > 0) {
        for (int traversal = 1; traversal < arraySize; traversal++) {
            int insertionPoint = traversal;
            while (insertionPoint > 0 && array[insertionPoint - 1] > array[insertionPoint]) {
                swap(array[insertionPoint], array[insertionPoint-1]);
                insertionPoint--;
            }
        }
    }
}
