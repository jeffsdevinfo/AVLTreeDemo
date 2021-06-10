// Copyright (c) 2021 Jeff Simon
// Distributed under the MIT/X11 software license, see the accompanying
// file license.txt or http://www.opensource.org/licenses/mit-license.php.

#pragma once
//#include <algorithm>
#include <iostream>
#include "Base.h"
#include "Student.h"

class AVLTreeExec : public Base
{
public:
	void Run();
};

template <typename TData>
class Node
{
public:
	Node<TData>* right;
	Node<TData>* left;
	int val;
	TData* m_data;
	//char level;
	char lbal;
	char rbal;
	Node() { right = left = nullptr; val = INT_MIN; lbal = rbal = 0; m_data = nullptr; }
	Node(int val) { right = left = nullptr; this->val = val; lbal = rbal = 0; m_data = nullptr; }
	Node(const Node<TData>& other) { std::cout << "Node Copy Constructor\n"; right = left = nullptr; this->val = val; lbal = rbal = 0; m_data = nullptr; }
	int Height() { if (lbal > rbal)return lbal; else return rbal; }
	bool CheckBalance() { if (abs(rbal - lbal) < 2) return true; else return false; }
	void MoveData(TData&& movedData)
	{
		m_data = movedData;
		movedData = nullptr;
	}
};

template <typename TData>
class AVLTree
{
private:
	void InsertNodeRecurse(Node<TData>*& curr, int val);
	void PreOrderTreeTraversal(Node<TData>* curr);
	void InOrderTreeTraversal(Node<TData>* curr);	
	void PostOrderTreeTraversal(Node<TData>* curr);
	char traverseState[2];
	Node<TData>* root;	
public:
	AVLTree() {
		root = nullptr;
		traverseState[0] = '0';
		traverseState[0] = '0';
	}

	enum OrderType { Inorder, PreOrder, PostOrder };
	bool InsertNode(int val);
	bool DeleteNode(int val);
	void LLRot(Node<TData>*& child);
	void LRRot(Node<TData>*& child);
	void RRRot(Node<TData>*& child);
	void RLRot(Node<TData>*& child);
	void InsertTraverseState(char tState);
	Node<TData>* Rebalance(Node<TData>*& BalanceNode);
	void TraverseTree(OrderType order);
	void InOrderTreeTraversal();
	void PreorderTreeTraversal();
	void PostOrderTreeTraversal();
};

#include "AVLTree.hpp"