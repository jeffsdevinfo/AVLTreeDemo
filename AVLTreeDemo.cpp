// Copyright (c) 2021 Jeff Simon
// Distributed under the MIT/X11 software license, see the accompanying
// file license.txt or http://www.opensource.org/licenses/mit-license.php.

#include <iostream>
#include "Base.h"
#include "AVLTree.h"

int main()
{
    Base* basePtr = nullptr;
    basePtr = new AVLTreeExec();
    basePtr->Run();
}
