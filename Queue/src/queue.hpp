/*
 * queue.h
 *
 *  Created on: 11 gen 2017
 *      Author: Simone Kslash Angeletti
 */

#ifndef QUEUE_H_
#define QUEUE_H_


#include <iostream>
#include<iomanip>
#include "node.hpp"
using namespace std;

template <class typeElem>
class Queue {
public:


	 Queue();
	 ~Queue();

	 //create a queue
	 void create();

	 //Control if queue is empty
	 bool isEmpty();

	 //read the queue, the first element of course.
	 typeElem top(); //leggicoda
	 
	 //read the last element of queue, the tail.
	 typeElem bot();
	 
	 //pop out the first element
	 void pop(); //fuoricoda

	 // insert an element into the queue
	 void push(typeElem);

private:
	 Node<typeElem>* head;
	 Node<typeElem>* tail;
};

template<class typeElem>
Queue<typeElem>::Queue() {
	head = NULL;
	tail = NULL;
}

template <class typeElem>
Queue<typeElem>::~Queue(){}

template<class typeElem>
void Queue<typeElem>::create(){
	Queue();
}

template<class typeElem>
bool Queue<typeElem>::isEmpty(){
	if(head == NULL){
		return true;
	}
	else {
		return false;
	}
}

template<class typeElem>
void Queue<typeElem>::push(typeElem newElem){
	Node<typeElem>* added = new Node<typeElem>;
	        added->setElement(newElem);
	        if (isEmpty()){
	        	tail = added;
	        	head = tail;
	        }
	        else{
	        	tail->setNext(added);
	        	tail = added;
	        }
	        
	        

}

template<class typeElem>
void Queue<typeElem>::pop(){
	if(isEmpty()){
		cout << "Queue empty";
	}
	else {
		Node<typeElem>* app;
		app = head;
		head= head->getNext();
		delete app;
	}

}

template<class typeElem>
typeElem Queue<typeElem>::top(){

	if(isEmpty()){
		cout << "Queue not found, no head found then, sorry!" << endl;
		return 0;
	}
	else{
		return head->getElement();
	}


}

template<class typeElem>
typeElem Queue<typeElem>::bot(){

	if(isEmpty()){
		cout << "Queue not found, no tail found then, sorry!" << endl;
		return 0;
	}
	else{
		return tail->getElement();
	}
}



#endif /* QUEUE_H_ */
