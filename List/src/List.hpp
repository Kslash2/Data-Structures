/*
 * list.h
 *
 *  Created on: 08 gen 2017
 *      Author: Simone
 */

#ifndef LIST_H_
#define LIST_H_
#include<iostream>
#include<iomanip>
#include<assert.h>

#include "Node.hpp"
using namespace std;


typedef bool boolean;

template <class tipoElem, class posizione>
class List{
public:
	List();
	~List();
	void createList();
	boolean isEmpty();
	tipoElem readList(posizione);
	void writeList(tipoElem,posizione);
	posizione firstList();
	posizione lastList();
	boolean endList(posizione);
	posizione succList(posizione);
	posizione precList(posizione);
	void insList(tipoElem, posizione);
	void cancList(posizione);



private:

	Node<tipoElem> *head;
};

//Constructor
template <class tipoElem, class posizione>
List<tipoElem, posizione>::List(){
	createList();
}

//Destructor
template<class tipoElem,class posizione>
List<tipoElem, posizione>::~List(){}

//create a list
template<class tipoElem, class posizione>
void List<tipoElem,posizione>::createList(){
	head=NULL;
}

//control if list is empty
template<class tipoElem, class posizione>
boolean List<tipoElem, posizione>::isEmpty(){
	return (head==NULL ? true : false);
}

//read the value of the element of the position given node
template<class tipoElem, class posizione>
tipoElem List<tipoElem, posizione>::readList(posizione pos){
	assert(!isEmpty());
	return pos->getElement();
}

//write the value of an element of the position given node
template<class tipoElem, class posizione>
void List<tipoElem, posizione>::writeList(tipoElem dato, posizione pos){
	assert(!isEmpty() && pos!=NULL);
	pos->setElemento(dato);
}

//first of the list, return the head
template<class tipoElem, class posizione>
posizione List<tipoElem,posizione>::firstList(){
	return head;
}

//last of the list
template<class tipoElem, class posizione>
posizione List<tipoElem, posizione>::lastList(){
	posizione p = firstList();
	while(p->getNextPtr()!=NULL && !endList(p)){
		p=succList(p);
	}
	return p;
}

//control if we are on the edge of the list, (start or finish both)
template<class tipoElem, class posizione>
boolean List<tipoElem,posizione>::endList(posizione pos){
	return(pos==NULL);
}

//just go to the next node
template<class tipoElem, class posizione>
posizione List<tipoElem,posizione>::succList(posizione pos){
	assert(pos!=NULL);
	return pos->getNextPtr();
}

//just go to the previous node
template<class tipoElem, class posizione>
posizione List<tipoElem,posizione>::precList(posizione pos){
	assert(pos!=NULL);
	return pos->getPrecPtr();
}

//Insert a node into the list
template<class tipoElem, class posizione>
void List<tipoElem,posizione>::insList(tipoElem dato, posizione pos){
	Node<tipoElem>* nuovo = new Node<tipoElem>();
	nuovo->setElement(dato);


	if(pos!=NULL){

		posizione pre = pos->getPrecPtr();
		nuovo->setNextPtr(pos);
		nuovo->setPrecPtr(pre);
		pos->setPrecPtr(nuovo);

		if(firstList()==pos){
			nuovo->setNextPtr(pos);
			pos->setPrecPtr(nuovo);
			nuovo->setPrecPtr(NULL);
			head=nuovo;

		}else{
			pre->setNextPtr(nuovo);
		}
	}else{ //if  pos==NULL
		if(isEmpty()){
			nuovo->setPrecPtr(NULL);
			head = nuovo;
		}else{
			 pos = firstList();
				while(pos->getNextPtr()!=NULL && !endList(pos)){
					pos=succList(pos);
				}
				pos->setNextPtr(nuovo);
				nuovo->setPrecPtr(pos);
		}
			nuovo->setNextPtr(NULL);

	}
}

//delete a node of the list
template<class tipoElem,class posizione>
void List<tipoElem,posizione>::cancList(posizione pos){
	if(pos!=NULL){
		if(isEmpty()){
			cout<<"list empty"<<endl;
		}else if(pos->getPrecPtr()==NULL && pos->getNextPtr()==NULL){	//only 1 element case
			head=NULL;
			delete pos;
		}else if(pos==firstList()){	//deleting head element
			posizione succ = succList(pos);
			succ->setPrecPtr(NULL);
			delete pos;
			head=succ;
		}else if(pos==lastList()){	//deleting last element
			posizione prec =precList(pos);
			prec->setNextPtr(NULL);
			delete pos;

		}else{		//deleting in generic position
			posizione pre = precList(pos);
			posizione succ = succList(pos);
			pre->setNextPtr(succ);
			succ->setPrecPtr(pre);
			delete pos;
		}

	}else{
		cout<<"Position not correct"<<endl;
	}
}

#endif /* LIST_H_ */
