#pragma once
#include "Base.h"
#include "AVLTree.h"
#include "Student.h"

class AVLTreeExec : public Base
{
public:
	void Run()
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
};