/*
@file heapsort.cpp
This is the source file for heapsort function for this lab assignment.
It will sort an array of ints from lowest to highest order.
It determines the largest int, places it at the front of the array. Then
it inserts this into the front of the sorted portion of the array (which
starts from the end).
This sort has complexity of O( n log (n) ) at best, worst, and average cases.

@section ASSIGNEMT Lab4
@section DUE_DATE 23 Feb 2014
@source: http://crackprogramming.blogspot.com/2012/11/heap-sort-c-implementation.html
@edited by: Sean Lai and Sai Badey
*/


#ifndef HEAPSORT_CPP
#define HEAPSORT_CPP
#include <iostream>
#include <assert.h>

void heapSort(int* array, int size);
void locateLargest(int* array, int first, int last);
void heapify(int* array, int first, int last);

/**
* heapSort function to be called by the main.
* Uses heapify and locateLargest to sort
* @param array - The array to be sorted.
* @param size - The size of the array
*
*This function does the sorting. It calls on function heapify to place the
*largest number at the front. It then takes this number and places it at the
*front of the sorted portion of the array. Eventually the sorted portion of the
*array fills up the whole array.
*/    
void heapSort(int* array, int size)
{
    if (size > 0) {
        assert(array);
        assert(size > 0);

        heapify(array, 0, size-1); //sets largest int at front
        int notSortedPosition = size - 1;
        
        while (notSortedPosition > 0) //while the entire array is not occupied by sorted portion
        {

            int temp = array[notSortedPosition];
            array[notSortedPosition] = array[0];
            array[0] = temp;
            notSortedPosition--; //swaps the largest int of nonsorted (at front) with notSortedPosition 
                                 //this increases size of the sorted elements at the end of the array

            locateLargest(array, 0, notSortedPosition); //updates the largest int at the front
        }
    }
}

/**
* locateLargest is used to determine largest int and place it at front
* so that heapSort can place it in the correct spot
* @param array - The array to be sorted.
* @param first and last - the segment to consider in the array
*/
void locateLargest(int* array, int first, int last)
{
    bool exitLoop = false;
    while ((first*2)+1 <= last && !exitLoop)
    {
        int leftBranch = (first * 2) + 1; //create the branches 
        int rightBranch = leftBranch + 1; 
        int swapIndex = first; //ensures that the largest number will come to front

        //checks to locate largest int
        if (array[swapIndex] < array[leftBranch])
        {
            swapIndex = leftBranch;
        }

        if ((rightBranch <= last) && (array[swapIndex] < array[rightBranch]))
        {
            swapIndex = rightBranch;
        }


        //if swap index changed, the largest was found so it is sent to the front.
        if (swapIndex != first)
        {
            int tempArray = array[first];
            array[first] = array[swapIndex];
            array[swapIndex] = tempArray;
            first = swapIndex;
        }
        //if swap index did not change, it was the largest already
        else
        {
            exitLoop = true;
        }
    }
}

/**
* heapify function used to get largest int at position 0
* @param array - The array to be sorted.
* @param first and last - the segment to consider in the array
* @param middle - the root of the binary tree
* The function looks at the array like a binary tree, sets a place as middle, 
* then branches are made from it
*/
void heapify(int* array, int first, int last)
{
    int middle = (last - first -1)/2; //middle is calculated, then branches made from it
                                      //through the help of locateLargest
    while (middle >= 0)
    {
        locateLargest(array, middle, last);
        middle--;
    }
}

#endif

