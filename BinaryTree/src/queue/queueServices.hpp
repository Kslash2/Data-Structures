/*
 * queueServices.h
 *
 *  Created on: 11 gen 2017
 *      Author: Simone Kslash Angeletti
 */

#ifndef QUEUESERVICES_H_
#define QUEUESERVICES_H_


#include <iostream>
#include <stdlib.h>
using namespace std;

#include "queue.h"
#include "node.h"

template <class T>
void acquireQueue(Queue<T> &);

template <class T>
void emptyQueue(Queue<T> &);

template<class typeElem>
void cancElement(Queue<typeElem> &queue);

template<class typeElem>
bool searchElement(Queue<typeElem> &queue, typeElem key);

template<class typeElem>
void printQueue(Queue<typeElem> &queue);

template<class typeElem>
int countElements(Queue<typeElem> &queue);


template <class typeElem>
void acquireQueue(Queue<typeElem> &queue){

	typeElem element;
	queue.create();
	for(element=1;element<6; element++){
			queue.push(element);
	}

}


template <class typeElem>
void emptyQueue(Queue<typeElem> &queue){

	if(queue.isEmpty()){
		cout<<"The queue is empty"<<endl;
	}
	else{
	int i=0;
	while(!queue.isEmpty()){
		queue.pop();
		cout << "Deleting element: " << i << ", from queue..." << endl;
		i++;
	}
	cout << "Queue is now empty" << endl;
	}
}

template<class typeElem>
void cancElement(Queue<typeElem> &queue, typeElem x){
	Queue<typeElem> temp;
	typeElem info;
	bool found = false;
	if(queue.isEmpty()){
		cout<<"The queue is empty"<<endl;
	}else{
		while(!queue.isEmpty() ){
			info = queue.top();
			queue.pop();
			if(info==x){
				found = true;
				cout << "The element: "<< x << ", was deleted successfully"<< endl;
			}else{
				temp.push(info);
			}
		}if(!found){
			cout<<"Element doesn't exist "<<endl;
		}while(!temp.isEmpty()){
			info = temp.top();
			queue.push(info);
			temp.pop();

		}

	}
}

template<class typeElem>
bool searchElement(Queue<typeElem> &queue, typeElem key){
	Queue<typeElem> temp;
	bool found = false;

	if(queue.isEmpty()){
		cout<<"the queue is empty"<<endl;
	}else{
		while(!queue.isEmpty()){
			temp.push(queue.top());
			if(queue.top()==key){
				found = true;
			}
			queue.pop();
		}
		while(!temp.isEmpty()){
			queue.push(temp.top());
			temp.pop();
		}
	}
	return found;
}

template<class typeElem>
void printQueue(Queue<typeElem> &queue){
	Queue<typeElem> temp;
	if(queue.isEmpty()){
		cout<<"The queue is empty"<<endl;
	}else{
		while(!queue.isEmpty()){
			temp.push(queue.top());
			cout<<queue.top()<<endl; //print vertical
			queue.pop();
		}
		while(!temp.isEmpty()){
			//cout<<temp.first()<<" "; //print horizontal
			queue.push(temp.top());
			temp.pop();
		}
	}
	cout<<endl;
}

template<class typeElem>
int countElements(Queue<typeElem> &queue){
	int i = 0;
	Queue<typeElem> temp;
	if(queue.isEmpty()){
		cout<<"The queue is empty"<<endl;
	}else{
		while(!queue.isEmpty()){
			temp.push(queue.top());
			queue.pop();
		}
		while(!temp.isEmpty()){
			queue.push(temp.top());
			i++;
			temp.pop();
		}
	}
	return i;
}


#endif /* QUEUESERVICES_H_ */
