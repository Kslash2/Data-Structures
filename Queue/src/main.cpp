
/*
 * main.cpp
 *
 *  Created on: 11 gen 2017
 *      Author: Simone kslash Angeletti
 */


//============================================================================
// Name        : main.cpp
// Author      : Simone Kslash Angeletti
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include "node.hpp"

#include "queue.hpp"
#include "queueServices.h"


using namespace std;



int main(){

	cout << "Queue" << endl;

	Queue<int> queue;

	acquireQueue(queue);
	printQueue(queue);
	cout << "number of elements: " << countElements(queue) << endl;
	cout << "found? " << searchElement(queue,89) << endl;
	cancElement(queue,2);
	printQueue(queue);


	return 0;


}
