/*
 * Stack.h
 *
 *  Created on: 10 gen 2017
 *      Author: Simone
 */

#ifndef STACK_H_
#define STACK_H_


#include <iostream>
#include<iomanip>
#include "Node.hpp"
using namespace std;

template <class typeElem>
class Stack {
public:


	 Stack();
	 ~Stack();

	 //create a stack
	 void create();

	 //Control if stack is empty
	 bool isEmpty();

	 //read the stack, the first element of course.
	 typeElem top();

	 //pop out the first element
	 void pop();

	 // insert an element into the Stack
	 void push(typeElem);

private:
	 Node<typeElem>* head;
};

template<class typeElem>
Stack<typeElem>::Stack() {
	head = NULL;
}

template <class typeElem>
Stack<typeElem>::~Stack(){}

template<class typeElem>
void Stack<typeElem>::create(){
	Stack();
}

template<class typeElem>
bool Stack<typeElem>::isEmpty(){
	if(head == NULL){
		return true;
	}
	else {
		return false;
	}
}

template<class typeElem>
void Stack<typeElem>::push(typeElem newElem){
	Node<typeElem>* nuovo = new Node<typeElem>;
	        nuovo->setElement(newElem);
	        if (!isEmpty()){
	        	nuovo->setNext(head);
	        }
	        head = nuovo;

}

template<class typeElem>
void Stack<typeElem>::pop(){
	if(isEmpty()){
		cout << "stack empty";
	}
	else {
		Node<typeElem>* app;
		app = head;
		head= head->getNext();
		delete(app);
	}

}

template<class typeElem>
typeElem Stack<typeElem>::top(){

	if(isEmpty()){
		cout << "no stack, no head, sorry!" << endl;
		return 0;
	}
	else{
		return head->getElement();
	}

}


#endif /* STACK_H_ */
