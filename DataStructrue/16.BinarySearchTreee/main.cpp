#include <iostream>

#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree<int> tree;

    tree.InsertNode(20);
    tree.InsertNode(20);
    tree.InsertNode(50);
    tree.InsertNode(50);
    tree.InsertNode(70);
    tree.InsertNode(80);
    tree.InsertNode(100);

    int searchData = 50;
    if (tree.SearchNode(searchData))
    {
        std::cout << searchData << " 검색 성공\n";
    }
    else
    {
        std::cout << searchData << " 검색 실패\n";
    }

    tree.DeleteNode(30);
    tree.InsertNode(30);

    tree.InorderTraverse();
}