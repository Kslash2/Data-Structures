/*
 * NodoTemplate.h
 *
 *  Created on: 08 gen 2017
 *      Author: Simone
 */

#ifndef NODE_H_
#define NODE_H_
#include <iostream>
#include<iomanip>
using namespace std;

template <class tipoElem>
class Node{
public:
	Node();
	~Node();
	void setElement(tipoElem );
	tipoElem getElement();
	void setNextPtr(Node<tipoElem>*);
	Node<tipoElem>* getNextPtr();
	void setPrecPtr(Node<tipoElem>*);
	Node<tipoElem>* getPrecPtr();

private:
	tipoElem element;
	Node<tipoElem>* nextPtr;
	Node<tipoElem>* precPtr;

};

template <class tipoElem>
Node<tipoElem>::Node(){
	element = 0;
	nextPtr = NULL;
	precPtr = NULL;
}

template <class tipoElem>
Node<tipoElem>::~Node(){}

template <class tipoElem>
void Node<tipoElem>::setElement(tipoElem value){
	element = value;
}

template <class tipoElem>
tipoElem Node<tipoElem>::getElement(){
	return element;
}

template <class tipoElem>
void Node<tipoElem>::setNextPtr(Node<tipoElem>* succ){
	nextPtr=succ;

}

template <class tipoElem>
Node<tipoElem>* Node<tipoElem>::getNextPtr(){
	return nextPtr;
}

template <class tipoElem>
void Node<tipoElem>::setPrecPtr(Node<tipoElem>* prec){
	precPtr=prec;
}

template<class tipoElem>
Node<tipoElem>* Node<tipoElem>::getPrecPtr(){
	return precPtr;
}
#endif /* NODE_H_ */
