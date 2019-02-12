/**
* Title : Binary Search Trees
* Author : Asuman Aydin
* ID: 21502604
* Section : 01
* Assignment : 2
* Description : PbBSTNode source code file
*/
#include "PbBSTNode.h"
using namespace std;
#include "iostream"

PbBSTNode:: PbBSTNode()
{
    nodeItem = 0;
    leftPointer = NULL;
    rightPointer = NULL;
}
PbBSTNode:: PbBSTNode(const int& newNodeItem)
{
    nodeItem = newNodeItem;
    leftPointer = NULL;
    rightPointer = NULL;
}
PbBSTNode:: PbBSTNode(const int &assignedItem, PbBSTNode* newLeft, PbBSTNode* newRight)
{
    nodeItem = assignedItem;
    leftPointer = newLeft;
    rightPointer = newRight;
}
