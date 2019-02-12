/**
* Title : Binary Search Trees
* Author : Asuman Aydin
* ID: 21502604
* Section : 01
* Assignment : 2
* Description : PbBST HEADER FILE
*/
#include <iostream>
#include "PbBSTNode.h"
using namespace std;
#ifndef __PBST_H
#define __PBST_H
#include "math.h"

class PbBST
{
public:
    PbBST();
    PbBST(const int& rootItem);
    PbBST(const int& rootItem,PbBST& leftTree, PbBST& rightTree);
    PbBST(const PbBST& newTree);
    ~PbBST();
    bool isEmpty() const;
    //assignment
    void insertKey(int key);
    void deleteKey(int key);
    int getHeight();
    int getNodeCount();
    int findNodesRequired();
    int findFullBTLevel();
    void mirrorTree();
    void printTree();
    void printNormal();

    //assignment
private:
    PbBSTNode* root;
    void copyTree(PbBSTNode *treePtr, PbBSTNode* &newTree) const
    {
        if(treePtr != NULL)
        {
            newTree = new PbBSTNode(treePtr->nodeItem, NULL, NULL);
            copyTree(treePtr->leftPointer, newTree->leftPointer);
            copyTree(treePtr->rightPointer, newTree->rightPointer);
        }
        else
        {
            newTree = NULL;

        }
    }
    void destroyTree(PbBSTNode * &treePtr)
    {
        if(treePtr != NULL)
        {
            destroyTree(treePtr->leftPointer);
            destroyTree(treePtr->rightPointer);
            delete treePtr;
            treePtr = NULL;
        }
    }
    void insertItemToNode(PbBSTNode *& treePtr,const int& newItem)
    {
        if (treePtr == NULL)
        {
            treePtr = new PbBSTNode(newItem, NULL, NULL);
        }
        // Else search for the insertion position
        else if (newItem < treePtr ->nodeItem)
        {
            insertItemToNode(treePtr->leftPointer, newItem);
        }
        else
        {
            insertItemToNode(treePtr->rightPointer, newItem);
        }
    }
    int getHeightHelper(PbBSTNode* subTreePtr) const
    {
        if (subTreePtr == NULL)
            return 0;
        else
            return 1 + max(getHeightHelper(subTreePtr->leftPointer), getHeightHelper(subTreePtr->rightPointer));

    }
    void  deleteItemFromNode(PbBSTNode * &treePtr, int item)
    {
        if (treePtr == NULL) {}
        else if (item == treePtr->nodeItem)
            deleteNodeItem(treePtr);
        else if (item < treePtr->nodeItem)
            deleteItemFromNode(treePtr->leftPointer, item);
        else
            deleteItemFromNode(treePtr->rightPointer, item);
    }
    void deleteNodeItem(PbBSTNode * &nodePtr)
    {
        PbBSTNode *delPtr;
        int replacementItem;
        if ( (nodePtr->leftPointer == NULL) &&
                (nodePtr->rightPointer == NULL) )
        {
            delete nodePtr;
            nodePtr = NULL;
        }
        else if (nodePtr->leftPointer == NULL)
        {
            delPtr = nodePtr;
            nodePtr = nodePtr->rightPointer;
            delPtr->rightPointer = NULL;
            delete delPtr;
        }
        else if (nodePtr->rightPointer == NULL)
        {
            delPtr = nodePtr;
            nodePtr = nodePtr->leftPointer;
            delPtr->leftPointer = NULL;
            delete delPtr;
        }
        else
        {
            processLeftmost(nodePtr->rightPointer, replacementItem);
            nodePtr->nodeItem = replacementItem;
        }
    }
    void processLeftmost(PbBSTNode *&nodePtr,int& treeItem)
    {
        if (nodePtr->leftPointer == NULL)
        {
            treeItem = nodePtr->nodeItem;
            PbBSTNode *delPtr = nodePtr;
            nodePtr = nodePtr->rightPointer;
            delPtr->rightPointer = NULL;
            delete delPtr;
        }
        else
            processLeftmost(nodePtr->leftPointer, treeItem);
    }
    int getNodeCountHelper(PbBSTNode* root)
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
    int findNodesRequiredHelper(PbBSTNode* root)
    {
        int nodes = this->getNodeCount();
        int height = this->getHeight();
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
    void levelFullValid(PbBSTNode* node,int i,int &nodeNumber)
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
    void mirrorTheTree(PbBSTNode* root)
    {
        if(root == NULL || ((root->leftPointer == NULL) && (root->rightPointer == NULL)) )
        {
        }
        else
        {
            PbBSTNode* tempNode;
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
    void printTreeHelper(PbBSTNode *treePtr,int height)
    {

        if(treePtr == NULL)
        {
            for(int i = 0; i< pow(2,height); i++)
            {
                cout<< " " ;
            }
        }
        if (treePtr != NULL)
        {
            visit(treePtr->nodeItem,height);
            cout<< endl;
            height--;
            printTreeHelper(treePtr->leftPointer,height);
            height = getHeight();
            printTreeHelper(treePtr->rightPointer,height);

        }
    }
    //self-checker
    void visitOrder(int item)
    {
        cout<< item << " " ;
    }
    void inOrderTree(PbBSTNode* node)
    {
        if(node != NULL)
        {
            inOrderTree(node->leftPointer);
            visitOrder(node->nodeItem);
            inOrderTree(node->rightPointer);
        }
    }
    void preOrderTree(PbBSTNode* node)
    {
        if(node != NULL)
        {
            visitOrder(node->nodeItem);
            preOrderTree(node->leftPointer);
            preOrderTree(node->rightPointer);
        }

    }
    void postOrderTree(PbBSTNode* node)
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
