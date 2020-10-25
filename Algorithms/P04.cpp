#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


int main() {
	unsigned int numCasos, i;
	string nomb1, nomb2, nomb3;
	
	cin >> numCasos;


	for (i = 0; i < numCasos; ++i)
	{
		cin >> nomb1 >> nomb2 >> nomb3;

		if ((nomb1 < nomb2) && (nomb1 < nomb3))
		{
			if (nomb2 < nomb3)
			{
				cout << nomb1 << "," << nomb2 << "," << nomb3 << endl;
			}
			else if (nomb3 < nomb2)
			{
				cout << nomb1 << "," << nomb3 << "," << nomb2 << endl;
			}
		}
		else if ((nomb2 < nomb1) && (nomb2 < nomb3))
		{
			if (nomb1 < nomb3)
			{
				cout << nomb2 << "," << nomb1 << "," << nomb3 << endl;
			}
			else if (nomb3 < nomb1)
			{
				cout << nomb2 << "," << nomb3 << "," << nomb1 << endl;
			}
		}
		else if ((nomb3 < nomb1) && (nomb3 < nomb2))
		{
			if (nomb1 < nomb2)
			{
				cout << nomb3 << "," << nomb1 << "," << nomb2 << endl;
			}
			else if (nomb2 < nomb1)
			{
				cout << nomb3 << "," << nomb2 << "," << nomb1 << endl;
			}
		}

	}
	return 0;

} 
