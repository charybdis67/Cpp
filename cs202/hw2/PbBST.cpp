/**
* Title : Binary Search Trees
* Author : Asuman Aydin
* ID: 21502604
* Section : 01
* Assignment : 2
* Description : Binary Search Tree source code file
*/
#include <iostream>
using namespace std;
#include "PbBST.h"
#include "PbBSTNode.h"

PbBST:: PbBST()
{
    root = NULL;
}
PbBST:: PbBST(const int& rootItem)
{
    root = new PbBSTNode(rootItem);
}
PbBST::PbBST(const int& rootItem,PbBST& leftTree, PbBST& rightTree)
{
    root = new PbBSTNode(rootItem,leftTree.root, rightTree.root);
}
PbBST::PbBST(const PbBST& newTree)
{
    copyTree(newTree.root,root);
}
PbBST::~PbBST()
{
    destroyTree(root);
}
bool PbBST:: isEmpty() const
{
    if(root == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//PART A
void PbBST::insertKey(int key)
{
    insertItemToNode(root,key);
}
void PbBST:: deleteKey(int key)
{
    deleteItemFromNode(root, key);
}
//PART B
int PbBST:: getHeight()
{
    return getHeightHelper(root);
}
int PbBST:: getNodeCount()
{
    if(root ==  NULL)
    {
        return 0;
    }
   else{
    return getNodeCountHelper(root);
   }
}
int PbBST:: findNodesRequired()
{
    return findNodesRequiredHelper(root);
}
//PART C
int PbBST:: findFullBTLevel()
{
    int numberLevel = this->getHeight();
    if(numberLevel == 0)
    {
        return 0;
    }
    else{
        for(int i = 1; i<= numberLevel; i++)
        {
            if(!this->levelFullValid(i))
            {
                return i-1;
            }
        }
    }
    return numberLevel;
}
//PART D
void PbBST:: mirrorTree()
{
    mirrorTheTree(root);
}
void PbBST:: printTree()
{
    int height = getHeight();
    printTreeHelper(root,height);
}
void PbBST:: printNormal()
{
    inOrderTree(root);
    cout<<  "Inorder" <<  endl;
    preOrderTree(root);
    cout<<  "PreOrder" << endl;
    postOrderTree(root);
    cout<< "Post Order" << endl;
}
