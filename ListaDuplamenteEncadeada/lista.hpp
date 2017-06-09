#ifndef LISTA_HPP
#define LISTA_HPP

#include <iostream>
#include "node.hpp"

template <typename T>
Lista<T>::Lista(){
	fsize = 0;
	head = NULL;
	tail = NULL;
}

template <typename T>
void Lista<T>::InserirInicio(T h){
	if(fsize!=0){
		Node<T> *tmp = new Node<T>();
		tmp->setData(h);
		tmp->setNext(head);
		head->setBack(tmp);
		head = tmp;
		fsize++;
	}else{
		Node<T> *tmp = new Node<T>();
		tmp->setData(h);
		head = tmp;
		tail = tmp;
		tail->setNext(NULL);
		tail->setBack(NULL);
		fsize=1;
	}
}


template <typename T>
void Lista<T>::InserirPosicao(T h, int pos){
	if(pos==0){
		InserirInicio(h);
		return;
	}
	if(pos>fsize){
		std::cout << "Posição inválida" << std::endl;
		return;
	}
	Node<T> *tmp = new Node<T>();
	Node<T> *cont = head;	
	for(int i=1; i<=fsize; i++){
		if(i==pos){
			tmp->setData(h);
			tmp->setNext(cont->getNext());
			Node<T> *next = cont->getNext();
			next->setBack(tmp);
			cont->setNext(tmp);
			tmp->setBack(cont);
			fsize++;
			break;
		}else{
			cont = cont->getNext();
		}
	}
}

template <typename T>
void Lista<T>::InserirFinal(T h){
	if(fsize!=0){
		Node<T> *tmp = new Node<T>();
		tmp->setData(h);
		tail->setNext(tmp);
		tmp->setBack(tail);
		tail = tmp;
		tail->setNext(NULL);
		tail->setBack(tmp->getBack());
		fsize++;
	}
}

template <typename T>
void Lista<T>::RemoverInicio(){
	if(fsize==0){
		std::cout << "Lista vazia" << std::endl;
		return;
	}
	else if(fsize==1){
		delete head;
		head=NULL;
		tail=NULL;
		return;
	}else{
		Node<T> *tmp;
		tmp = head;
		head = head->getNext();
		head->setBack(NULL);
		delete tmp;
		fsize--;
	}
}

template <typename T>
void Lista<T>::RemoverPosicao(int pos){
	if(fsize==0){
		std::cout << "Lista vazia" << std::endl;
		return;
	}
	if(pos>fsize){
		std::cout << "Operação inválida" << std::endl;
		return;
	}
	if(pos == 0){
		RemoverInicio();
		return;
	}
	Node<T> *cont = head;
	for(int i=1; i<=fsize; i++){
		if(i==pos){
			Node<T> *tmp = cont->getNext();
			tmp->setBack(cont);
			cont->setNext(tmp->getNext());
			cont->setBack(tmp->getBack());
			delete tmp;
			fsize--;
			break;
		}else{
			cont = cont->getNext();
		}
	}
}


template <typename T>
void Lista<T>::RemoverFinal(){
	if(fsize==0){
		std::cout << "Lista vazia" << std::endl;
		return;
	}
	if(fsize==1){
		delete head;
		head=NULL;
		tail=NULL;
		return;
	}
	Node<T> *cont = head;
	while(cont->getNext()!=tail) {
		cont = cont->getNext();	
	}
	tail = cont;
	delete cont->getNext();
	tail->setNext(NULL);
	fsize--;
}

template <typename T>
void Lista<T>::NumeroElementos(){
	std::cout << "Tamanho da lista: " << fsize << std::endl;
}

template <typename T>
void Lista<T>::BuscarElemento(T x){
	Node<T> *cont;
	int pos = 0;
	for(cont = head; cont!=NULL; cont = cont->getNext()) {
		if(x==cont->getData()){
			std::cout << "Elemento encontrado na posicao " << pos << std::endl;
			return;
		}
		pos++;
	}
	std::cout << "Elemento nao esta na lista" << std::endl;
}


template <typename T>
void Lista<T>::DeletarLista(){
	Node<T> *cont = head; 
	while(cont!=NULL){
		Node<T> *tmp = cont;
		cont = tmp->getNext();
		delete tmp;
	}
	fsize=0;
	head = NULL;
	tail = NULL;
}

template <typename T>
void Lista<T>::ImprimirLista(){
	Node<T> *cont = head;
	while(cont!=NULL){
		std::cout << cont->getData() << std::endl;
		cont = cont->getNext();
	}
}

#endif
