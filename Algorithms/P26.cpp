// Grupo DG211, Beatriz Herguedas Pinedo
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

const int MAX_F = 6;
const int MAX_C = 7;
const int COND = 4;

typedef int tMatriz[MAX_F][MAX_C];
typedef int tContador[MAX_C];

int contadorFila(tMatriz matriz, int fila, int col) {
	int contador = 0;
	bool fallo = false;

	int i = 0;
	while (!fallo && i < COND && col + i < MAX_C) {
		if (matriz[fila][col + i] == matriz[fila][col])
			contador++;
		else
			fallo = true;
		i++;
	}
	
	fallo = false;
	int j = 1;
	while (!fallo && j < COND && col - j > -1) {
		if (matriz[fila][col - j] == matriz[fila][col])
			contador++;
		else
			fallo = true;
		j++;
	}

	return contador;
}

int contadorCol(tMatriz matriz, int fila, int col) {
	int contador = 0;
	bool fallo = false;
	int i = 0;
	while (!fallo && i < COND && fila + i < MAX_F) {
		if (matriz[fila + i][col] == matriz[fila][col])
			contador++;
		else
			fallo = true;
		i++;
	}

	return contador;
}

int contadorDiag1(tMatriz matriz, int fila, int col) {
	int contador = 0;
	bool fallo = false;

	int i = 0;
	while (!fallo && i < COND && fila + i < MAX_F && col + i < MAX_C) {
		if (matriz[fila + i][col + i] == matriz[fila][col])
			contador++;
		else
			fallo = true;
		i++;
	}
		
	fallo = false;
	int j = 1;
	while (!fallo && j < COND && fila - j > -1 && col - j > -1) {
		if (matriz[fila - j][col - j] == matriz[fila][col])
			contador++;
		else
			fallo = true;
		j++;
	}
	
	return contador;
}

int contadorDiag2(tMatriz matriz, int fila, int col) {
	int contador = 0;
	bool fallo = false;

	int i = 0;
	while (!fallo && i < COND && fila + i < MAX_F && col - i > -1) {
		if (matriz[fila + i][col - i] == matriz[fila][col])
			contador++;
		else
			fallo = true;
		i++;
	}

	fallo = false;
	int j = 1;
	while (!fallo && j < COND && fila - j > -1 && col + j < MAX_C) {
		if (matriz[fila - j][col + j] == matriz[fila][col])
			contador++;
		else
			fallo = true;
		j++;
	}
	
	return contador;
}
 
int resolver(tMatriz matriz, int fila, int col) {
	int winner = 0;
	int f = contadorFila(matriz, fila, col);
	int c = contadorCol(matriz, fila, col);
	int d1 = contadorDiag1(matriz, fila, col);
	int d2 = contadorDiag2(matriz, fila, col);

	if (f >= COND || c >= COND || d1 >= COND || d2 >= COND)
		winner = matriz[fila][col];

	return winner;
}

bool resuelveCaso() {
	tMatriz matriz;
	tContador contador;
	int numMov, col, ganador = 0;

	for (int f = 0; f < MAX_F; f++)
		for (int c = 0; c < MAX_C; c++)
			matriz[f][c] = 0;

	for (int j = 0; j < MAX_C; j++)
		contador[j] = 6;

	std::cin >> numMov;

	if (numMov == 0)
		return false;

	for (int i = 0; i < numMov; i++) {
		std::cin >> col;
		if (i % 2 == 0)
			matriz[contador[col] - 1][col] = 1;
		else
			matriz[contador[col] - 1][col] = 2;
		if (ganador == 0)
			ganador = resolver(matriz, contador[col] - 1, col);
		contador[col]--;
	}

	if (ganador == 1)
		std::cout << "Gana A\n";
	else if (ganador == 2)
		std::cout << "Gana B\n";
	else
		std::cout << "Empate\n";

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("Prueba.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 
	while (resuelveCaso());

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}