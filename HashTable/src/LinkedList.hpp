/*
 * LinkedList.h
 *
 *  Created on: 15 feb 2017
 *      Author: Simone Kslash Angeletti
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_


#include <iostream>
#include <string>
using namespace std;

//*****************************************************************
// List items are keys with pointers to the next item.
//*****************************************************************
template <class T>
class Node
{
 public:
	string key;
	T value;
    Node<T> * next;
};

//*****************************************************************
// Linked lists store a variable number of items.
//*****************************************************************
template <class T>
class LinkedList
{
private:
    // Head is a reference to a list of data nodes.
    Node<T> * head;

    // Length is the number of data nodes.
    int length;

public:
    // Constructs the empty linked list object.
    // Creates the head node and sets length to zero.
    LinkedList();

    // Inserts an item at the end of the list.
    void insertItem( Node<T> * newItem );

    // Removes an item from the list by item key.
    // Returns true if the operation is successful.
    bool removeItem( string itemKey );

    // Searches for an item by its key.
    // Returns a reference to first match.
    // Returns a NULL pointer if no match is found.
    Node<T> * getItem( string itemKey );

    // Displays list contents to the console window.
    void printList();

    // Returns the length of the list.
    int getLength();

    // De-allocates list memory when the program terminates.
    ~LinkedList();
};

template <class T>
LinkedList<T>::LinkedList()
{
    head = new Node<T>;
    head -> next = NULL;
    length = 0;
}

// Inserts an item at the end of the list.
template <class T>
void LinkedList<T>::insertItem( Node<T> * newItem )
{
    if (!head -> next)
    {
        head -> next = newItem;
        length++;
        return;
    }
    Node<T> * p = head;
    Node<T> * q = head;
    while (q)
    {
        p = q;
        q = p -> next;
    }
    p -> next = newItem;
    newItem -> next = NULL;
    length++;
}

// Removes an item from the list by item key.
// Returns true if the operation is successful.
template <class T>
bool LinkedList<T>::removeItem( string itemKey )
{
    if (!head -> next) return false;
    Node<T> * p = head;
    Node<T> * q = head;
    while (q)
    {
        if (q -> key == itemKey)
        {
            p -> next = q -> next;
            delete q;
            length--;
            return true;
        }
        p = q;
        q = p -> next;
    }
    return false;
}

// Searches for an item by its key.
// Returns a reference to first match.
// Returns a NULL pointer if no match is found.
template <class T>
Node<T> * LinkedList<T>::getItem( string itemKey )
{
    Node<T> * p = head;
    Node<T> * q = head;
    while (q)
    {
        p = q;
        if ((p != head) && (p -> key == itemKey))
            return p;
        q = p -> next;
    }
    return NULL;
}

// Displays list contents to the console window.
template <class T>
void LinkedList<T>::printList()
{
    if (length == 0)
    {
        cout << "\n{ }\n";
        return;
    }
    Node<T> * p = head;
    Node<T> * q = head;
    cout << "\n{ ";
    while (q)
    {
        p = q;
        if (p != head)
        {
            cout << p -> key;
            cout << " " << p -> value;
            if (p -> next) cout << ", ";
            else cout << " ";
        }
        q = p -> next;
    }
    cout << "}\n";
}

// Returns the length of the list.
template <class T>
int LinkedList<T>::getLength()
{
    return length;
}

// De-allocates list memory when the program terminates.
template <class T>
LinkedList<T>::~LinkedList()
{
    Node<T> * p = head;
    Node<T> * q = head;
    while (q)
    {
        p = q;
        q = p -> next;
        if (q) delete p;
    }
}

#endif /* LINKEDLIST_H_ */
