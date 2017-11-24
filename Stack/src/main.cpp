//============================================================================
// Name        : Stack.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "stdafx.h"
#include "stack.hpp"
#include "node.hpp"
#include "stackServices.hpp"
using namespace std;




int main() {
	cout << "!!!Stack!!!" << endl; // prints !!!Hello World!!!


	Stack<int> intStack;


	acquireStack(intStack);
	printStack(intStack);
	emptyStack(intStack);
	printStack(intStack);
	system("PAUSE");
return 0;
}