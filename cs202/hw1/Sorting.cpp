/*
*	Title : Algorithm Efficiency and Sorting
*	Author : Asuman Aydin
*   ID : 21502604
*	Section : 01
*	Assignment : 1
*	Description : Source file of Sorting codes
*/

#include <iostream>
using namespace std;
#include "Sorting.h"
#include <string>
#include <stdlib.h>
#include <ctime>

const int MAX_SIZE = 21001;

//print array
void printArray(int *arr, int arraySize)
{
    for(int i = 0; i < arraySize; i++)
    {
        cout<< arr[i] << " " << endl;
    }
}

//insertion sort
void  insertionSort(int *arr, int first, int last, int &compCount, int &moveCount)
{
    for(int i = first +1; i < last +1 ; i++ )
    {
        for(; (i > 0) && (arr[i-1] > arr[i]); compCount++,i--)
        {
            int temp =  arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = temp;
            moveCount += 3;
        }
        compCount++; // to see f it will enter the for statement, it makes comparison in for
    }
}

//mergeSort
void  mergeSort(int *arr, int first, int last, int &compCount, int &moveCount)
{
    if (first < last)
    {
        int mid = (first + last)/2;
        mergeSort(arr, first, mid, compCount, moveCount);
        mergeSort(arr, mid+1, last,compCount, moveCount);
        mergeSorted( arr, first,  mid, last,compCount, moveCount);
    }
}
void mergeSorted( int* arr, int first, int mid, int last,int &compCount, int &moveCount)
{
    int *tempArray = new int[MAX_SIZE];
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;
    moveCount = moveCount + 1;
    for ( ; (first1 <= last1) && (first2 <= last2);  ++index)
    {
        if (arr[first1] < arr[first2])
        {
            compCount++;
            tempArray[index] = arr[first1];
            moveCount++;
            ++first1;
        }
        else
        {
            tempArray[index] = arr[first2];
            moveCount++;
            ++first2;
        }
        compCount++; // to see if it will enter the if statement, it makes comparison in if
    }
    //FIRST SUBARRAY IF STAYS
    for (; first1 <= last1; ++first1, ++index)
    {
        tempArray[index] = arr[first1];
        moveCount++;
    }
    //SECOND SUBARRAY IF STAYS
    for (; first2 <= last2; ++first2, ++index)
    {
        tempArray[index] = arr[first2];
        moveCount++;
    }
    //COPY
    for (index = first; index <= last; ++index)
    {
        arr[index] = arr[index];
        moveCount++;
    }
}

//QUICK SORT
void  quickSort(int *arr, int first, int last, int &compCount, int &moveCount)
{
    int pivotIndex ;
    if(first < last)
    {
        partitionQuick(arr, first, last, pivotIndex, compCount, moveCount);
        quickSort(arr, first, pivotIndex-1, compCount, moveCount);
        quickSort(arr, pivotIndex+1, last,compCount, moveCount);
    }
}
void swapToSort(int* arr, int first, int last, int &moveCount)
{
    int temp = arr[first];
    arr[first] = arr[last];
    arr[last] = temp;
    moveCount += 3;
}
void  partitionQuick(int* arr, int first, int last,int &pivotIndex,int &compCount, int &moveCount)
{
    swapToSort(arr,first,last,moveCount);
    int pivot = arr[first];
    int lastS1 = first;
    int firstValue = first +1;
    moveCount ++;
    for ( ; firstValue <= last; firstValue++)
    {
        if (arr[firstValue] <  pivot)
        {
            compCount++;
            ++lastS1;
            swapToSort(arr,firstValue, lastS1,moveCount);
        }
        compCount++; // to see if it will enter the if statement, it makes comparison in if
    }
    swapToSort(arr, first,lastS1,moveCount);
    pivotIndex = lastS1;
}
//HYBRIDSORT
void  hybridSort(int *arr, int first, int last, int &compCount, int &moveCount)
{
    int pivotIndex;
    if (last - first + 1 < 10)
    {
        insertionSort(arr, first, last,compCount,moveCount);
    }
    else
    {
        partitionQuick(arr, first, last,pivotIndex,compCount,moveCount);
        quickSort(arr, first, pivotIndex - 1,compCount,moveCount);
        quickSort(arr, pivotIndex + 1, last,compCount,moveCount);
    }
}
void  performanceAnalysis(int arraySize)
{
    int keyComparison,dataMoves = 0;

    int *Array = new int[arraySize];
    //step 1 rand
    for(int i = 0; i < arraySize ; i++)
    {
        Array[i] = rand() % 100 + 30;
    }
    //step2 ascending
//   for(int i = 0; i < arraySize; i++)
//   {
//       Array[i] = i+3;
//    }
    //step3 descending
//    int increment = 0;
//    for(int i = arraySize-1; i>= 0; i--)
//    {
//
//        Array[i] = increment+30;
//        increment++;
//    }

    double duration;
    clock_t startTime = clock();

    //insertionSort(Array, 0, arraySize-1,keyComparison,dataMoves);
    //mergeSort(Array,0,arraySize-1,keyComparison,dataMoves);
    //quickSort(Array,0,arraySize-1,keyComparison,dataMoves);
    //hybridSort(Array,0,arraySize-1,keyComparison,dataMoves);

    duration =  1000* double( clock() - startTime ) / (CLOCKS_PER_SEC);
    cout << "time: "  << duration  << " miliseconds" << endl;
    cout<< "InsertionSort: compCount: " << keyComparison << " " << "moveCount: " << dataMoves << endl;
}
