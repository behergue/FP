// Grupo DG211, Beatriz Herguedas Pinedo
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

const int MAX = 9;

struct tMatriz {
	int numFilas, numCols;
	int elementos[MAX][MAX];
};

typedef int tArray[MAX];

bool fila(tMatriz matriz);
bool columna(tMatriz matriz);
bool casilla(tMatriz matriz);
bool resolver(tMatriz matriz);
void resuelveCaso();

bool fila(tMatriz matriz) {
	tArray vector;
	bool bien = true;
		for (int fila = 0; fila < MAX; fila++)
			for (int col = 0; col < MAX; col++) {
				vector[col] = matriz.elementos[fila][col];
				int i = 0;
				while (bien && i < col) {
					if (vector[col] < 1 || vector[col] > 9 || vector[col] == vector[i])
						bien = false;
					i++;
				}
			}
	return bien;
}

bool columna(tMatriz matriz) {
	tArray vector;
	bool bien = true;
	for (int col = 0; col < MAX; col++)
		for (int fila = 0; fila < MAX; fila++) {
				vector[fila] = matriz.elementos[fila][col];
				int j = 0;
				while (bien && j < fila) {
					if (vector[fila] < 1 || vector[fila] > 9 || vector[fila] == vector[j])
						bien = false;
					j++;
					}
		}
	return bien;
}

bool casilla(tMatriz matriz) {
	tArray vector;
	bool bien = true;
	for (int fila = 0; fila < MAX; fila = fila + 3)
		for (int col = 0; col < MAX; col = col + 3)
			for (int i = fila; i < fila + 3; i++)
				for (int j = col; j < col + 3; j++) {
					int f = 3 * (i - fila) + (j - col);
						vector[f] = matriz.elementos[i][j];
						int k = 0;
						while (bien && k < f) {
							if (vector[f] < 1 || vector[f] > 9 || vector[f] == vector[k])
								bien = false;
							k++;
						}
					}
	return bien;
}

bool resolver(tMatriz matriz) {
	bool exito = false;
	bool fil = fila(matriz);
	bool col = columna(matriz);
	bool cas = casilla(matriz);
	if (fil && col && cas)
		exito = true;
	return exito;
}

void resuelveCaso() {
	tMatriz matriz;
	for (int fila = 0; fila < MAX; fila++)
		for (int col = 0; col < MAX; col++)
			std::cin >> matriz.elementos[fila][col];

	bool sol = resolver(matriz);

	if (sol)
		std::cout << "SI" << '\n';
	else
		std::cout << "NO" << '\n';
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("sudoku.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}