// Grupo Doble Grado, Beatriz Herguedas Pinedo.
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

struct tPosicion {
	int posFila;
	int posCol;
};

int resolver(const tMatriz &cotas, tPosicion &pos);
bool resuelveCaso();

int resolver(const tMatriz &cotas, tPosicion &pos) {
	int max = cotas.elementos[0][0];
	for (int fila = 0; fila < cotas.numFilas; fila++)
		for (int col = 0; col < cotas.numCols; col++)
		{
			if (cotas.elementos[fila][col] > max)
			{
				max = cotas.elementos[fila][col];
				pos.posFila = fila;
				pos.posCol = col;
			}
		}

	return max;
}


bool resuelveCaso() {
	int sol;
	tMatriz cotas;
	tPosicion pos;
	pos.posFila = 0;
	pos.posCol = 0;
	
	std::cin >> cotas.numFilas;

	if (!std::cin)
		return false;

	std::cin >> cotas.numCols;

	for (int fila = 0; fila < cotas.numFilas; fila++)
		for (int col = 0; col < cotas.numCols; col++)
			std::cin >> cotas.elementos[fila][col];

	sol = resolver(cotas, pos);
	std::cout << sol << " " << pos.posFila << " " << pos.posCol << std::endl;


	return true;

}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("cota.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 


	while (resuelveCaso())
		;

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}