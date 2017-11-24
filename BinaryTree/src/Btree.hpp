/*
 * TBtree.h
 *
 *  Created on: 07 feb 2017
 *      Author: Simone
 */

#ifndef BTREE_H_
#define BTREE_H_


#include <iostream>
#include <assert.h>
#include "Tnode.hpp"

using namespace std;

template <class tipoelem>
class Btree {
public:
	typedef Tnode<tipoelem> NodeBtree;

	void createBinTree();
	boolean isEmpty();
	NodeBtree* root();
	NodeBtree* parent(NodeBtree*);
	NodeBtree* leftChild(NodeBtree*);
	NodeBtree* rightChild(NodeBtree*);
	boolean leftEmpty(NodeBtree*);
	boolean rightEmpty(NodeBtree*);
	tipoelem readNode(NodeBtree*);
	void writeNode(tipoelem, NodeBtree*);
	void insRoot();
	void insLeftChild(NodeBtree*);
	void insRightChild(NodeBtree*);
	void delSubTree(NodeBtree*);
	Btree();
	~Btree();
private:
	NodeBtree* albero;
};

template <class T>
Btree<T>::Btree() {
	createBinTree();
}

template <class T>
Btree<T>::~Btree() {}

template <class T>
void Btree<T>::createBinTree() {
	albero = NULL;
}

template <class T>
boolean Btree<T>::isEmpty() {
	return (albero == NULL);
}

template <class T>
Tnode<T>* Btree<T>::root() {
	if(!isEmpty()){
	  return albero;
	 }
	 else{
		 return NULL;
	 }
}

template <class T>
Tnode<T>* Btree<T>::parent(NodeBtree* u) {
	 if(!isEmpty()){
	  return u->getParent();
	  }
	  else{
		  return NULL;
	  }
}

template <class T>
Tnode<T>* Btree<T>::leftChild(NodeBtree* u) {
	if(!isEmpty() && !leftEmpty(u)){
		return u->getLeftChild();
		}
		else {
			return NULL;
		}
}

template <class T>
Tnode<T>* Btree<T>::rightChild(NodeBtree* u) {
	if(!isEmpty() && !rightEmpty(u)){
	  return u->getRightChild();
	  }
	  else {
		  return NULL;
	  }
}

template <class T>
boolean Btree<T>::leftEmpty(NodeBtree* u) {
	return (u->getLeftChild() == NULL);
}

template <class T>
boolean Btree<T>::rightEmpty(NodeBtree* u) {
	return (u->getRightChild() == NULL);
}

template <class T>
T Btree<T>::readNode(NodeBtree* u) {
	return u->getElem();
}

template <class T>
void Btree<T>::writeNode(T elem, NodeBtree* u) {
	u->setElem(elem);
}

template <class T>
void Btree<T>::insRoot() {
	if(isEmpty()){
	albero = new Tnode<T>();
    }
}

template <class T>
void Btree<T>::insLeftChild(NodeBtree* u) {
	if(!isEmpty() && leftEmpty(u)){
	NodeBtree* temp = new NodeBtree();
	u->setLeftChild(temp);
	temp->setParent(u);
	}
}

template <class T>
void Btree<T>::insRightChild(NodeBtree* u) {
	if(!isEmpty() && rightEmpty(u)){
	NodeBtree* temp = new NodeBtree();
	u->setRightChild(temp);
	temp->setParent(u);
	}
}

template <class T>
void Btree<T>::delSubTree(NodeBtree* u) {
	if (!isEmpty()) {
		if (u == albero)
			albero=NULL;
		else {
			NodeBtree* parent = u->getParent();
			if (u==parent->getfiglioSinistro())
				parent->setfiglioSinistro(NULL);
			else
				parent->setRightChild(NULL);
			delete u;
			}
	}
	else{
		cout << "Empty Tree!";
	}
}


#endif /* BTREE_H_ */
