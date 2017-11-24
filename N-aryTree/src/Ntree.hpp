/*
 * Ntree.h
 *
 *  Created on: 10 feb 2017
 *      Author: Simone
 */

#ifndef NTREE_H_
#define NTREE_H_

#include <iostream>
#include <cstdlib>
#include <assert.h>
#include "Nnode.hpp"

using namespace std;

typedef bool boolean;

template <class T>
class nTree {
public:
	void createNTree();
	boolean isEmpty();
	void insRoot(T);
	nNode<T>* root();
	nNode<T>* parent(nNode<T>*);
	boolean leaf(nNode<T>*);
	nNode<T>* firstChild(nNode<T>*);
	boolean lastSibling(nNode<T>*);
	nNode<T>* nextSibling(nNode<T>*);
	void insFirstChild(T, nNode<T>*);
	void insNextSibling(T, nNode<T>*);
	void delSubTree(nNode<T>*);
	T readNode(nNode<T>*);
	void writeNode(T, nNode<T>*);

	nTree();
	~nTree();
private:
	nNode<T>* radice;
};


template <class T>
void nTree<T>::createNTree() {
	radice = NULL;
}

template <class T>
boolean nTree<T>::isEmpty() {
	return (radice == NULL);
}

template <class T>
void nTree<T>::insRoot(T elem) {
	radice = new nNode<T>;
	writeNode(elem,radice);
	radice->setFirstChild(NULL);
	radice->setNextSibling(NULL);
	radice->setParent(NULL);
}

template <class T>
nNode<T>* nTree<T>::root() {
	return radice;
}

template <class T>
nNode<T>* nTree<T>::parent(nNode<T>* u) {
	assert(!isEmpty() && u != radice);
	return u->getParent();
}

template <class T>
boolean nTree<T>::leaf(nNode<T>*u) {
	assert(!isEmpty());
	return (u->getFirstChild() == NULL);
}

template <class T>
nNode<T>* nTree<T>::firstChild(nNode<T>* u) {
	assert(!isEmpty() && !leaf(u));
	return u->getFirstChild();
}

template <class T>
boolean nTree<T>::lastSibling(nNode<T>* u) {
	assert(!isEmpty());
	return (u->getNextSibling()==NULL);
}

template <class T>
nNode<T>* nTree<T>::nextSibling(nNode<T>* u) {
	assert(!isEmpty() && !lastSibling(u));
	return u->getNextSibling();
}

template <class T>
void nTree<T>::insFirstChild(T elem, nNode<T>* u) {
	assert(!isEmpty() && leaf(u));
    if (!isEmpty() && leaf(u)) {
        nNode<T>* nuovo = new nNode<T>();
        writeNode(elem, nuovo);
        u->setFirstChild(nuovo);
        nuovo->setParent(u);
        nuovo->setFirstChild(NULL);
        nuovo->setNextSibling(NULL);
    }
}

template <class T>
void nTree<T>::insNextSibling(T elem, nNode<T>* u) {
	assert(!isEmpty() && lastSibling(u) && u!=radice);
    if (!isEmpty() && lastSibling(u) && u != radice) {
        nNode<T> *nuovo = new nNode<T>();
        writeNode(elem, nuovo);
        u->setNextSibling(nuovo);
        nuovo->setParent(u->getParent());
        nuovo->setNextSibling(NULL);
        nuovo->setFirstChild(NULL);
    }
}

template <class T>
void nTree<T>::delSubTree(nNode<T>* n) {
	nNode<T> *temp;
	if(n != radice) {
        if ( (n->getParent())->getFirstChild() ==  n )
        	(n->getParent())->setFirstChild(n->getNextSibling());
		else {
            temp = (n->getParent())->getFirstChild();
            while(temp->getNextSibling() != n)
            	temp = temp->getNextSibling();
            temp->setNextSibling(n->getNextSibling());
		}
    } else {
    	nNode<T>* u;
    	u = firstChild(radice);
    	while(!lastSibling(u)) {
    		delSubTree(u);
    		u = nextSibling(u);
    	}
    	radice = NULL;
    	cout << "Tree was completely removed." << endl;
    }
    if(n->getFirstChild() != NULL ){
        temp = n->getFirstChild();
        if(temp->getNextSibling() != NULL)
        	delSubTree(temp->getNextSibling());
        delSubTree(temp);
    }
    delete n;
}

template <class T>
T nTree<T>::readNode(nNode<T>* u) {
	return u->getData();
}

template <class T>
void nTree<T>::writeNode(T elem, nNode<T>* u) {
	u->setData(elem);
}

template <class T>
nTree<T>::nTree() {
	createNTree();
}

template <class T>
nTree<T>::~nTree() {}



#endif /* NTREE_H_ */
