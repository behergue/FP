#include <stdio.h>
#include <iostream>
using namespace std;


int main() {
	unsigned int numCasos, i;
	int dividendo, divisor, cociente, resto;

	cin >> numCasos;


	for (i = 0; i < numCasos; ++i)
	{
		cin >> dividendo >> divisor;
		if (divisor == 0)
		{
			cout << "DIV0" << endl;
		}
		else if (divisor != 0)
		{
			cociente = dividendo / divisor;
			resto = dividendo % divisor;

			if ((resto != 0) && (dividendo < 0))
			{
				if (divisor < 0)
				{
					cociente = cociente + 1;
					resto = resto - divisor;
					cout << cociente << " " << resto << endl;
				}
				else if (0 < divisor)
				{
					cociente = cociente - 1;
					resto = resto + divisor;
					cout << cociente << " " << resto << endl;

				}
			}
			else
			{
				cout << cociente << " " << resto << endl;
			}	
		}
	}

	return 0;

} 
