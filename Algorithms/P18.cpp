// Grupo DG211, Beatriz Herguedas Pinedo
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

const int MAX = 50;

struct tMatriz {
	int numFilas, numCols;
	int elementos[MAX][MAX];
};


std::istream& operator>> (std::istream & in, tMatriz & matriz);
std::ostream& operator<< (std::ostream & out, tMatriz const& matriz);
tMatriz girarMatriz90(tMatriz const& matriz);
tMatriz girarMatriz180(tMatriz const& matriz);
tMatriz girarMatriz270(tMatriz const& matriz);
tMatriz resolver(tMatriz matriz, int giro);
bool resuelveCaso();

std::istream& operator>> (std::istream & in, tMatriz & matriz) {
	for (int i = 0; i < matriz.numFilas; i++)
		for (int j = 0; j < matriz.numCols; j++)
			in >> matriz.elementos[i][j];
	return in;
}

std::ostream& operator<< (std::ostream & out, tMatriz const& matriz) {
	for (int i = 0; i < matriz.numFilas; i++) {
		for (int j = 0; j < matriz.numCols; j++)
			out << matriz.elementos[i][j] << " ";
		out << '\n';
	}
	return out;
}

tMatriz girarMatriz90(tMatriz const& matriz) {
	tMatriz aux;
	aux.numFilas = matriz.numFilas;
	aux.numCols = matriz.numCols;
	for (int i = 0; i < matriz.numFilas; i++)
		for (int j = 0; j < matriz.numCols; j++) {
			aux.elementos[j][matriz.numFilas - 1 - i] = matriz.elementos[i][j];
		}
	return aux;
}

tMatriz girarMatriz180(tMatriz const& matriz) {
	tMatriz aux;
	aux.numFilas = matriz.numFilas;
	aux.numCols = matriz.numCols;
	for (int i = 0; i < matriz.numFilas; i++)
		for (int j = 0; j < matriz.numCols; j++) {
			aux.elementos[matriz.numFilas - 1 - i][matriz.numCols - 1 - j] = matriz.elementos[i][j];
		}
	return aux;
}

tMatriz girarMatriz270(tMatriz const& matriz) {
	tMatriz aux;
	aux.numFilas = matriz.numFilas;
	aux.numCols = matriz.numCols;
	for (int i = 0; i < matriz.numFilas; i++)
		for (int j = 0; j < matriz.numCols; j++) {
			aux.elementos[matriz.numCols - 1 - j][i] = matriz.elementos[i][j];
		}
	return aux;
}

tMatriz resolver(tMatriz matriz, int giro) {
	tMatriz nueva;
	switch (giro) {
	case 90: {
		nueva = girarMatriz90(matriz);
	}break;
	case 180: {
		nueva = girarMatriz180(matriz);
	}break;
	case 270: {
		nueva = girarMatriz270(matriz);
	}break;
	}
	return nueva;
}


bool resuelveCaso() {
	tMatriz matriz, sol;
	std::cin >> matriz.numFilas;
	int numGiros, giro;

	if (!std::cin)
		return false;

	std::cin >> matriz.numCols;
	std::cin >> matriz;
	std::cin >> numGiros;
	for (int i = 0; i < numGiros; i++) {
		std::cin >> giro;
		sol = resolver(matriz, giro);
		matriz = sol;
	}

	std::cout << sol << '\n';

	return true;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("giros.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif 

	while (resuelveCaso());

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}