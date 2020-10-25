#include <stdio.h>
#include <iostream>
using namespace std;
bool bisiesto (int anio);


int main()
{
	unsigned int numCasos, i;
	int anio;

	cin >> numCasos;


	for (i = 0; i < numCasos; ++i)
	{
		cin >> anio;
			bool bisiesto;
			if ((anio % 4) == 0)
			{
				if (((anio % 100) == 0) && ((anio % 400) != 0))
				{
					bisiesto = false;
					cout << "NO" << endl;
				}
				else
				{
					bisiesto = true;
					cout << "SI" << endl;
				}
			}
			else
			{
				bisiesto = false;
				cout << "NO" << endl;
			}
	}

	return 0;
}
