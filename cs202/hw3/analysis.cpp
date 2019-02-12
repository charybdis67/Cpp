/**
* Title :
* Author : Asuman Aydin
* ID: 21502604
* Section :
* Assignment : 3
* Description :
*/
#include <iostream>
using namespace std;
#include "analysis.h"
#include "AVLTree.h"
#include "AVLTreeNode.h"
#include <stdlib.h>

void heightAnalysis()
{
    AVLTree *tree = new AVLTree;
    AVLTree* ascendingTree = new AVLTree;
    AVLTree* descendingTree = new AVLTree;

    int *timeArray = new int[80000];
    int *ascending  = new int[80000];
    int *descanding = new int[80000];

    for(int i = 0; i < 80000 ; i++)
    {
        timeArray[i] = rand()%80000;
    }
    //ascending
    for(int i = 0; i < 80000; i++)
    {
       ascending[i] = i+3;
    }
    //descending
    int increment = 0;
    for(int i = 80000-1; i>= 0; i--)
    {
        descanding[i] = increment+30;
        increment++;
    }

    int countNumber = 0;
    int countNumber2 = 0;
    int countNumber3 = 0;
    cout<< "Part b - Height analysis of AVL trees" << endl;
    cout<< "---------------------------------------------------------"<< endl;
    cout<< "Array Size        Random       Ascending      Descending" << endl;
    cout<< "---------------------------------------------------------"<< endl;
    for(countNumber = 0 ; countNumber < 20 && countNumber < 20 && countNumber < 20; countNumber++ ,countNumber2++,countNumber3++)
    {
        cout<< (countNumber+1)*4000 << "               " ;
//        for(int j = countNumber*8000; j < (countNumber+1)*8000; j++)
//        {
//            tree->insertKey(timeArray[j]);
//        }
//        cout << tree->getHeightTree() << "       ";
        for(int j = countNumber2*4000; j < (countNumber2+1)*4000; j++)
        {
            ascendingTree->insertKey(ascending[j]);
        }
        cout <<"                " << ascendingTree->getHeightTree() << "       ";
        for(int j = countNumber3*4000; j < (countNumber3+1)*4000; j++)
        {
            descendingTree->insertKey(descanding[j]);
        }
        cout << descendingTree->getHeightTree() << endl;
    }
}

