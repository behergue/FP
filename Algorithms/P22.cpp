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
	int numFilas, numCols, fila, col;
	int elementos[MAX][MAX];
};


bool resolver(const tMatriz &matriz, tMatriz &patron) {
	bool encontrado = false, mal = false;
	patron.fila = 0;
	patron.col = 0;
	int fila = 0;
	while (!encontrado && fila < matriz.numFilas) {
		int col = 0;
		while (!encontrado && col < matriz.numCols) {
			if (matriz.elementos[fila][col] == patron.elementos[0][0] && matriz.numFilas - fila + 1 > patron.numFilas 
				&& matriz.numCols - col + 1 > patron.numCols) {
				int  f = 0;
				mal = false;
				while (!mal && f < patron.numFilas) {
					int c = 0;
					while (!mal && c < patron.numCols) {
						if (matriz.elementos[fila + f][col + c] != patron.elementos[f][c]) {
							mal = true;
							encontrado = false;
						}
						else {
							encontrado = true;
							patron.fila = fila;
							patron.col = col;
						}
						c++;
					}
					f++;
				}
			}
			col++;
		}
		fila++;
	}
	return encontrado;
}


bool resuelveCaso() {
	tMatriz matriz, patron;

	std::cin >> matriz.numFilas >> matriz.numCols;

	if (!std::cin)
		return false;

	for (int fila = 0; fila < matriz.numFilas; fila++)
		for (int col = 0; col < matriz.numCols; col++)
			std::cin >> matriz.elementos[fila][col];

	std::cin >> patron.numFilas >> patron.numCols;

	for (int f = 0; f < patron.numFilas; f++)
		for (int c = 0; c < patron.numCols; c++)
			std::cin >> patron.elementos[f][c];

	bool sol = resolver(matriz, patron);

	if (sol)
		std::cout << patron.fila << ' ' << patron.col << '\n';
	else
		std::cout << "NO\n";

	return true;

}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("Busqueda.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());

#endif 
	while (resuelveCaso());

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");

#endif

	return 0;
}