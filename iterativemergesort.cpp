/**
 @file iterativemergesort.cpp
 This is the source file for the iterative version of the merge sort.
 It will sort using the merge method without using any recursions.
 It will use one temporary array to swap the merge the array back and forth.
 
 @section ASSIGNEMT Lab4
 @section DUE_DATE 23 Feb 2014
 @source: http://penguin.ewu.edu/cscd300/Topic/AdvSorting/MergeSorts/MergeIter.html
 @author: S. Sahni
 @edited by: Sean Lai and Sai Badey
 */

#ifndef ITERATIVEMERGESORT_CPP
#define ITERATIVEMERGESORT_CPP
using namespace std;

// prototype functions
void iterativeMergeSort (int* array, int arraySize);
void mergePass (int sourceArray[], int mergeArray[], int segmentSize, int arraySize);
void merge (int* sourceArray, int* mergeArray, int left, int middle, int right);

/**
 * The merge sort function that iteratively merge an int array.
 * It will pass in the segment ints into an temp array to merge.
 
 * @param array - The array to be sorted.
 * @param arraySize - Size of the array, must be > 0.
 */
void iterativeMergeSort (int* array, int arraySize)
{
    if (arraySize > 0){
        int segmentSize = 1;   // segment size
        int* tempArray = new int[arraySize];
        
        while (segmentSize < arraySize)
        {  mergePass (array, tempArray, segmentSize, arraySize); // merge from a to b
            segmentSize += segmentSize;                 // double the segment size
            mergePass (tempArray, array, segmentSize, arraySize); // merge from b to a
            segmentSize += segmentSize;                 // again, double the segment size
        }
        delete [] tempArray;
    }
}

/**
 * Function will merge sort the segment that's passed in.
 * Calls the merge function to merge the segment back and forth.
 
 * @param array - The array to be sorted.
 * @param arraySize - Size of the array, must be > 0.
 */
void mergePass (int sourceArray[], int mergeArray[], int segmentSize, int arraySize)
{
    // Merge adjacent segments of size s.
    int adjacentSegments = 0;
    
    while (adjacentSegments <= arraySize - 2 * segmentSize)
    {//Merge two adjacent segments of size s
        merge (sourceArray, mergeArray, adjacentSegments, adjacentSegments+segmentSize-1,
               adjacentSegments+2*segmentSize-1);
        adjacentSegments = adjacentSegments + 2*segmentSize;
    }
    // fewer than 2s elements remain
    if (adjacentSegments + segmentSize < arraySize)
        merge (sourceArray, mergeArray, adjacentSegments, adjacentSegments+segmentSize-1, arraySize-1);
    else
        for (int j = adjacentSegments; j <= arraySize-1; j++)
            mergeArray[j] = sourceArray[j];   // copy last segment to y
}

/**
 * Merge function will sort the segment of the merge. It will use left, mid and right
 * point and swap elements until it's merged, then it will combine the elements.
 *
 * @param sourceArray - Array that's before the switch
 * @param mergeArray - Array that the elements are merged into
 * @param left - left element cursor for first segment
 * @param middle - middle element cursor for first segment
 * @param right - right element cursor for first segment
 */
void merge (int* sourceArray, int* mergeArray, int left, int middle, int right)
{
    int leftPoint = left,       // cursor for first segment
    midPoint = middle+1,     // cursor for second
    rightPoint = left;       // cursor for result
    
    // merge until i or j exits its segment
    while ( (leftPoint <= middle) && (midPoint <= right) )
        if (sourceArray[leftPoint]<(sourceArray[midPoint])){
            mergeArray[rightPoint++] = sourceArray[leftPoint++];
        }
    
        else  {
            mergeArray[rightPoint++] = sourceArray[midPoint++];
        }
    
    // take care of left overs --- tjr code:  only one while loop actually runs
    while ( leftPoint <= middle ){
        mergeArray[rightPoint++] = sourceArray[leftPoint++];
    }
    while ( midPoint <= right ){
        mergeArray[rightPoint++] = sourceArray[midPoint++];
    }
}
#endif
