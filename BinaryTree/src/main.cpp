//============================================================================
// Name        : TemplateBinaryTree.cpp
// Author      : Simone Kslash Angeletti
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Btree.h"
#include "Tnode.h"
#include "BinaryTreeServices.h"
using namespace std;


int main() {
	cout << "Binary Tree Template" << endl; // prints !!!Hello World!!!


	Btree<int> albero;

	autoAcquire(albero);
	acquire(albero);
	preOrder(albero,albero.root());
	cout << endl;
	postOrder(albero,albero.root());
	cout << endl;
	inOrder(albero,albero.root());
	cout << endl;
	BFS(albero);
	cout << endl;

	cout << "binary search: " << binarySearchBool(albero,albero.root(),21) << endl;
	cout << "binary search bool: " << binarySearch(albero,albero.root(),21) << endl;
	cout << "search preOrder: " << preOrderSearch(albero,albero.root(),21) << endl;
	cout << "search node: " << searchNode(albero,albero.root(),21) << endl;
	cout << "level: " << getLevel(albero,albero.root(),21) << endl;
	cout << "end" << endl;



	return 0;
}
