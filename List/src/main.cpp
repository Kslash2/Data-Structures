//============================================================================
// Name        : TemplateList.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "List.hpp"
#include "listServices.hpp"
#include "Node.hpp"
using namespace std;

typedef Node<char>* posizione;

int main() {

List<char,posizione> list;


    //ACQUISIZIONE E STAMPA LISTA
	acquireList(list);
	printList(list);
	cout<<endl;

	//NUMERO ELEMENTI
	cout<<"Number of element: "<<numeroElem(list)<<endl;

	emptyList(list);
	printList(list);











	return 0;
}
