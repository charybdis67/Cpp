/**
* Title : Binary Search Trees
* Author : Asuman Aydin
* ID: 21502604
* Section : 01
* Assignment : 2
* Description : main function
*/

#include "AVLTree.h"
#include "AVLTreeNode.h"
#include "analysis.h"
#include <iostream>
using namespace std;

int main()
{
    heightAnalysis();
    AVLTree* tree = new AVLTree;
    int arr[16] = {5 ,10, 15, 60, 8,40, 2, 30, 17, 12, 74};
    for(int i=0; i<11; i++){
        tree->insertKey(arr[i]);
    }
    cout<< tree->getHeightTree() << endl;
    tree->printNormal();
    tree->deleteKey(30);
    tree->deleteKey(10);
    tree->deleteKey(8);
    tree->deleteKey(74);
    tree->deleteKey(5);
    tree->printNormal();
    return 0;

}

