/*
 * BinaryTreeServices.h
 *
 *  Created on: 07 feb 2017
 *      Author: Simone
 */

#ifndef BINARYTREESERVICES_H_
#define BINARYTREESERVICES_H_

#include "Btree.hpp"
#include "queue/queue.hpp"



template <class S>
void preOrder(Btree<S> &T,Tnode<S>* u) {
	if (!T.isEmpty()) {
		printNode(u, T);
		if (!T.leftEmpty(u))
			preOrder(T,T.leftChild(u));
		if (!T.rightEmpty(u))
			preOrder(T,T.rightChild(u));
	}
}

template <class S>
void inOrder(Btree<S> &T,Tnode<S>* u) {
	if (!T.isEmpty()) {
		if(!T.leftEmpty(u))
			inOrder(T,T.leftChild(u));
		printNode(u, T);
		if(!T.rightEmpty(u))
			inOrder(T,T.rightChild(u));
	}
}

template <class S>
void postOrder(Btree<S> &T,Tnode<S>* u) {
	if (!T.isEmpty()) {
		if(!T.leftEmpty(u))
			postOrder(T,T.leftChild(u));
		if(!T.rightEmpty(u))
			postOrder(T,T.rightChild(u));
		printNode(u, T);
	}
}

template <class S>
void BFS(Btree<S> &T) {
	Queue<Tnode<S>*> coda;
	Tnode<S>* x;

	if (!T.isEmpty()) {
			printNode(T.root(), T);
			coda.push(T.root());
			while (!coda.isEmpty()) {
				x = coda.top();
				coda.pop();
				if (!T.leftEmpty(x)) {
					printNode(T.leftChild(x),T);
					coda.push(T.leftChild(x));
				}
				if (!T.rightEmpty(x)) {
					printNode(T.rightChild(x), T);
					coda.push(T.rightChild(x));
				}
			}
		}
}


template <class S>
void printNode(Tnode<S>* u, Btree<S> &T) {
	cout << T.readNode(u) << "  ";
}

template <class S>
int compareValues(S a,S b){
	int conf;
	if(a<b)
		conf = -1;
	if(a==b)
		conf = 0;
	if(a>b)
		conf = 1;
	return conf;
}

template <class S>
void acquire(Btree<S> &T) {
	S elem;

	cout<<"insert element (-1 to stop): ";
	cin>>elem;
	while (elem != -1) {
		if (!T.isEmpty()) {
			insertOrdered(T,T.root(),elem);
		} else {
			T.createBinTree();
			T.insRoot();
			T.writeNode(elem,T.root());
		}
		cout<<"insert element (-1 to stop): ";
		cin>>elem;
	}
}

template <class S>
void autoAcquire(Btree<S> &T) {

	T.insRoot();
	Tnode<S>* radix = T.root();
	  T.writeNode(49,T.root());

	  T.insLeftChild(radix);
	  Tnode<S>* left = T.leftChild(radix);
	  T.writeNode(22,left);

	  T.insRightChild(radix);
	  Tnode<S>* right = T.rightChild(radix);
	  T.writeNode(82,right);

	  T.insLeftChild(left);
	  Tnode<S>* leftA = T.leftChild(left);
	  T.writeNode(17,leftA);

	  T.insLeftChild(right);
	  Tnode<S>* leftB = T.leftChild(right);
	  T.writeNode(57,leftB);

	  T.insRightChild(right);
	  Tnode<S>* rightA = T.rightChild(right);
	  T.writeNode(88,rightA);


}

template <class S>
void insertOrdered( Btree<S> &T,Tnode<S>* u,S e) {
	if (T.isEmpty()) {
		T.insRoot();
		T.writeNode(e,T.root());
	} else {
		if (compareValues(e,T.readNode(u)) == -1) {
			if (T.leftEmpty(u)) {
				T.insLeftChild(u);
				T.writeNode(e,T.leftChild(u));
			} else
				insertOrdered(T,T.leftChild(u),e);
		}
		if (compareValues(e,T.readNode(u)) == 1) {
			if (T.rightEmpty(u)) {
				T.insRightChild(u);
				T.writeNode(e,T.rightChild(u));
			} else
				insertOrdered(T,T.rightChild(u),e);   // chiamata ricorsiva
		}
		if (compareValues(e,T.readNode(u)) == 0)
			cout<<"Element already present!!!"<<endl;
	}
}

template <class S>
int height(Btree<S> &T, Tnode<S>* u) {
	int max,corr;
	if (T.leftEmpty(u) && T.rightEmpty(u))
		return 0;
	else {
		max = 0;
		if (!T.leftEmpty(u)) {
			corr = height(T,T.leftChild(u));
			if (max <= corr)
				max = corr;
		}
		if (!T.rightEmpty(u)) {
			corr = height(T,T.rightChild(u));
			if (max <= corr)
				max = corr;
		}
		return (max+1);
	}
}


template <class S>
int countNodes(Btree<S> &T,Tnode<S>* u ){
	int num = 0;
	if(!T.isEmpty()){
		if (!T.leftEmpty(u))
			num = num + countNodes(T,T.leftChild(u));
		if (!T.rightEmpty(u))
			num = num + countNodes(T,T.rightChild(u));
		num++;
	}
	return num;
}

template <class S>
bool preOrderSearch(Btree<S> &T,Tnode<S>* u, S elem){
	bool found=false;
	return innerPreOrderSearch(T, u, elem, found);
}

template <class S>
bool innerPreOrderSearch(Btree<S> &T,Tnode<S>* u, S elem, bool found){

	if (!T.isEmpty()) {
		if(T.readNode(u)==elem){
			found = 1;
		}

		if (!T.leftEmpty(u))
			found = preOrderSearch(T,T.leftChild(u), elem);
		if (!T.rightEmpty(u))
			found = preOrderSearch(T,T.rightChild(u), elem);

	}

	return found;
}

template <class S>
int getLevel( Btree<S> &T,Tnode<S>* u, S x){
  return getLevelUtil(T,u,x,0);
}

template <class S>
int getLevelUtil( Btree<S> &T,Tnode<S>* u, S x, int level){
  if(u==NULL)
    return 0;
  if (compareValues(x,T.readNode(u)) == 0)
    return level;
  int downlevel = getLevelUtil(T,T.leftChild(u),x,level+1);
  if(downlevel!=0)
    return downlevel;

  downlevel = getLevelUtil(T,T.rightChild(u),x,level+1);
  return downlevel;
}



template <class S>
bool binarySearchBool(Btree<S> &T, Tnode<S>* u, S x){
  bool trovato = false;
  if(!T.isEmpty()){
    if( x == T.readNode(u)){
      //printNode(u,T);
      return trovato=true;
    }else if(x<T.readNode(u) && !T.leftEmpty(u)){
       return binarySearchBool(T,T.leftChild(u),x);
    }else if(x>T.readNode(u) && !T.rightEmpty(u)){
       return binarySearchBool(T,T.rightChild(u),x);
    }

  }else{
    cout << "Empty Tree" << endl;
  }

  return trovato;


}

template <class S>
Tnode<S>* binarySearch(Btree<S> &T, Tnode<S>* u, S x){
  if(!T.isEmpty()){
    if( x == T.readNode(u)){
      printNode(u,T);
      return u;
    }else if(x<T.readNode(u) && !T.leftEmpty(u)){
      return binarySearch(T,T.leftChild(u),x);
    }else if(x>T.readNode(u) && !T.rightEmpty(u)){
      return binarySearch(T,T.rightChild(u),x);
    }

  }else{
    cout << "Empty Tree" << endl;
  }
  return NULL;
}

template <class S>
Tnode<S>* searchNode(Btree<S> &T,Tnode<S>* u,S elem ) {
	Tnode<S>* nodo = NULL;
	if (!T.isEmpty()) {
		if (compareValues(elem,T.readNode(u)) == 0)
			nodo = u;
		else {
			if (T.leftEmpty(u) && T.rightEmpty(u))
				nodo = NULL;
			else {
				if (!T.leftEmpty(u))
					nodo = searchNode(T,T.leftChild(u),elem);
				if (nodo == NULL && !T.rightEmpty(u))
					nodo = searchNode(T,T.rightChild(u),elem);
			}

		}
	}
	return nodo;
}

template <class S>
Tnode<S>* OrderedSearch(Btree<S> &T,Tnode<S>* u,S elem ) {
	Tnode<S>* nodo = NULL;
	int res;
	if(!T.isEmpty()){
		res = compareValues(elem, T.readNode(u));
		if(res == 0)
			nodo = u;
		else if(res == -1){
			if(T.leftEmpty(u))
				nodo = 0;
			else
				nodo = OrderedSearch(T, T.leftChild(u),elem);
		}else if(res == 1){
			if(T.rightEmpty(u))
				nodo = 0;
			else
				nodo = OrderedSearch(T, T.rightChild(u), elem);
		}
	}
	return nodo;
}


#endif /* BINARYTREESERVICES_H_ */
