/*
 * CircularQueue.h
 *
 *  Created on: 31 gen 2017
 *      Author: Simone
 */


#ifndef CIRCULARQUEUE_H_
#define CIRCULARQUEUE_H_

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class CircularQueue
{
	private :
	 	std::vector<int> V;
		int head;
		int MAX;
		int length;
	public :
		CircularQueue( int maxsize);
		int top();
		int getBottom();
		bool isEmpty();
		void push ( T item );
		void pop( );
		void display( );

} ;

#include "CircularQueue.h"

template <class T>
CircularQueue<T>::CircularQueue(int maxSize):V(vector<T>(maxSize)){

	MAX=maxSize;

	head=0;
	for(int i=0;i<MAX;i++){
		V[i]=0;
	}
	length=0;

}


template <class T>
bool CircularQueue<T>::isEmpty(){
	if(length ==0){
		return true;
	}
	else{
		 return false;
		}
}

template <class T>
int CircularQueue<T>::top(){
	if(isEmpty()){
		cout << "The queue is empty" << endl;
		return 0;
	}
	else{
		return V[head];
	}
}

template <class T>
void CircularQueue<T>::pop(){
	if(isEmpty()){
			cout << "The queue is empty" << endl;

	}
	else{
		head = (head+1)%MAX;
		length--;
	}

}

template <class T>
void CircularQueue<T>::push(T item){

	if(length==MAX){
		cout << "The queue is full" << endl;
	}
	else{
		V[(head+length)%MAX]= item;
		length++;
	}

}

template <class T>
int CircularQueue<T>::getBottom(){
	if(!isEmpty()){
		return V[(head+length-1)%MAX];
	}
	else{
		return -1;
	}
}

/////////////////////////////////////////////////////////

template <class T>
void CircularQueue<T>::display( )
{
	cout << endl ;
	for ( int i = 0 ; i < MAX ; i++ )
		cout << V[i] << "  " ;
	cout << endl ;
}




#endif /* CIRCULARQUEUE_H_ */



