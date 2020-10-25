#include <stdio.h>
#include <iostream>
using namespace std;


int main() {
	unsigned int numCasos, i;
	int anchoPat, altoPat, anchoAzul, largoAzul, total;
	int nAncho, nLargo;
	
	cin >> numCasos;


	for (i = 0; i < numCasos; ++i)
	{
		cin >> anchoPat >> altoPat >> anchoAzul >> largoAzul;
		nAncho = anchoPat / anchoAzul;
		nLargo = altoPat / largoAzul;
		
		if (anchoPat % anchoAzul != 0) 
		{
			if (altoPat % largoAzul != 0)
			{
				total = (nAncho + 1) * (nLargo + 1);
				cout << total << " NECESITA COMPRAR MAQUINA" << endl;
			}
			else
			{
				total = (nAncho + 1) * nLargo;
				cout << total << " NECESITA COMPRAR MAQUINA" << endl;
			}
		}
		else if (altoPat % largoAzul != 0)
		{
			if (anchoPat % anchoAzul != 0)
			{
				total = (nAncho + 1) * (nLargo + 1);
				cout << total << " NECESITA COMPRAR MAQUINA" << endl;
			}
			else
			{
				total = nAncho * (nLargo + 1);
				cout << total << " NECESITA COMPRAR MAQUINA" << endl;
			}
		}
		else
		{
			total = nAncho * nLargo;
			cout << total << endl;
		}
	}

	return 0;

}