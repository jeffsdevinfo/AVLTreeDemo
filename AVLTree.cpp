// Copyright (c) 2021 Jeff Simon
// Distributed under the MIT/X11 software license, see the accompanying
// file license.txt or http://www.opensource.org/licenses/mit-license.php.

#include "AVLTree.h"

bool AVLTree::InsertNode(int val)
{
    InsertNodeRecurse(root, val);
    return false;
}

void AVLTree::InsertNodeRecurse(Node*& child, int val)
{
    if (!child)
    {
        child = new Node(val);
    }
    else if (child->val > val)
    {
        InsertNodeRecurse(child->left, val);
        InsertTraverseState('L');
        int temp = (int)child->left->Height() + 1;
        child->lbal = temp;
    }
    else if (child->val < val)
    {
        InsertNodeRecurse(child->right, val);
        InsertTraverseState('R');
        child->rbal = (int)child->right->Height() + 1;
    }
    if (!(child->CheckBalance()))
    {
        Rebalance(child);
    }
}

bool AVLTree::DeleteNode(int val)
{
    return false;
}

void AVLTree::LLRot(Node*& A)
{
    Node* ASaved = A;
    Node* CSaved = A->left->right;
    A = ASaved->left;
    A->right = ASaved;
    ASaved->left = CSaved;
}

void AVLTree::LRRot(Node*& A)
{
    Node* ASaved = A;
    Node* BSaved = A->left;
    Node* CLeft = A->left->right->left;
    Node* CRight = A->left->right->right;
    A = A->left->right;
    A->left = BSaved;
    A->right = ASaved;
    BSaved->right = CLeft;
    ASaved->left = CRight;
}

void AVLTree::RRRot(Node*& A)
{
    Node* ASaved = A;
    Node* CSaved = A->right->left;
    A = A->right;
    A->left = ASaved;
    ASaved->right = CSaved;
}

void AVLTree::RLRot(Node*& A)
{
    Node* ASaved = A;
    Node* BSaved = A->right;
    Node* CLeft = A->right->left->left;
    Node* CRight = A->right->left->right;
    A = A->right->left;
    A->left = ASaved;
    A->right = BSaved;
    BSaved->left = CRight;
    ASaved->right = CLeft;
}

void AVLTree::InsertTraverseState(char tState)
{
    traverseState[1] = traverseState[0];
    traverseState[0] = tState;
}

Node* AVLTree::Rebalance(Node*& BalanceNode)
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

void AVLTree::PostOrderTreeTraversal()
{
    if (!root)
    {
        return;
    }
    PostOrderTreeTraversal(root);
}

/*
* Post order traversal 
*/
void AVLTree::PostOrderTreeTraversal(Node* curr)
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
    AVLTree* tree = new AVLTree();
    //RL
    /*tree->InsertNode(50);
    tree->InsertNode(75);
    tree->InsertNode(65);*/

    //LL
    tree->InsertNode(50);
    tree->InsertNode(25);
    tree->InsertNode(75);            
    tree->InsertNode(20);
    tree->InsertNode(45);
    tree->InsertNode(60);
    tree->InsertNode(85);    
    tree->InsertNode(10);
    tree->InsertNode(23);
    tree->InsertNode(40);
    tree->InsertNode(48);
    tree->InsertNode(5);        
    
    //Display avl tree with a post order traversal
    tree->PostOrderTreeTraversal();
}
