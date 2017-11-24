/*
 * serviziListaTemplate.h
 *
 *  Created on: 09 gen 2017
 *      Author: Simone
 */

#ifndef LISTSERVICES_H_
#define LISTSERVICES_H_
#include<iostream>
#include<iomanip>
#include<stdlib.h>

#include "List.hpp"
#include "Node.hpp"

using namespace std;

template<class tipoElem, class posizione>
void acquireList(List<tipoElem,posizione> &lista){
	posizione pos = lista.firstList();
	tipoElem dato;

	dato = 'a';
	lista.insList(dato,pos);

	dato = 'b';
	lista.insList(dato,pos);

	dato = 'c';
	lista.insList(dato,pos);

	dato = 'd';
	lista.insList(dato,pos);

	dato = 'e';
	lista.insList(dato,pos);

}

template<class tipoElem, class posizione>
void printList(List<tipoElem,posizione> &lista){
	posizione pos = lista.firstList();
		if(!lista.isEmpty()){
			cout<<"List: ";
			while(!lista.endList(pos)){
				cout<<lista.readList(pos)<<" ";
				pos = lista.succList(pos);
			}
		}else{
			cout<<"List is empty"<<endl;
		}
}

template<class tipoElem, class posizione>
int numeroElem(List<tipoElem,posizione> &lista){

	if(!lista.isEmpty()){
	int i = 1;
		posizione pos = lista.firstList();
		while(pos!=lista.lastList() && !lista.endList(pos)){
			pos=lista.succList(pos);
			i++;
		}
		return i;
	}else{
		cout<<"List is empty"<<endl;
		return 0;
	}

}

template<class tipoElem, class posizione>
void insListap(List<tipoElem,posizione> &lista, int i, tipoElem dato){

	posizione p = lista.firstList();
		int j =0;

		int lunghezza = numeroElem(lista);

		if(i==lunghezza){
			p = lista.ultimoLista();
			lista.insLista(dato,p);
		}else if(i==lunghezza+1){
			p = lista.succList(lista.ultimoLista());
			lista.insLista(dato,p);
		}else if (i==1){
			lista.insLista(dato,p);

		}else{
			while(j!=i){
				p = lista.succList(p);
				j++;
			}
			p = lista.precList(p);
			lista.insLista(dato,p);
		}


}

template<class tipoElem, class posizione>
void canc(List<tipoElem,posizione> &lista,int i){
	int j = 1;
	int lunghezza = numeroElem(lista);

	if(i==lunghezza){
		lista.cancLista(lista.ultimoLista());

	}else if(i==j){
		lista.cancLista(lista.firstList());
	}else{
		posizione pos = lista.firstList();
		while(j!=i){
			pos = lista.succList(pos);
			j++;
		}
		lista.cancLista(pos);

	}
}






template<class tipoElem, class posizione>
posizione find(List<tipoElem,posizione> &lista,tipoElem elem){
	posizione pos = new Node<tipoElem>();
	pos = NULL;
	boolean trovato = false;
	int i = 0;
	pos = lista.firstList();
	if (!lista.listaVuota()) {
		while (!lista.endList(pos) && !trovato) {
			i++;
			if (lista.leggiLista(pos) == elem)
				trovato = true;
			else
				pos = lista.succList(pos);
		}
	}
	cout << "Element "<<elem;
	if (trovato)
		cout << "is not present into the list " << endl;
	else
		cout << " is not present into the list" << endl;

	return pos;
}

template<class tipoElem, class posizione>
void emptyList(List<tipoElem,posizione> &lista){
	if(lista.isEmpty()){
		cout<<"Impossible to empty a list that is already empty"<<endl;
	}else{
		posizione pos = lista.firstList();
		while(!lista.isEmpty() && !lista.endList(pos)){
			posizione pos = lista.firstList();
			lista.cancList(pos);
		}
	}
}

#endif /* LISTSERVICES_H_ */
