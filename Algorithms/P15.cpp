#include <iostream>  
using namespace std;
#include <iomanip>
#include <stdio.h>

void casoDePrueba()
{
	int num, fila, suma = 0, total = 0, i = 0;
	cin >> num;
	for (int fila = 1; fila <= num, fila++)
	{
		cout << setw(5) << fila;
		for (int fila = 1; fila <= num, fila++)
		{
			cout << setw(5) << fila;
			for (int e = 2; e <= num; e++)
			{
				i = (e * fila);
				cout << setw(5) << i;
				suma = suma + i;
			}
			total = suma + fila;
			cout << setw(6) << total << endl;
			total = 0;
			suma = 0;
		}
	}
}
int main()
{
	unsigned int numCasos, i;
	cin >> numCasos;
	for (i = 0; i < numCasos; ++i)
	{
		casoDePrueba();
	}
	return 0;
}