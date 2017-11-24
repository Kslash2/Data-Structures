//============================================================================
// Name        : TemplateN-aryTree.cpp
// Author      : Simone Kslash Angeletti
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Nnode.hpp"
#include "Ntree.hpp"
#include "servicesNtree.hpp"

using namespace std;

int main() {

	nTree<int> albero; //albero is tree translated in italian ;)

	//acquire(albero);
	autoAcquire(albero);
	preOrder(albero.root(),albero);
	cout << endl;
    inOrder(albero.root(),albero);
    cout << endl;
    postOrder(albero.root(),albero);
    cout << endl;
    BFS(albero.root(),albero);
    cout << endl;
    cout << countNode(albero.root(),albero) << endl;
    cout << countLeaves(albero.root(),albero) << endl;
    cout << height(albero.root(),albero) << endl;
    cout << depthNode(searchNode(4,albero),albero) << endl;


	return 0;
}
