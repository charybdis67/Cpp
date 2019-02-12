/**
* Title : Binary Search Trees
* Author : Asuman Aydin
* ID: 21502604
* Section : 01
* Assignment : 2
* Description : source code file of calculation of time
*/
#include "PbBST.h"
#include "PbBSTNode.h"
#include <iostream>
using namespace std;
#include <string>
#include <stdlib.h>
#include <ctime>

void timeAnalysis()
{
    PbBST *tree = new PbBST;
    int shuffleIndex = 0;
    int *timeArray = new int[15000];

    for(int i = 0; i < 15000 ; i++)
    {
        timeArray[i] = rand()%15000;
    }

    cout<< "INSERTION" << endl;
    //insertion
    double durationSum = 0;
    int countNumber = 0;
    for(int i = 0; i< 10; i++)
    {
        double duration;
        clock_t startTime = clock();
        for(int j = countNumber*1500; j < (countNumber+1)*1500; j++)
        {
            tree->insertKey(timeArray[j]);
        }
        countNumber++;
        for(int i = 0; i < 100000000 ; i++){}
        duration =1000* double( clock() - startTime ) / (CLOCKS_PER_SEC);
        durationSum += duration;
        cout << "time: "  << durationSum  << " miliseconds" << endl;
    }


    cout<< "DELETION"  << endl;
    for(int i = 0 ; i< 15000 ; i++)
    {
        shuffleIndex  = rand()%15000;
        int temp =  timeArray[shuffleIndex];
        timeArray[shuffleIndex] = timeArray[i];
        timeArray[i] = temp;
    }
    //deletion
    int deleteCount = 0;
    double sum = 0;
    for(int i = 0; i< 10; i++)
    {
        double duration;
        clock_t startTime = clock();
        for(int j = deleteCount*1500; j < (deleteCount+1)*1500; j++)
        {
            tree->deleteKey(timeArray[j]);
        }
        deleteCount++;
        cout<< tree->getHeight();
        for(int i = 0; i < 100000000 ; i++){}
        duration = 1000* double( clock() - startTime ) / (CLOCKS_PER_SEC);
        sum = sum + duration;
        cout << "time: "  << sum  << " miliseconds" << endl;
    }
}
