#ifndef NODE_HPP
#define NODE_HPP
#include "lista.hpp"

template <typename T>

class Node{

private:
	T data;
	Node *next;
	Node *back;
public:
	Node(void){}
	T getData(){
		return data;
	}
	void setData(T d){
		data = d;
	}
	Node *getNext(){
		return next;
	}
	void setNext(Node *p){
		next = p;
	}
	Node *getBack(){
		return back;
	}
	void setBack(Node *b){
		back = b;
	}

};

template <typename T>
class Lista{

private:
	Node<T> *head;
	Node<T> *tail;
	int fsize;
public:
	Lista(void);
	//Lista(object);
	void InserirInicio(T h);
	void InserirPosicao(T h, int pos);
	void InserirFinal(T h);
	void RemoverInicio();
	void RemoverPosicao(int pos);
	void RemoverFinal();
	void NumeroElementos();
	void BuscarElemento(T x);
	void DeletarLista();
	void ImprimirLista();
};

#endif
