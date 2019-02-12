/*
*	Title : Algorithm Efficiency and Sorting
*	Author : Asuman Aydin
* ID : 21502604
*	Section : 01
*	Assignment : 1
*	Description : Header file of Sorting codes
*/

#include <iostream>
#include <string>


//insertion
void insertionSort(int *arr, int first, int last, int &compCount, int &moveCount);
//merge
void mergeSort(int *arr, int first, int last, int &compCount, int &moveCount);
void mergeSorted(int* arr, int first, int mid, int last, int &compCount, int &moveCount);
//quick
void quickSort(int *arr, int first, int last, int &compCount, int &moveCount);
void partitionQuick(int* arr, int first, int last,int &pivotIndex, int &compCount, int &moveCount);
void swapToSort(int* arr, int first, int last, int &moveCount);
//others
void hybridSort(int *arr, int first, int last, int &compCount, int &moveCount);
void performanceAnalysis(int arraySize);
void printArray(int *arr, int arraySize);

