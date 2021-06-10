#pragma once
// Copyright (c) 2021 Jeff Simon
// Distributed under the MIT/X11 software license, see the accompanying
// file license.txt or http://www.opensource.org/licenses/mit-license.php.

#include "AVLTree.h"

template <typename TData>
bool AVLTree<TData>::InsertNode(int val)
{
    InsertNodeRecurse(root, val);
    return false;
}

template <typename TData>
void AVLTree<TData>::InsertNodeRecurse(Node<TData>*& curr, int val)
{
    if (!curr)
    {
        curr = new Node<TData>(val);
    }
    else if (curr->val > val)
    {
        InsertNodeRecurse(curr->left, val);
        InsertTraverseState('L');
        int temp = (int)curr->left->Height() + 1;
        curr->lbal = temp;
    }
    else if (curr->val < val)
    {
        InsertNodeRecurse(curr->right, val);
        InsertTraverseState('R');
        curr->rbal = (int)curr->right->Height() + 1;
    }
    if (!(curr->CheckBalance()))
    {
        Rebalance(curr);
    }
}

template <typename TData>
bool AVLTree<TData>::DeleteNode(int val)
{
    return false;
}

template <typename TData>
void AVLTree<TData>::LLRot(Node<TData>*& A)
{
    std::cout << "LLRot \n";
    Node<TData>* ASaved = A;
    Node<TData>* CSaved = A->left->right;
    A = ASaved->left;
    A->right = ASaved;
    ASaved->left = CSaved;
}

template <typename TData>
void AVLTree<TData>::LRRot(Node<TData>*& A)
{
    std::cout << "LRRot \n";
    Node<TData>* ASaved = A;
    Node<TData>* BSaved = A->left;
    Node<TData>* CLeft = A->left->right->left;
    Node<TData>* CRight = A->left->right->right;
    A = A->left->right;
    A->left = BSaved;
    A->right = ASaved;
    BSaved->right = CLeft;
    ASaved->left = CRight;
}

template <typename TData>
void AVLTree<TData>::RRRot(Node<TData>*& A)
{
    std::cout << "RRRot \n";
    Node<TData>* ASaved = A;
    Node<TData>* CSaved = A->right->left;
    A = A->right;
    A->left = ASaved;
    ASaved->right = CSaved;
}

template <typename TData>
void AVLTree<TData>::RLRot(Node<TData>*& A)
{
    std::cout << "RLRot \n";
    Node<TData>* ASaved = A;
    Node<TData>* BSaved = A->right;
    Node<TData>* CLeft = A->right->left->left;
    Node<TData>* CRight = A->right->left->right;
    A = A->right->left;
    A->left = ASaved;
    A->right = BSaved;
    BSaved->left = CRight;
    ASaved->right = CLeft;
}

template <typename TData>
void AVLTree<TData>::InsertTraverseState(char tState)
{
    traverseState[1] = traverseState[0];
    traverseState[0] = tState;
}

template <typename TData>
Node<TData>* AVLTree<TData>::Rebalance(Node<TData>*& BalanceNode)
{
    if (traverseState[0] == 'L' && traverseState[1] == 'L')
    {
        LLRot(BalanceNode);
    }
    else if (traverseState[0] = 'L' && traverseState[1] == 'R')
    {
        LRRot(BalanceNode);
    }
    else if (traverseState[0] = 'R' && traverseState[1] == 'L')
    {
        RLRot(BalanceNode);
    }
    else
    {
        RRRot(BalanceNode);
    }
    return nullptr;
}
template <typename TData>
void AVLTree<TData>::TraverseTree(OrderType order)
{
    std::cout << "\n\nStarting Traversal\n";
    switch (order)
    {
    case OrderType::Inorder:
        InOrderTreeTraversal();
        break;
    case OrderType::PreOrder:
        PreorderTreeTraversal();
        break;
    case OrderType::PostOrder:
        PostOrderTreeTraversal();
    }
}

template <typename TData>
void AVLTree<TData>::PreorderTreeTraversal()
{
    if (!root)
    {
        return;
    }
    InOrderTreeTraversal(root);
}

template <typename TData>
void AVLTree<TData>::InOrderTreeTraversal()
{
    if (!root)
    {
        return;
    }
    InOrderTreeTraversal(root);
}

template <typename TData>
void AVLTree<TData>::PostOrderTreeTraversal()
{
    if (!root)
    {
        return;
    }
    PostOrderTreeTraversal(root);
}

/*
* Pre order traversal 
* →
*/
template <typename TData>
void AVLTree<TData>::PreOrderTreeTraversal(Node<TData>* curr)
{

    if (curr)
    {
        std::cout << curr->val;
        if (curr->left)
        {
            std::cout << "\nleft \n";
            PreOrderTreeTraversal(curr->left);
            std::cout << "\nup\n";
        }
        if (curr->right)
        {
            std::cout << "\nright \n";
            PreOrderTreeTraversal(curr->right);
            std::cout << "\nup\n";
        }
    }
}

/*
* In order traversal
* ↑
*/
template <typename TData>
void AVLTree<TData>::InOrderTreeTraversal(Node<TData>* curr)
{
    if (curr)
    {
        if (curr->left)
        {
            std::cout << "\nleft \n";
            InOrderTreeTraversal(curr->left);
            std::cout << "\nup\n";
        }
        std::cout << curr->val;
        if (curr->right)
        {
            std::cout << "\nright \n";
            InOrderTreeTraversal(curr->right);
            std::cout << "\nup\n";
        }        
    }
}

/*
* Post order traversal
* ←
*/
template <typename TData>
void AVLTree<TData>::PostOrderTreeTraversal(Node<TData>* curr)
{
    if (curr)
    {
        if (curr->left)
        {
            std::cout << "\nleft \n";
            PostOrderTreeTraversal(curr->left);
            std::cout << "\nup\n";
        }
        if (curr->right)
        {
            std::cout << "\nright \n";
            PostOrderTreeTraversal(curr->right);
            std::cout << "\nup\n";

        }
        std::cout << curr->val;
    }
}


void AVLTreeExec::Run()
{
    AVLTree<Student>* tree = new AVLTree<Student>();
    //RL
    /*tree->InsertNode(50);
    tree->InsertNode(75);
    tree->InsertNode(65);*/

    //LL
    std::cout << "Inserting 50\n";
    tree->InsertNode(50);
    std::cout << "Inserting 25\n";
    tree->InsertNode(25);
    std::cout << "Inserting 75\n";
    tree->InsertNode(75);
    std::cout << "Inserting 20\n";
    tree->InsertNode(20);
    std::cout << "Inserting 45\n";
    tree->InsertNode(45);
    std::cout << "Inserting 60\n";
    tree->InsertNode(60);
    std::cout << "Inserting 85\n";
    tree->InsertNode(85);
    std::cout << "Inserting 10\n";
    tree->InsertNode(10);
    std::cout << "Inserting 23\n";
    tree->InsertNode(23);
    std::cout << "Inserting 40\n";
    tree->InsertNode(40);
    std::cout << "Inserting 48\n";
    tree->InsertNode(48);
    std::cout << "Inserting 5\n";
    tree->InsertNode(5);    

    //Display avl tree with a post order traversal     
    tree->TraverseTree(AVLTree<Student>::OrderType::PostOrder);
}
