/*
 * servicesNtree.h
 *
 *  Created on: 10 feb 2017
 *      Author: Simone
 */

#ifndef SERVICESNTREE_H_
#define SERVICESNTREE_H_

#include <iostream>
#include "queue/queue.hpp"
#include "Ntree.hpp"
#include "Nnode.hpp"

using namespace std;

template <class S>
void preOrder(nNode<S>* u,nTree<S> &T) {
	nNode<S>* c;
	printNode(u, T);
	if (!T.leaf(u)) {
		c = T.firstChild(u);
		while (!T.lastSibling(c)) {
			preOrder(c,T);
			c = T.nextSibling(c);
		}
		preOrder(c,T);
	}

}

template <class S>
void postOrder(nNode<S>* u,nTree<S> &T) {
	nNode<S>* c;
	if (!T.leaf(u)) {
		c = T.firstChild(u);
		while(!T.lastSibling(c)) {
			postOrder(c,T);
			c = T.nextSibling(c);
		}
		postOrder(c,T);
	}
	printNode(u,T);
}

template <class S>
void inOrder(nNode<S>*u,nTree<S> &T) {//inVisita
	nNode<S>* c;
	if (T.leaf(u))
		printNode(u,T);
	else {
		c = T.firstChild(u);
		inOrder(c,T);
		printNode(u,T);
		while(!T.lastSibling(c)) {
			c = T.nextSibling(c);
			inOrder(c,T);
		}
	}
}



template <class S>
void BFS(nNode<S>* u,nTree<S> &T) {
    nNode<S>* temp;
    Queue<nNode<S>*> coda;
    coda.push(u);
    while (!coda.isEmpty()) {
    	temp = coda.top();
        printNode(temp,T);
        coda.pop();
        if (!T.leaf(temp)) {
        	temp = T.firstChild(temp);
            while (!T.lastSibling(temp)) {
            	coda.push(temp);
                temp = T.nextSibling(temp);
            }
            coda.push(temp);
        }
    }
}

template <class S>
void printNode(nNode<S>* u, nTree<S> &T) {
	if (u!=NULL)
		cout << T.readNode(u) << "  ";
}

template <class S>
int compareValues(S a,S b) {
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
void autoAcquire(nTree<S> &T) {

	nNode<S> *u = new nNode<S>();

	T.insRoot(4);
	u = T.root();
	T.insFirstChild(3,u);
	u = T.firstChild(u);
	T.insNextSibling(6,u);
	u = T.nextSibling(u);
	T.insFirstChild(18,u);
	T.insNextSibling(7,u);
	u = T.nextSibling(u);
	T.insFirstChild(16,u);
	u = T.firstChild(u);
	T.insNextSibling(14,u);
	u = T.firstChild(T.root());
	T.insFirstChild(5,u);
	u = T.firstChild(u);
	T.insNextSibling(24,u);
	u = T.nextSibling(u);
	T.insNextSibling(9,u);
}

template <class S>
void acquire(nTree<S> &T) {
    Queue<nNode<S>*> tmp;
    bool finito;
    nNode<S>* aux;
    S info,infoPrimoFiglio;
	char risp;

	cout << "Insert root: " << endl;
	cin >> info;
    T.insRoot(info);
    aux = T.root();
    tmp.push(aux);
    while(!tmp.isEmpty()) {
       aux=tmp.top();
       tmp.pop();
       cout<<"If you want to insert first child of "<<aux->getData()<<" press S otherwise N:";
       do {
          cin>>risp;
       } while(toupper(risp)!='S' && toupper(risp)!='N');

       if (toupper(risp) == 'S') {
   		  cout<<"Insert first child of "<<aux->getData()<<": ";
       	  cin>>info;
          cout<<endl;
          T.insFirstChild(info,aux);
          aux=T.firstChild(aux);
          tmp.push(aux);
          infoPrimoFiglio=info;
          do {
            finito=true;
           	cout<<"If you want to insert a Sibling of "<<infoPrimoFiglio<<" press S otherwise N: ";
	        do {
               cin>>risp;
            } while(toupper(risp)!='S'&& toupper(risp)!='N');
      		if (toupper(risp)=='S') {
               cout<<"Sibling of "<<infoPrimoFiglio<<" is: ";
			   cin>>info;
               cout<<endl;
               T.insNextSibling(info,aux);
               aux=T.nextSibling(aux);
               tmp.push(aux);
				infoPrimoFiglio=info;
            finito=false;
            }
         } while(!finito);
      }
   }
}

template <class S>
int countNode(nNode<S>* u, nTree<S> &T){
	int cont = 0;
	return innerCountNode(u, T,cont);
}

template <class S>
int innerCountNode(nNode<S>* u, nTree<S> &T,int cont) {
	 if (!T.isEmpty()) {
		 nNode<S>* c;
	     cont++;
	     if (!T.leaf(u)) {
	    	 c = T.firstChild(u);
	    	 while (!T.lastSibling(c)) {
	    		 cont = innerCountNode(c, T,cont);
	             c = T.nextSibling(c);
	    	 }
	    	 cont = innerCountNode(c,T, cont);
	     }
	 }
	 return cont;
}

template <class S>
int countLeaves(nNode<S>* u,nTree<S> &T){
	int cont =0;
	return innerCountLeaves(u, T, cont);
}
template <class S>
int innerCountLeaves(nNode<S>* u,nTree<S> &T, int cont) {
	if (!T.isEmpty() && u != NULL) {
		nNode<S>* c;
		if (T.leaf(u))
			cont++;
		else {
			c = T.firstChild(u);
			while (!T.lastSibling(c)) {
				cont = innerCountLeaves(c,T, cont);
				c = T.nextSibling(c);
			}
			cont = innerCountLeaves(c,T, cont);
		}
	}
	return cont;
}



template <class S>
int height(nNode<S>* u, nTree<S> &T) {
	int max, temp;
    max = temp = 0;
    if (!T.isEmpty())
    	max = calcHeight(u, T, temp, max);
    return max;
}

template <class S>
int depthNode(nNode<S>* n, nTree<S> &T){
	if (T.root() == n)
		return 0;
	return 1 + depthNode(T.parent(n), T);
}

template <class S>
int calcHeight(nNode<S>* u, nTree<S> &T, int temp, int max) {
    nNode<S>* c;
    if (T.leaf(u)) {
    	if (temp >= max)
    		max = temp;
     } else {
             temp++;
             {
            	 c = T.firstChild(u);
                 while (!T.lastSibling(c)) {
                	 max = calcHeight(c,T,temp,max);
                     c = T.nextSibling(c);
                 }
                     max = calcHeight(c,T, temp, max);
             }
     }
     return max;
}


template <class S>
nNode<S>* searchNode(S c,nTree<S> &a) {
	S s;
    nNode<S>* rad = new nNode<S>();
    nNode<S>* temp= new nNode<S>();
    boolean trovato = false;
    Queue<nNode<S>*> cod;

    rad = a.root();
    if (rad->getData() == c)
    	return rad;

    cod.push(rad);
    while (!cod.isEmpty() && trovato == false) {
    	temp = cod.top();
        s = temp->getData();
        cod.pop();
        if (s == c) {
        	trovato = true;
            	return temp;
        } else if (!a.leaf(temp)) {
        	temp = a.firstChild(temp);
            while (!a.lastSibling(temp)) {
            	cod.push(temp);
                temp = a.nextSibling(temp);
            }
            cod.push(temp);
        }
    }
    if (cod.isEmpty())
    	cout << "element not found" << endl;
    return NULL;
}

#endif /* SERVICESNTREE_H_ */
