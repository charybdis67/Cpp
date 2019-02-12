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
#include <math.h>
#ifndef __AVLTREE_H
#define __AVLTREE_H
class AVLTree
{
public:
    AVLTree();
    AVLTree(const int& rootItem);
    AVLTree(const int& rootItem,AVLTree& leftTreePtr, AVLTree& rightTreePtr);
    AVLTree(const AVLTree& newTree);
    virtual ~AVLTree();
    bool isEmpty() const;
    void insertKey(int val);
    void deleteKey(int val);
    int getHeightTree();
    int getNodeCount();
    int findNodesRequired();
    int findFullBTLevel();
    void mirrorTree();
    void printTree();
    void printNormal();
private:
    AVLTreeNode* root;
    int  getBalance(AVLTreeNode* node)
    {
        if(node== NULL)
        {
            return 0;
        }
        else
        {
            int balance = getHeightHelper(node->leftPointer)- getHeightHelper(node->rightPointer);
            return balance;
        }
    }
    void singleRightRotationNode(AVLTreeNode*& node)
    {
        if(node != NULL)
        {
            AVLTreeNode* k2 = node;
            AVLTreeNode* k1 = node->leftPointer;
            k2->leftPointer = k1->rightPointer;
            k1->rightPointer = k2;
            node = k1;
            k2->setHeight(getHeightHelper(k2));
            k1->setHeight(getHeightHelper(k1));
        }
    }
    void singleLeftRotationNode(AVLTreeNode*& node)
    {
        if(node != NULL)
        {
            AVLTreeNode* k2 = node;
            AVLTreeNode* k1 = node->rightPointer;
            k2->rightPointer = k1->leftPointer;
            k1->leftPointer = k2;
            node = k1;
            k2->setHeight(getHeightHelper(k2));
            k1->setHeight(getHeightHelper(k1));
        }
    }
    void copyTree(AVLTreeNode *treePtr, AVLTreeNode* &newTree) const
    {
        if(treePtr != NULL)
        {
            newTree = new AVLTreeNode(treePtr->nodeItem, NULL, NULL);
            copyTree(treePtr->leftPointer, newTree->leftPointer);
            copyTree(treePtr->rightPointer, newTree->rightPointer);
        }
        else
        {
            newTree = NULL;
        }
    }
    void destroyTree(AVLTreeNode * &treePtr)
    {
        if(treePtr != NULL)
        {
            destroyTree(treePtr->leftPointer);
            destroyTree(treePtr->rightPointer);
            delete treePtr;
            treePtr = NULL;
        }
    }
    void insertItemToNode(AVLTreeNode *& treePtr,const int& val)
    {
        if (treePtr == NULL)
        {
            treePtr = new AVLTreeNode(val, NULL, NULL);
            treePtr->setHeight(1);
        }
        else if (val < treePtr ->nodeItem)
        {
            insertItemToNode(treePtr->leftPointer, val);
        }
        else if(val > treePtr->nodeItem)
        {
            insertItemToNode(treePtr->rightPointer, val);
        }
        else
        {
        }
        int balanceNo = getBalance(treePtr);
        if(treePtr->leftPointer != NULL)
        {
            if(balanceNo > 1 && val < treePtr->leftPointer->nodeItem)
            {
                singleRightRotationNode(treePtr);
            }
            if(balanceNo > 1 && val > treePtr->leftPointer->nodeItem)
            {
                //LR
                singleLeftRotationNode(treePtr->leftPointer);
                singleRightRotationNode(treePtr);
            }
        }
        if(treePtr->rightPointer != NULL)
        {
            if(balanceNo < -1 && val > treePtr->rightPointer->nodeItem)
            {
                singleLeftRotationNode(treePtr);
            }

            if( balanceNo < -1 && val < treePtr->rightPointer->nodeItem)
            {
                //RL
                singleRightRotationNode(treePtr->rightPointer);
                singleLeftRotationNode(treePtr);
            }
        }
    }
    int getHeightHelper(AVLTreeNode* subTreePtr) const
    {
        if (subTreePtr == NULL)
            return 0;
        else
            return 1 + max(getHeightHelper(subTreePtr->leftPointer), getHeightHelper(subTreePtr->rightPointer));

    }
    void  deleteItemFromNode(AVLTreeNode * &treePtr, int item)
    {
        if (treePtr == NULL) {}
        else if (item == treePtr->nodeItem)
            deleteNodeItem(treePtr, item);
        else if (item < treePtr->nodeItem)
            deleteItemFromNode(treePtr->leftPointer, item);
        else
            deleteItemFromNode(treePtr->rightPointer, item);
    }
    void deleteNodeItem(AVLTreeNode * &nodePtr,int val)
    {
        int replacementItem;
        if ( (nodePtr->leftPointer == NULL) &&
                (nodePtr->rightPointer == NULL) )
        {
            delete nodePtr;
            nodePtr = NULL;
        }
        if (val < nodePtr->nodeItem)
        {
            deleteNodeItem(nodePtr->leftPointer,val);
        }
        else if(val > nodePtr->nodeItem)
        {
            deleteNodeItem(nodePtr->rightPointer, val);
        }
        else
        {
            processLeftmost(nodePtr->rightPointer, replacementItem);
            nodePtr->nodeItem = replacementItem;
        }
        if(nodePtr == NULL)
        {
            cout<< "tree is empty" << endl;
        }
        else
        {
            nodePtr->setHeight(getHeightHelper(nodePtr));
            int balanceNo = getBalance(nodePtr);
            if(nodePtr->leftPointer != NULL)
            {
                if(balanceNo > 1 && getBalance(nodePtr->leftPointer) >= 0)
                {
                    singleRightRotationNode(nodePtr);
                }
                if(balanceNo > 1 && getBalance(nodePtr->rightPointer) < 0)
                {
                    singleLeftRotationNode(nodePtr->leftPointer);
                    singleRightRotationNode(nodePtr);
                }
            }
            if(nodePtr->rightPointer != NULL)
            {
                if( balanceNo < -1 && getBalance(nodePtr->rightPointer) <= 0)
                {
                    singleLeftRotationNode(nodePtr);
                }
                if(balanceNo < -1 && getBalance(nodePtr->rightPointer) > 0)
                {
                    singleRightRotationNode(nodePtr->rightPointer);
                    singleLeftRotationNode(nodePtr);
                }
            }

        }

    }
    void processLeftmost(AVLTreeNode *&nodePtr,int& treeItem)
    {
        if (nodePtr->leftPointer == NULL)
        {
            treeItem = nodePtr->nodeItem;
            AVLTreeNode *delPtr = nodePtr;
            nodePtr = nodePtr->rightPointer;
            delPtr->rightPointer = NULL;
            delete delPtr;
        }
        else
            processLeftmost(nodePtr->leftPointer, treeItem);
    }
    int getNodeCountHelper(AVLTreeNode* root)
    {
        int countNodes = 1;
        if(root == NULL)
        {

        }
        if(root->leftPointer != NULL)
        {
            countNodes += getNodeCountHelper(root->leftPointer);
        }
        if(root->rightPointer != NULL)
        {
            countNodes += getNodeCountHelper(root->rightPointer);
        }
        return countNodes;
    }
    int findNodesRequiredHelper(AVLTreeNode* root)
    {
        int nodes = this->getNodeCount();
        int height = getHeightHelper(root);
        int numberOfNodestoBe = 0;
        for(int i = 0; i< height; i++)
        {
            numberOfNodestoBe += pow(2,i);
        }
        int numberOfRequired = numberOfNodestoBe - nodes;
        return numberOfRequired;
    }
    int nodeLevel(int i)
    {
        int nodeNumber = 0;
        this -> levelFullValid(root,i,nodeNumber);
        nodeNumber = pow(2,i-1);
        return nodeNumber;
    }
    bool levelFullValid(int i)
    {
        int nodeNumber = 0;
        this -> levelFullValid(root,i,nodeNumber);
        return nodeNumber == pow(2,i-1);
    }
    void levelFullValid(AVLTreeNode* node,int i,int &nodeNumber)
    {
        if(node == NULL)
        {
            return;
        }
        if(i == 1)
        {
            nodeNumber++;
        }
        else
        {
            this->levelFullValid(node->leftPointer,i-1,nodeNumber);
            this->levelFullValid(node->rightPointer,i-1,nodeNumber);
        }
    }
    void mirrorTheTree(AVLTreeNode* root)
    {
        if(root == NULL || ((root->leftPointer == NULL) && (root->rightPointer == NULL)) )
        {
        }
        else
        {
            AVLTreeNode* tempNode;
            mirrorTheTree(root->leftPointer);
            mirrorTheTree(root->rightPointer);
            tempNode = root->leftPointer;
            root->leftPointer = root->rightPointer;
            root->rightPointer = tempNode;

        }
    }
    //visit for print function
    void visit(int item,int height)
    {
        for(int i = 0; i < pow(2,height/2); i++)
        {
            cout <<"-";
        }
        cout<< item ;
        for(int i = 0; i < pow(2,height/2); i++)
        {
            cout <<"-";
        }
    }
    //self-checker
    void visitOrder(int item)
    {
        cout<< item << " " ;
    }
    void inOrderTree(AVLTreeNode* node)
    {
        if(node != NULL)
        {
            inOrderTree(node->leftPointer);
            visitOrder(node->nodeItem);
            inOrderTree(node->rightPointer);
        }
    }
    void preOrderTree(AVLTreeNode* node)
    {
        if(node != NULL)
        {
            visitOrder(node->nodeItem);
            preOrderTree(node->leftPointer);
            preOrderTree(node->rightPointer);
        }

    }
    void postOrderTree(AVLTreeNode* node)
    {
        if(node != NULL)
        {
            postOrderTree(node->leftPointer);
            postOrderTree(node->rightPointer);
            visitOrder(node->nodeItem);
        }
    }

};
#endif

