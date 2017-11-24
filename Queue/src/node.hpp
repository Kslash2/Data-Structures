/*
 * node.h
 *
 *  Created on: 11 gen 2017
 *      Author: Simone Kslash Angeletti
 */

//Queue's node

#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include<iomanip>
using namespace std;

template <class typeElem>
class Node {
public:

	 Node();
	 ~Node();
	 typeElem getElement();
	 void setElement(typeElem element);
	 Node<typeElem> *getNext();
	 void setNext(Node<typeElem> *next);
private:
	typeElem elem;
	Node* nextPtr;
};

template <class typeElem>
Node<typeElem>::Node() {
	nextPtr = NULL;
}

template <class typeElem>
Node<typeElem>::~Node() {
	
}


template <class typeElem>
void Node<typeElem>::setElement(typeElem element){
	elem = element;
}

template <class typeElem>
typeElem Node<typeElem>::getElement(){
	return elem;
}

template <class typeElem>
void Node<typeElem>::setNext(Node<typeElem>* nextP){
	nextPtr = nextP;
}

template <class typeElem>
Node<typeElem>* Node<typeElem>::getNext(){
	return nextPtr;
}



#endif /* NODE_H_ */
