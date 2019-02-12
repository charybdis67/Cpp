
/**
* Title :
* Author : Asuman Aydin
* ID: 21502604
* Section :
* Assignment : 3
* Description :
*/
#include "AVLTree.h"
#include "AVLTreeNode.h"
#include <iostream>
using namespace std;

AVLTree::  AVLTree()
{
    root = NULL;
}
AVLTree::  AVLTree(const int& rootItem)
{
    root = new AVLTreeNode(rootItem);
}
AVLTree::  AVLTree(const int& rootItem,AVLTree& leftTree, AVLTree& rightTree)
{
    root = new AVLTreeNode(rootItem,leftTree.root, rightTree.root);
}
AVLTree::  AVLTree(const AVLTree& newTree)
{
    copyTree(newTree.root,root);
}
AVLTree:: ~AVLTree()
{
    destroyTree(root);
}
bool AVLTree::isEmpty() const
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
int AVLTree::getHeightTree()
{
    return getHeightHelper(root);
}
void AVLTree::insertKey(int val)
{
    insertItemToNode(root, val);
}
void AVLTree::deleteKey(int val)
{
    deleteNodeItem(root, val);
}
int AVLTree::findNodesRequired()
{
    return findNodesRequiredHelper(root);
}
int AVLTree::getNodeCount()
{
    if(root ==  NULL)
    {
        return 0;
    }
    else
    {
        return getNodeCountHelper(root);
    }
}
int AVLTree::findFullBTLevel()
{
    int numberLevel = getHeightHelper(root);
    if(numberLevel == 0)
    {
        return 0;
    }
    else
    {
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

void AVLTree:: printNormal()
{
    inOrderTree(root);
    cout<<  "Inorder" <<  endl;
//    preOrderTree(root);
//    cout<<  "PreOrder" << endl;
//    postOrderTree(root);
//    cout<< "Post Order" << endl;
}
