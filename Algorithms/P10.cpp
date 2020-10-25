#include <iostream>  
using namespace std;  

void casoDePrueba()
{
	long long int num;
	int suma1, suma2, resto1, resto2, total;
	suma1 = 0;
	suma2 = 0;
	cin >> num;
	while ((9 < num) && (num != 0))
	{
		resto1 = num % 10;
		suma1 = suma1 + resto1;
		num = num / 10;
	}
	if (num <= 9)
	{
		suma1 = suma1 + num;
	}
	while (9 < suma1)
	{
		resto2 = suma1 % 10;
		suma2 = suma2 + resto2;
		suma1 = suma1 / 10;
	}
	total = suma1 + suma2;
	cout << total << endl;
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
