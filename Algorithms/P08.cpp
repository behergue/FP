#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


int main()
{
	unsigned int numCasos, b;
	string palabra;
	bool ifA, ifE, ifI, ifO, ifU;
	cin >> numCasos;


	for (b = 0; b < numCasos; ++b)
	{
		cin >> palabra;
		for (int c = 0; c < palabra.size(); c++)
		{
			if (palabra[c] == 'a') 
			{
				ifA = true;
			}
			if (palabra[c] == 'e') 
			{
				ifE = true;
			}
			if (palabra[c] == 'i') 
			{
				ifI = true;
			}
			if (palabra[c] == 'o') 
			{
				ifO = true;
			}
			if (palabra[c] == 'u') 
			{
				ifU = true;
			}
		}
		if ((ifA == true) && (ifE == true) && (ifI == true) && (ifO == true) && (ifU == true)) 
		{
			cout << "SI" << endl;
		}
		else 
		{
			cout << "NO" << endl;
		}
		ifA = false, ifE = false, ifI = false, ifO = false, ifU = false;

	}
	return 0;

}