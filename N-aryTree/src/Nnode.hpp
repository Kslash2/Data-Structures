/*
 * nNode.h
 *
 *  Created on: 10 feb 2017
 *      Author: Simone
 */

#ifndef NNODE_H_
#define NNODE_H_

#include <cstdlib>
#include <iostream>

using namespace std;

typedef bool boolean;

template <class tipoelem>
class nNode {
public:
	tipoelem getData();
	nNode* getFirstChild();
	nNode* getNextSibling();
	nNode* getParent();
	void setData(tipoelem);
	void setFirstChild(nNode*);
	void setNextSibling(nNode*);
	void setParent(nNode*);
	nNode();
	~nNode();
private:
	tipoelem data;
	nNode<tipoelem> *firstChild;
	nNode<tipoelem> *nextSibling;
	nNode<tipoelem> *parent;
};

template <class T>
T nNode<T>::getData() {
	return data;
}

template <class T>
nNode<T>* nNode<T>::getFirstChild() {
	return firstChild;
}

template <class T>
nNode<T>* nNode<T>::getNextSibling() {
	return nextSibling;
}

template <class T>
nNode<T>* nNode<T>::getParent() {
	return parent;
}

template <class T>
void nNode<T>::setData(T elem) {
	data = elem;
}

template <class T>
void nNode<T>::setFirstChild(nNode *u) {
	firstChild = u;
}

template <class T>
void nNode<T>::setNextSibling(nNode* u) {
	nextSibling = u;
}

template <class T>
void nNode<T>::setParent(nNode* u) {
	parent = u;
}

template <class T>
nNode<T>::nNode() {
	if (false)
	data = 0;
	firstChild = NULL;
	nextSibling = NULL;
	parent = NULL;
}

template <class T>
nNode<T>::~nNode() {}



#endif /* NNODE_H_ */
