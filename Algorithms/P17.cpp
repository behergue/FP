// Grupo DG211, Beatriz Herguedas Pinedo
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

const int MAX = 500;

struct tMatriz {
	int numFilas, numCols;
	int elementos[MAX][MAX];
};

tMatriz operator* (tMatriz const& matriz1, tMatriz const& matriz2);
std::istream& operator>> (std::istream & in, tMatriz & matriz);
std::ostream& operator<< (std::ostream & out, tMatriz const& matriz);
tMatriz resolver(tMatriz const& matriz1, tMatriz const& matriz2);
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


tMatriz operator* (tMatriz const& matriz1, tMatriz const& matriz2) {
	tMatriz aux;
	int prod = 0;
	aux.numFilas = matriz1.numFilas;
	aux.numCols = matriz2.numCols;
	for (int i = 0; i < matriz1.numFilas; i++)
		for (int j = 0; j < matriz2.numCols; j++) {
			for (int k = 0; k < matriz1.numCols; k++)
				prod = prod + (matriz1.elementos[i][k] * matriz2.elementos[k][j]);
			aux.elementos[i][j] = prod;
			prod = 0;
		}
	return aux;
}

tMatriz resolver(tMatriz const& matriz1, tMatriz const& matriz2) {
	return matriz1 * matriz2;
}


bool resuelveCaso() {
	tMatriz sol, matriz1, matriz2;

	std::cin >> matriz1.numFilas;

	if (!std::cin)
		return false;

	std::cin >> matriz1.numCols;
	std::cin >> matriz1;
	std::cin >> matriz2.numFilas;
	std::cin >> matriz2.numCols;
	std::cin >> matriz2;

	sol = resolver(matriz1, matriz2);
	
	std::cout << sol;
	std::cout << '\n';

	return true;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("juguetes.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif 

	while (resuelveCaso());


#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
} 