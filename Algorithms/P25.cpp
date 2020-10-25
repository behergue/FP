/*#ifdef _DEBUG
#define DBG_NEW new (_NORMAL_BLOCK, __FILE__, __LINE__) 
#define new DBG_NEW*/

// Grupo DG211, Beatriz Herguedas Pinedo
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>

const int MAX = 50;
const int MAX_NUMF = 200;

struct tMatriz {
	int contador;
	int elementos[MAX][MAX];
};

struct tFoto {
	std::string titulo;
	std::string tema;
	tMatriz matriz;
};

typedef tFoto *tFotoPtr[MAX_NUMF];

void ordenarTitulo(tFotoPtr punt, int numFotos) {
	for (int i = 1; i < numFotos; i++) {
		tFoto elemento = *punt[i];
		int j = i;
		while (j > 0 && elemento.titulo < punt[j - 1]->titulo) {
			*punt[j] = *punt[j - 1];
			j--;
		}
		if (j != i)
			*punt[j] = elemento;
	}
}

void ordenarTema(tFotoPtr punt, int numFotos) {
	for (int i = 1; i < numFotos; i++) {
		tFoto elemento = *punt[i];
		int j = i;
		while (j > 0 && elemento.tema < punt[j - 1]->tema) {
			*punt[j] = *punt[j - 1];
			j--;
		}
		if (j != i)
			*punt[j] = elemento;
	}
}


bool resuelveCaso() {
	tFotoPtr punt1, punt2;
	int numFotos;
	
	std::cin >> numFotos;
	std::cin.get();

	if (numFotos == 0)
		return false;

	for (int i = 0; i < numFotos; i++) {
		punt1[i] = new tFoto;
		std::getline(std::cin, punt1[i]->titulo);
	}

	for (int i = 0; i < numFotos; i++) {
		std::getline(std::cin, punt1[i]->tema);
		for (int f = 0; f < MAX; f++)
			for (int c = 0; c < MAX; c++)
				punt1[i]->matriz.elementos[f][c] = 3;
	}
	
	ordenarTitulo(punt1, numFotos);

	for (int i = 0; i < numFotos; i++)
		std::cout << punt1[i]->titulo << '\n';
	std::cout << '\n';

	for (int i = 0; i < numFotos; i++)
		punt2[i] = punt1[i];
	
	ordenarTema(punt2, numFotos);

	for (int i = 0; i < numFotos; i++)
		std::cout << punt2[i]->tema << " - " << punt2[i]->titulo << '\n';

	for (int i = 0; i < numFotos; i++) {
		delete punt2[i];
		punt1[i] = nullptr;
		punt2[i] = nullptr;
	}

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("fotos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif 
	while (resuelveCaso());

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	//_CrtDumpMemoryLeaks();
	return 0;
}
//#endif