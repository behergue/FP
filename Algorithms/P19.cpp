// Grupo DG211, Beatriz Herguedas Pinedo
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

const int MAX = 100;

struct tMatriz {
	int numFilas, numCols;
	int elementos[MAX][MAX];
};

struct tM{
	int max;
	int min;
};

typedef tM tFila[MAX];
typedef tM tCol[MAX];

void funcionFila(tMatriz matriz, tFila fila);
void funcionColumna(tMatriz matriz, tCol columna);
bool resolver(tMatriz matriz, tFila fila, tCol columna);
bool resuelveCaso();

void funcionFila(tMatriz matriz, tFila fila) {
	for (int i = 0; i < matriz.numFilas; i++) {
		fila[i].max = matriz.elementos[i][0];
		fila[i].min = matriz.elementos[i][0];
		for (int j = 0; j < matriz.numCols; j++) {
			if (matriz.elementos[i][j] > fila[i].max) 
				fila[i].max = matriz.elementos[i][j];

			else if (matriz.elementos[i][j] < fila[i].min)
				fila[i].min = matriz.elementos[i][j];
		}
	}	
}

void funcionColumna(tMatriz matriz, tCol columna) {
	for (int j = 0; j < matriz.numCols; j++) {
		columna[j].max = matriz.elementos[0][j];
		columna[j].min = matriz.elementos[0][j];
		for (int i = 0; i < matriz.numFilas; i++) {
			if (matriz.elementos[i][j] > columna[j].max) 
				columna[j].max = matriz.elementos[i][j];

			else if (matriz.elementos[i][j] < columna[j].min) 
				columna[j].min = matriz.elementos[i][j];
		}
	}
}

bool resolver(tMatriz matriz, tFila fila, tCol columna) {
	bool silla = false;
	funcionFila(matriz, fila);
	funcionColumna(matriz, columna);
	for (int i = 0; i < matriz.numFilas; i++)
		for (int j = 0; j < matriz.numCols; j++) {
			if (fila[i].max == columna[j].min || fila[i].min == columna[j].max) {
				silla = true;
			}
		}
	return silla;
}

bool resuelveCaso() {
	tMatriz matriz;
	tFila fila;
	tCol columna;

	std::cin >> matriz.numFilas;
	std::cin >> matriz.numCols;

	if (matriz.numFilas == 0 || matriz.numCols == 0)
		return false;

	for (int i = 0; i < matriz.numFilas; i++)
		for (int j = 0; j < matriz.numCols; j++)
			std::cin >> matriz.elementos[i][j];
	

	bool sol = resolver(matriz, fila, columna);

	if (sol)
		std::cout << "SI" << '\n';
	else
		std::cout << "NO" << '\n';

	return true;
}

int main() {
	
#ifndef DOMJUDGE
	std::ifstream in("silla.txt"); 
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	while (resuelveCaso());

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}