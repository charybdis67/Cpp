/**
* Title : Binary Search Trees
* Author : Asuman Aydin
* ID: 21502604
* Section : 01
* Assignment : 2
* Description : Binary Search Node header file
*/
#include <iostream>
using namespace std;
#ifndef __PBSTNODE_H
#define __PBSTNODE_H

class PbBSTNode
{
private:
    int	nodeItem;
    PbBSTNode* leftPointer;
    PbBSTNode* rightPointer;
public:
    PbBSTNode();
    PbBSTNode(const int& newNodeItem);
    PbBSTNode(const int &assignedItem, PbBSTNode* newLeft, PbBSTNode* newRight);
    friend class PbBST;
};
#endif
