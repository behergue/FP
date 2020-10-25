#include <stdio.h>
#include <iostream>
using namespace std;


int main() 
{
	unsigned int numCasos, i;
	int n = 0, anchoCont, largoCont, altoCont, anchoCaja, largoCaja, altoCaja;
	int nAncho, nLargo, nAlto, total;
	numCasos = n;
	cin >> numCasos;

	for (i = 0; i < numCasos; ++i)
	{
		cin >> anchoCont >> largoCont >> altoCont >> anchoCaja >> largoCaja >> altoCaja;
		nAncho = (100 * anchoCont) / anchoCaja;
		nLargo = (100 * largoCont) / largoCaja;
		nAlto = (100 * altoCont) / altoCaja;
		total = nAncho * nLargo * nAlto;
		cout << total << endl;
	}
	return 0;

} 
