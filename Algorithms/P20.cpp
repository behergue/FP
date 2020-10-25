// Grupo DG211, Beatriz Herguedas Pinedo
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>


const int MAX = 20;

struct tMatriz {
	int numFilas, numCols;
	int elementos[MAX][MAX];
};

typedef int tArray[MAX];

std::istream& operator >> (std::istream & in, tMatriz & matriz);
std::ostream& operator<< (std::ostream & out, tMatriz const& matriz);
tMatriz filas(tMatriz matriz, int a, int b);
tMatriz columnas(tMatriz matriz, int a, int b);
tMatriz cruz(tMatriz matriz, int f, int c, int d);
tMatriz rotarFila(tMatriz matriz, int f);
tMatriz rotarCol(tMatriz matriz, int c);
bool resuelveCaso();

std::istream& operator >> (std::istream & in, tMatriz & matriz) {
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

tMatriz filas(tMatriz matriz, int a, int b) {
	tArray aux;
	for (int j = 0; j < matriz.numCols; j++) {
		aux[j] = matriz.elementos[a][j];
		matriz.elementos[a][j] = matriz.elementos[b][j];
		matriz.elementos[b][j] = aux[j];
	}
	return matriz;
}

tMatriz columnas(tMatriz matriz, int a, int b) {
	tArray aux;
	for (int i = 0; i < matriz.numFilas; i++) {
		aux[i] = matriz.elementos[i][a];
		matriz.elementos[i][a] = matriz.elementos[i][b];
		matriz.elementos[i][b] = aux[i];
	}
	return matriz;
}

tMatriz cruz(tMatriz matriz, int f, int c, int d) {
	int aux;
	if (matriz.numFilas < matriz.numCols)
		aux = matriz.numFilas;
	else
		aux = matriz.numCols;
	for (int i = 0; i < aux; i++) {
		if (f + i < matriz.numFilas && c + i < matriz.numCols)
			matriz.elementos[f + i][c + i] = d;
		if (f - i >= 0 && c - i >= 0)
			matriz.elementos[f - i][c - i] = d;
		if (f + i < matriz.numFilas && c - i >= 0)
			matriz.elementos[f + i][c - i] = d;
		if (f - i >= 0 && c + i < matriz.numCols)
			matriz.elementos[f - i][c + i] = d;
	}

	return matriz;
}

tMatriz rotarFila(tMatriz matriz, int f) {
	int aux;
	if (f < 0) {
		f = -f;
		f--;
		aux = matriz.elementos[f][0];
		for (int j = 0; j < matriz.numCols - 1; j++)
			matriz.elementos[f][j] = matriz.elementos[f][j + 1];
		matriz.elementos[f][matriz.numCols - 1] = aux;
	}
	else if (f >= 0) {
		f--;
		aux = matriz.elementos[f][matriz.numCols - 1];
		for (int j = matriz.numCols - 1; j > 0; j--)
			matriz.elementos[f][j] = matriz.elementos[f][j - 1];
		matriz.elementos[f][0] = aux;
	}
	return matriz;
}

tMatriz rotarCol(tMatriz matriz, int c) {
	int aux;
	if (c < 0) {
		c = -c;
		c--;
		aux = matriz.elementos[0][c];
		for (int i = 0; i < matriz.numFilas - 1; i++)
			matriz.elementos[i][c] = matriz.elementos[i + 1][c];
		matriz.elementos[matriz.numFilas - 1][c] = aux;
	}
	else if (c > 0) {
		c--;
		aux = matriz.elementos[matriz.numFilas - 1][c];
		for (int i = matriz.numFilas - 1; i > 0; i--)
			matriz.elementos[i][c] = matriz.elementos[i - 1][c];
		matriz.elementos[0][c] = aux;
	}
	return matriz;
}


bool resuelveCaso() {
	tMatriz matriz;
	int T, a, b, f, c, d;
	std::string opcion;
	std::cin >> matriz.numFilas;
	std::cin >> matriz.numCols;

	if (matriz.numFilas == 0 || matriz.numCols == 0)
		return false;

	std::cin >> matriz;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		std::cin >> opcion;
		if (opcion == "filas") {
			std::cin >> a >> b;
			a--;
			b--;
			matriz = filas(matriz, a, b);
		}
		else if (opcion == "columnas") {
			std::cin >> a >> b;
			a--;
			b--;
			matriz = columnas(matriz, a, b);
		}
		else if (opcion == "cruz") {
			std::cin >> f >> c >> d;
			f--;
			c--;
			matriz = cruz(matriz, f, c, d);
		}

		else if (opcion == "rotarFila") {
			std::cin >> f;
			matriz = rotarFila(matriz, f);
		}

		else if (opcion == "rotarCol") {
			std::cin >> c;
			matriz = rotarCol(matriz, c);
		}
	}

	std::cout << matriz << "---" << '\n';

	return true;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("diversion.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	while (resuelveCaso());

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}