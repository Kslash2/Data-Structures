//============================================================================
// Name        : main.cpp
// Author      : Simone Kslash Angeletti
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "CircularQueue.hpp"
using namespace std;

int main() {
	cout << "!!!Circular Queue with Templates!!!" << endl; // prints !!!Hello World!!!


	CircularQueue<int> Q (10);
	cout << "Queue created:" << endl;
	Q.display();

	cout << "Head: " << Q.top() << endl;
	cout << "Bottom: " << Q.getBottom() << endl;


	cout << "pushing some data..." << endl;
	Q.push(23);
	Q.push(78);
	Q.push(29);
	Q.push(54);

	Q.display();
	cout << "Head: " << Q.top() << endl;
	cout << "Bottom: " << Q.getBottom() << endl;

	cout << "deleting some data(2)..." << endl;

	//2
	Q.pop();
	Q.pop();

	Q.display();
	cout << "Head: " << Q.top() << endl;
	cout << "Bottom: " << Q.getBottom() << endl;






	return 0;
}
