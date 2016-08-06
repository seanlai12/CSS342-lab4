/*
@file recursiveMergeSort.cpp
This is the source file for recursive merge sort function for this lab assignment.
It will sort an array of ints from lowest to highest order.
It splits the array into segments and then merges them in sorted order.
It does the splitting and reassembling by calling itself.
This sort has Big O complexity of  O(n log n) for best, worst, and average cases.

@section ASSIGNEMT Lab4
@section DUE_DATE 23 Feb 2014
@source: http://stackoverflow.com/questions/12030683/implementing-merge-sort-in-c
@editted by: Sean Lai and Sai Badey
*/

#ifndef RECURSIVEMERGSORT_CPP
#define RECURSIVEMERGSORT_CPP
#include <iostream>
using namespace std;

void recursiveMergeSort(int* array, int beg, int end);

/**
* recursiveMergeSort function to be called by the main.
* @param array - The array to be sorted.
* @param first - The start index of the sequence to be sorted.
* @param last - The end index of the sequence to be sorted.
*/
void recursiveMergeSort(int* array, int first, int last){
    if (first < last) {// error check
    
        int middle = (first+last)/2;
        recursiveMergeSort(array, first, middle); //calculates middle then calls itself
        recursiveMergeSort(array, middle+1, last);//for the segment before and after mid
                                                  //essentially splits into 2
        
        int indexFirst = first; //make new variables so old ones aren't affected by changesx 
        int indexMid = middle+1;
        int segmentSize = last - first+1;
        int *temp = new int [segmentSize]; //new array where all sorting happens
        
        
        //inserts sorted values into temp array
        for (int traversalIndex = 0; traversalIndex < segmentSize; traversalIndex++) {
            if (indexMid > last || (indexFirst <= middle && array[indexFirst] < array[indexMid])){
                temp[traversalIndex] = array[indexFirst];
                indexFirst++;
            }
            else{
                temp[traversalIndex]=array[indexMid];
                indexMid++;
            }
        }
        
        //transfers contents of the temp array into the original array
        for (int traversalIndex = 0, index = first; traversalIndex < segmentSize; traversalIndex++, index++){
            array[index] = temp[traversalIndex];
        }
        delete temp;
    }
}
#endif
