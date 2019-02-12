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
#ifndef __AVLTREENODE_H
#define __AVLTREENODE_H
class AVLTreeNode
{
    int	nodeItem;
    AVLTreeNode* leftPointer;
    AVLTreeNode* rightPointer;
    int height;
public:
    AVLTreeNode();
    AVLTreeNode(const int &newItem);
    AVLTreeNode(const int &newItem, AVLTreeNode* left, AVLTreeNode* right);
    void setItem( const int& newItem);
    int getItem() const;
    int getHeight();
    void setHeight(int heightNew);
    AVLTreeNode* getLeftChildPtr() const ;
    AVLTreeNode* getRightChildPtr() const ;
    void setLeftChildPtr(AVLTreeNode* leftPtr);
    void setRightChildPtr(AVLTreeNode* rightPtr);
    friend class AVLTree;

};
#endif

