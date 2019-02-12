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
#include "AVLTreeNode.h"

AVLTreeNode:: AVLTreeNode()
{
    nodeItem = 0;
    leftPointer = NULL;
    rightPointer = NULL;
}

AVLTreeNode:: AVLTreeNode(const int &newItem)
{
    nodeItem = newItem;
    leftPointer = NULL;
    rightPointer = NULL;
    height = 0;
}

AVLTreeNode:: AVLTreeNode(const int &newItem, AVLTreeNode* newLeft, AVLTreeNode* newRight)
{
    nodeItem = newItem;
    leftPointer = newLeft;
    rightPointer = newRight;
}
void AVLTreeNode:: setItem( const int& newItem)
{
    nodeItem = newItem;
}
int AVLTreeNode:: getItem() const
{
    return nodeItem;
}

AVLTreeNode* AVLTreeNode::  getLeftChildPtr() const
{
    return leftPointer;
}
AVLTreeNode* AVLTreeNode::  getRightChildPtr() const
{
    return rightPointer;
}
void AVLTreeNode:: setLeftChildPtr(AVLTreeNode* leftPtr)
{
    leftPointer = leftPtr;
}
int AVLTreeNode:: getHeight()
{
    return height;
}
void AVLTreeNode:: setRightChildPtr(AVLTreeNode* rightPtr)
{
    rightPointer = rightPtr;
}
void AVLTreeNode:: setHeight(int heightNew)
{
    height = heightNew;
}
