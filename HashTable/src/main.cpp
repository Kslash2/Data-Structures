//============================================================================
// Name        : HashTable.cpp
// Author      : Simone Kslash Angeletti
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "HashTable.h"

using namespace std;

int main() {
	 // Create 26 Items to store in the Hash Table.
	    Node<int> * A = new Node<int> {"Apple",24, NULL};
	    Node<int> * B = new Node<int> {"Banana",39, NULL};
	    Node<int> * C = new Node<int> {"Caterpillar",23, NULL};
	    Node<int> * D = new Node<int> {"Dog",56, NULL};
	    Node<int> * E = new Node<int> {"Elephant",66, NULL};
	    Node<int> * F = new Node<int> {"Fedora",89, NULL};
	    Node<int> * G = new Node<int> {"Goosebumps",47, NULL};
	    Node<int> * H = new Node<int> {"House",78, NULL};
	    Node<int> * I = new Node<int> {"Insects",123, NULL};
	    Node<int> * J = new Node<int> {"Jam",890, NULL};
	    Node<int> * K = new Node<int> {"Kite",55, NULL};
	    Node<int> * L = new Node<int> {"Limestone",66, NULL};
	    Node<int> * M = new Node<int> {"Mountaineering",99, NULL};
	    Node<int> * N = new Node<int> {"Night",11, NULL};
	    Node<int> * O = new Node<int> {"Open Sesame",23, NULL};
	    Node<int> * P = new Node<int> {"Potatoes",56, NULL};
	    Node<int> * Q = new Node<int> {"Quantum Mechanics",99, NULL};
	    Node<int> * R = new Node<int> {"Rrrrrrrrrrawr",12, NULL};
	    Node<int> * S = new Node<int> {"Snakes",12345, NULL};
	    Node<int> * T = new Node<int> {"Tizzy Tube",34, NULL};
	    Node<int> * U = new Node<int> {"Underworld",56, NULL};
	    Node<int> * V = new Node<int> {"Volcanic Ash",90, NULL};
	    Node<int> * W = new Node<int> {"Who When What Why",45, NULL};
	    Node<int> * X = new Node<int> {"XXX",23, NULL};
	    Node<int> * Y = new Node<int> {"Yellow",89, NULL};
	    Node<int> * Z = new Node<int> {"Zest of Lemon",11, NULL};

	    // Create a Hash Table of 13 Linked List elements.
	    HashTable<int> table;

	    // Add 3 Items to Hash Table.
	    table.insertItem(A);
	    table.insertItem(B);
	    table.insertItem(C);
	    table.printTable();
	    table.printHistogram();

	    // Remove one item from Hash Table.
	    table.removeItem("Apple");
	    table.printTable();
	    table.printHistogram();


	    // Add 23 items to Hash Table.
	    table.insertItem(D);
	    table.insertItem(E);
	    table.insertItem(F);
	    table.insertItem(G);
	    table.insertItem(H);
	    table.insertItem(I);
	    table.insertItem(J);
	    table.insertItem(K);
	    table.insertItem(L);
	    table.insertItem(M);
	    table.insertItem(N);
	    table.insertItem(O);
	    table.insertItem(P);
	    table.insertItem(Q);
	    table.insertItem(R);
	    table.insertItem(S);
	    table.insertItem(T);
	    table.insertItem(U);
	    table.insertItem(V);
	    table.insertItem(W);
	    table.insertItem(X);
	    table.insertItem(Y);
	    table.insertItem(Z);
	    table.printTable();
	    table.printHistogram();

	    // Look up an Node<int> in the Hash Table.
	    Node<int> * result = table.getItemByKey("Snakes");
	    cout << result -> key << endl;

	    return 0;
}
