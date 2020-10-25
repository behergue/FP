// Grupo DG211, Beatriz Herguedas Pinedo
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

int resolver(int a, int b) {

	if (b == 0)
		return 0;

	else if (b == 1)
		return a;

	else if (b > 1 && b % 2 == 0)
		return (2 * a) * (b / 2);

	else if (b > 1 && b % 2 == 1)
		return (2 * a) * (b / 2) + a;
}

bool resuelveCaso() {
	int num1, num2;

	std::cin >> num1;

	if (!std::cin)
		return false;

	std::cin >> num2;

	int sol = resolver(num1, num2);

	std::cout << sol << '\n';

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("Egipcios.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif 
	while (resuelveCaso());

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}