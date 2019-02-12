/**
* Title : Binary Search Trees
* Author : Asuman Aydin
* ID: 21502604
* Section : 01
* Assignment : 2
* Description : main function
*/

#include "PbBST.h"
#include "PbBSTNode.h"
#include "analysis.h"
#include <iostream>
using namespace std;

int main()
{
    int mainArray[16] =  {7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11, 14, 2, 8, 14, 5};
    PbBST *tree = new PbBST();
    for(int i = 0; i< 16 ; i++)
    {
        tree->insertKey(mainArray[i]);
    }
    cout<< "Nodes are required" << tree->findNodesRequired() << endl;
    tree->deleteKey(7);
    tree->deleteKey(8);
    cout<< "Full Levels are: " << tree->findFullBTLevel() << endl;
    tree->mirrorTree();
    tree->printNormal();
//    tree->printTree();
    cout<< tree->findFullBTLevel() << endl;
    cout<< tree->findNodesRequired() << endl;
    //timeAnalysis();
    return  0;
}
