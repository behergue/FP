// Grupo DG211, Beatriz Herguedas Pinedo
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

const int MAX = 100;
const int incF[] = {1, 0, -1, 0}; 
const int incC[] = {0, 1, 0, -1};

struct tMatriz {
	int contador;
	int elementos[MAX][MAX];
};


int resolver(tMatriz matriz, int &posF) {
	tMatriz aux;
	int max;
	
	if (matriz.contador == 1)
		max = matriz.elementos[0][0];

	else {
		aux.contador = matriz.contador;
		for (int i = 0; i < matriz.contador; i++)
			for (int j = 0; j < matriz.contador; j++)
				aux.elementos[i][j] = matriz.elementos[i][j];

		for (int k = 0; k < 2; k++)
			aux.elementos[0][0] = aux.elementos[0][0] + matriz.elementos[incF[k]][incC[k]];

		for (int i = 1; i < aux.contador - 1; i++)
			for (int k = 0; k < 4; k++)
				aux.elementos[i][i] = aux.elementos[i][i] + matriz.elementos[i + incF[k]][i + incC[k]];

		int temp = aux.contador - 1;
		for (int k = 2; k < 4; k++)
			aux.elementos[temp][temp] = aux.elementos[temp][temp] + matriz.elementos[temp + incF[k]][temp + incC[k]];

		max = aux.elementos[0][0];
		for (int i = 0; i < aux.contador; i++)
			if (aux.elementos[i][i] > max) {
				max = aux.elementos[i][i];
				posF = i;
			}
	}
	return max;
}

bool resuelveCaso() {
	tMatriz matriz;
	int posF = 0;
	std::cin >> matriz.contador;

	if (!std::cin)
		return false;

	for (int i = 0; i < matriz.contador; i++)
		for (int j = 0; j < matriz.contador; j++) 
			matriz.elementos[i][j] = 0;

	for (int i = 0; i < matriz.contador; i++)
			std::cin >> matriz.elementos[i][i];
	
	if (matriz.contador > 1) {
		for (int i = 0; i < matriz.contador - 1; i++)
			std::cin >> matriz.elementos[i + 1][i];

		for (int i = 0; i < matriz.contador - 1; i++)
			std::cin >> matriz.elementos[i][i + 1];
	}

	int sol = resolver(matriz, posF);
	
	std::cout << posF << " " << sol << '\n';

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("tridiagonal.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif 
	while (resuelveCaso());

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}