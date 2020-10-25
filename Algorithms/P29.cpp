// Grupo DG211, Beatriz Herguedas Pinedo
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

const int MAX = 100;
typedef int tVector[MAX];

void invertir(tVector &vector, int &ini, int &fin) {
	int aux;
	if (ini <= fin) {
		aux = vector[ini];
		vector[ini] = vector[fin];
		vector[fin] = aux;
		ini++;
		fin--;
		invertir(vector, ini, fin);
	}
}

bool resuelveCaso() {
	tVector vector;
	int num, ini, fin;

	std::cin >> num;

	if (!std::cin)
		return false;
	
	for (int i = 0; i < num; i++)
		std::cin >> vector[i];

	ini = 0;
	fin = num - 1;
	invertir(vector, ini, fin); 

	for (int i = 0; i < num; i++)
		std::cout << vector[i] << " ";
	std::cout << '\n';

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("Invertir.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif 
	while (resuelveCaso());

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");

#endif
	return 0;
}