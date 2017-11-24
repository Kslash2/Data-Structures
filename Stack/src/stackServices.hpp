/*
 * stackServices.h
 *
 *  Created on: 10 gen 2017
 *      Author: Simone
 */

#ifndef STACKSERVICES_H_
#define STACKSERVICES_H_

#include <iostream>
#include <stdlib.h>
using namespace std;

#include "Stack.hpp"
#include "Node.hpp"

template <class T>
void acquireStack(Stack<T> &);

template <class T>
void printStack(Stack<T>);

template <class T>
void EmptyStack(Stack<T> &);



template <class T>
void acquireStack(Stack<T> &stack){

	T element;
	stack.create();
	for(element=1;element<6; element++){
			stack.push(element);
	}

}


template <class T>
void printStack(Stack<T> stack){

	Stack<T> app;

	if(stack.isEmpty()){
		cout << "Can't print, stack is empty" << endl;
	}
	else{
		while(!stack.isEmpty()){
			app.push(stack.top());
			stack.pop();
		}
		while(!app.isEmpty()){
			cout << app.top() << " ";
			stack.push(app.top());
			app.pop();

		}
		cout<<endl<<endl;

	}
}

template <class T>
void emptyStack(Stack<T> &stack){

	int i=0;
	while(!stack.isEmpty()){
		stack.pop();
		cout << "Deleting element: " << i << ", from stack..." << endl;
		i++;
	}

	cout << "Stack is now empty" << endl;

}


#endif /* STACKSERVICES_H_ */
