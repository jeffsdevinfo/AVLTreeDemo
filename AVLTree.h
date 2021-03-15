// Copyright (c) 2021 Jeff Simon
// Distributed under the MIT/X11 software license, see the accompanying
// file license.txt or http://www.opensource.org/licenses/mit-license.php.

#pragma once
//#include <algorithm>
#include <iostream>
#include "Base.h"

class AVLTreeExec : public Base
{
public:
	void Run();
};

class Node
{
public:
	Node* right;
	Node* left;
	int val;
	//char level;
	char lbal;
	char rbal;
	Node() { right = left = nullptr; val = INT_MIN; lbal = rbal = 0; }
	Node(int val) { right = left = nullptr; this->val = val; lbal = rbal = 0; }
	int Height() { if (lbal > rbal)return lbal; else return rbal; }
	bool CheckBalance() { if (abs(rbal - lbal) < 2) return true; else return false; }
};
class AVLTree
{
private:
	void InsertNodeRecurse(Node*& child, int val);
	void PostOrderTreeTraversal(Node* curr);
	char traverseState[2];
	Node* root;

public:
	AVLTree() {
		root = nullptr;
		traverseState[0] = '0';
		traverseState[0] = '0';
	}

	bool InsertNode(int val);
	bool DeleteNode(int val);
	void LLRot(Node*& child);
	void LRRot(Node*& child);
	void RRRot(Node*& child);
	void RLRot(Node*& child);
	void InsertTraverseState(char tState);
	Node* Rebalance(Node*& BalanceNode);
	void PostOrderTreeTraversal();
};

