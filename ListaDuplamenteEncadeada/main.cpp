#include <iostream>
using namespace std;

#include "lista.hpp"

void printSeparator(){
	cout << "---" << endl;
}

void printOptions(){
	cout << "1-inserir elemento no inicio\n2-insirir elemento no final\n3-remover elemento inicio\n4-Numero de elementos\n5-imprimir lista\n0-sair" << endl;
}

void showMenu(Lista<int>* l) {
	int option, n;
	
	do{
		printOptions();
		cin >> option;
		printSeparator();
		switch(option) {
			case 1:
				cin >> n;
				l->InserirInicio(n);
				break;
			case 2:
				cin >> n;
				l->InserirFinal(n);
				break;
			case 3:
				l->RemoverInicio();
				break;
			case 4:
				l->NumeroElementos();
				break;
			case 5:
				l->ImprimirLista();
				break;
			default:
				option = 0;
				break;
		}
		printSeparator();
	} while (option != 0);
}

int main(){
	/*
	int n;
	std::cout << "Informe um elemento para inserir na lista: " << std::endl;
	std::cin >> n;
	l->InserirInicio(n);
	l->InserirFinal(n + n);
	l->RemoverInicio();
	//l->InserirPosicao(4, 2);
	
	l->NumeroElementos();
	l->ImprimirLista();
	*/
	Lista<int> l;
	showMenu(&l);
	/*cout << "ESSA AQUI FOI A LISTA FINAL: " << endl;
	l.ImprimirLista();*/
	
	return 0;
}

