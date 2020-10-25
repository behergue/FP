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
	int numFilas, numCols, fila, col;
	int elementos[MAX][MAX];
};

struct tDimensiones {
	int ladoCuadrado, alturaTriangulo;
};

bool esTriangulo(const tMatriz &matriz,const int fila, const int col, const tDimensiones dim){
	bool ok = true;
	int aux = matriz.elementos[fila][col];

	int f = 0;
	while (ok && f < dim.alturaTriangulo) {
		int c = 0;
		while (ok && c <= f) {
			if (matriz.elementos[fila + f][col + c] != aux)
				ok = false;
			else
				c++;
		}
		f++;
	}                          
	return ok;
}

bool esCuadrado(const tMatriz &matriz, const int fila, const int col, const tDimensiones dim) {
	int aux = matriz.elementos[fila][col];
	bool ok = true;
	int f = 0;
	while (ok && f < dim.ladoCuadrado) {
		int c = 0;
		while (ok && c < dim.ladoCuadrado) {
			if (matriz.elementos[fila + f][col + c] != aux)
				ok = false;
			else
				c++;
		}
		f++;
	}
	return ok;
}


int resolverCuadrados(tMatriz const& matriz, tDimensiones const& dim) {
	int contador = 0;
	for (int fila = 0; fila <= matriz.numFilas - dim.ladoCuadrado; fila++)
		for (int col = 0; col <= matriz.numCols - dim.ladoCuadrado; col++)
			if (esCuadrado(matriz, fila, col, dim))
				contador++;

	return contador;
}

int resolverTriangulos(tMatriz const& matriz, tDimensiones const& dim) {
	int contador = 0;
	for (int fila = 0; fila <= matriz.numFilas - dim.alturaTriangulo; fila++)
		for (int col = 0; col <= matriz.numCols - dim.alturaTriangulo; col++)
			if (esTriangulo(matriz, fila, col, dim))
				contador++;
	
	return contador;
}


bool resuelveCaso() {
	tMatriz matriz;
	tDimensiones dim;

	std::cin >> matriz.numFilas >> matriz.numCols >> dim.ladoCuadrado >> dim.alturaTriangulo;

	if (!std::cin)
		return false;

	for (int fila = 0; fila < matriz.numFilas; fila++)
		for (int col = 0; col < matriz.numCols; col++)
			std::cin >> matriz.elementos[fila][col];

	int solCuadrados = resolverCuadrados(matriz, dim);
	int solTriangulos = resolverTriangulos(matriz, dim);

	std::cout << solCuadrados << " " << solTriangulos << '\n';

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("cuadrados.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 
	while (resuelveCaso());

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}