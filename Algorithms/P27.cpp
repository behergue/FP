// Grupo DG211, Beatriz Herguedas Pinedo
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>

struct tObjeto {
	int numUds;
	std::string identificador;
};

struct tVector {
	int contador;
	int tam;
	tObjeto* lista;
};

bool buscar (std::string palabra, tVector &vector, int &pos) {
	bool encontrado = false;
	int i = 0;
	while (i < vector.contador && !encontrado) {
 		if (vector.lista[i].identificador == palabra) {
			encontrado = true;
			pos = i;
		}
		else i++;
	}
	return encontrado;
}

void mostrarLista(tVector &vector){
	for (int i = 0; i < vector.contador; i++) 
		std::cout << vector.lista[i].identificador << " " << vector.lista[i].numUds << '\n';
	std::cout << "---\n";
}

bool resuelveCaso(tVector &vector) {
	char codigo;
	int pos = 0;
	std::string palabra;
	int num;

	std::cin >> codigo;

	if (codigo == 'F')
		return false;

	else if (codigo == 'A') {
		std::cin >> palabra;
		std::cin >> num;
		if (buscar(palabra, vector, pos))
			vector.lista[pos].numUds = vector.lista[pos].numUds + num;
		else {
			if (vector.contador == vector.tam) {
				vector.tam = 2 * vector.tam;
				tObjeto *aux = new tObjeto[vector.tam];
				for (int i = 0; i < vector.contador; i++)
					aux[i] = vector.lista[i];
				delete[] vector.lista;
				vector.lista = aux;
			}
			vector.lista[vector.contador].identificador = palabra;
			vector.lista[vector.contador].numUds = num;
			vector.contador++;
		}
	}
	
	else if (codigo == 'R') {
		std::cin >> palabra;
		std::cin >> num;
		if (buscar(palabra, vector, pos))
			if (vector.lista[pos].numUds - num >= 0)
				vector.lista[pos].numUds = vector.lista[pos].numUds - num;
			else
				vector.lista[pos].numUds = 0;
	}
	else if (codigo == 'L') {
		mostrarLista(vector);
	}

	return true;
}

int main() {
	tVector vector;
	vector.contador = 0;
	vector.tam = 3;
	vector.lista = new tObjeto[vector.tam];
#ifndef DOMJUDGE
	std::ifstream in("VectDinamicos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif 
	while (resuelveCaso(vector));

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	delete[] vector.lista;
	return 0;
}