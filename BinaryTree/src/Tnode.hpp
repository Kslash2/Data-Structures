/*
 * Tnode.h
 *
 *  Created on: 07 feb 2017
 *      Author: Simone
 */

#ifndef TNODE_H_
#define TNODE_H_


#include <iostream>

using namespace std;

typedef bool boolean;

template <class tipoelem>
class Tnode {
public:
	Tnode();
	~Tnode();
	void setElem(tipoelem);
	void setParent(Tnode<tipoelem>*);
	void setLeftChild(Tnode<tipoelem>*);
	void setRightChild(Tnode<tipoelem>*);

	tipoelem getElem();
	Tnode<tipoelem>* getParent();
	Tnode<tipoelem>* getLeftChild();
	Tnode<tipoelem>* getRightChild();

private:
	tipoelem data;
	Tnode* parent;
	Tnode* leftChild;
	Tnode* rightChild;
};

template <class T>
Tnode<T>::Tnode(){
	data = 0;
	parent = NULL;
	leftChild = NULL;
	rightChild = NULL;
}
template <class T>
Tnode<T>::~Tnode(){
	parent= NULL;
	delete leftChild;
	delete rightChild;
}

template <class T>
void Tnode<T>::setElem(T elem) {
	data = elem;
}

template <class T>
void Tnode<T>::setParent(Tnode<T>* u) {
	parent = u;
}

template <class T>
void Tnode<T>::setLeftChild(Tnode<T>* u) {
	leftChild = u;
}

template <class T>
void Tnode<T>::setRightChild(Tnode<T>* u) {
	rightChild = u;
}

template <class T>
T Tnode<T>::getElem() {
	return data;
}

template <class T>
Tnode<T>* Tnode<T>::getParent() {
	return parent;
}

template <class T>
Tnode<T>* Tnode<T>::getLeftChild() {
	return leftChild;
}


template <class T>
Tnode<T>* Tnode<T>::getRightChild() {
	return rightChild;
}


#endif /* TNODE_H_ */
