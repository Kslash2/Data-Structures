/*
 * hashTable.h
 *
 *  Created on: 15 feb 2017
 *      Author: Simone
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_


#include "LinkedList.hpp"

template <class T>
class HashTable{
private:

    // Array is a reference to an array of Linked Lists.
    LinkedList<T> * array;

    // Length is the size of the Hash Table array.
    int length;

    // Returns an array location for a given item key.
    int hash( string itemKey );

public:

    // Constructs the empty Hash Table object.
    // Array length is set to 13 by default.
    HashTable( int tableLength = 13 );

    // Adds an item to the Hash Table.
    void insertItem( Node<T> * newItem );

    // Deletes an Node<T> by key from the Hash Table.
    // Returns true if the operation is successful.
    bool removeItem( string itemKey );

    // Returns an item from the Hash Table by key.
    // If the item isn't found, a null pointer is returned.
    Node<T> * getItemByKey( string itemKey );

    // Display the contents of the Hash Table to console window.
    void printTable();

    // Prints a histogram illustrating the Node<T> distribution.
    void printHistogram();

    // Returns the number of locations in the Hash Table.
    int getLength();

    // Returns the number of Items in the Hash Table.
    int getNumberOfItems();

    // De-allocates all memory used for the Hash Table.
    ~HashTable();
};

template <class T>
HashTable<T>::HashTable( int tableLength )
{
    if (tableLength <= 0) tableLength = 13;
    array = new LinkedList<T>[ tableLength ];
    length = tableLength;
}

// Returns an array location for a given item key.
template <class T>
int HashTable<T>::hash( string itemKey )
{
    int value = 0;
    for (unsigned int i = 0; i < itemKey.length(); i++)
        value += itemKey[i];
    return (itemKey.length() * value) % length;
}

// Adds an item to the Hash Table.
template <class T>
void HashTable<T>::insertItem( Node<T> * newItem )
{
    int index = hash( newItem -> key );
    array[ index ].insertItem( newItem );
}

// Deletes an Node<T> by key from the Hash Table.
// Returns true if the operation is successful.
template <class T>
bool HashTable<T>::removeItem( string itemKey )
{
    int index = hash( itemKey );
    return array[ index ].removeItem( itemKey );
}

// Returns an item from the Hash Table by key.
// If the item isn't found, a null pointer is returned.
template <class T>
Node<T> * HashTable<T>::getItemByKey( string itemKey )
{
    int index = hash( itemKey );
    return array[index].getItem( itemKey );
}

// Display the contents of the Hash Table to console window.
template <class T>
void HashTable<T>::printTable()
{
    cout << "\nHash Table:\n";
    for (int i = 0; i < length; i++)
    {
        cout << "Bucket " << i+1 << ": ";
        array[i].printList();
    }
}

// Prints a histogram illustrating the Node<T> distribution.
template <class T>
void HashTable<T>::printHistogram()
{
    cout << "\n\nHash Table Contains ";
    cout << getNumberOfItems() << " Items total\n";
    for (int i = 0; i < length; i++)
    {
        cout << i + 1 << ":\t";
        for (int j = 0; j < array[i].getLength(); j++)
            cout << " X";
        cout << "\n";
    }
}

// Returns the number of locations in the Hash Table.
template <class T>
int HashTable<T>::getLength()
{
    return length;
}

// Returns the number of Items in the Hash Table.
template <class T>
int HashTable<T>::getNumberOfItems()
{
    int itemCount = 0;
    for (int i = 0; i < length; i++)
        itemCount += array[i].getLength();
    return itemCount;
}

// De-allocates all memory used for the Hash Table.
template <class T>
HashTable<T>::~HashTable()
{
    delete [] array;
}
#endif /* HASHTABLE_H_ */
