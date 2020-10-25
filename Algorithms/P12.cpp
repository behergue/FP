#include <iostream>  
using namespace std;
void casoDePrueba()
{
	double peso, pesototal = 0, media = 0;
	int cont1 = 0, cont2 = 0, a = 0;
	const int P = 100000;
	typedef double tPesoNinios[P];
	tPesoNinios pesoNin;

	cin >> peso;
	cin >> pesoNin[0];
	while ((pesoNin[a] != 0) && (a < P))
	{
		a++;
		cin >> pesoNin[a];
		pesototal = pesototal + pesoNin[a - 1];
	}
	media = pesototal / a;
	for (int e = 0; e < a; e++)
	{
		if (pesoNin[e] >= media)
		{
			cont1 = cont1 + 1;
		}
		else if (pesoNin[e] < media)
		{
			cont2 = cont2 + 1;
		}
	}
	if (peso >= media)
	{
		cout << "MAYOR " << cont1 << endl;
	}
	else if (peso < media)
	{
		cout << "MENOR " << cont2 << endl;
	}
	cont1 = 0;
	cont2 = 0;

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