#include <stdio.h>
#include <iostream>
using namespace std;


int main()
{
	unsigned int numCasos, i;
	int n, n1, n2, n3, n4, n5, m;
	cin >> n;
	numCasos = n;

	for (i = 0; i < numCasos; ++i)
	{
		cin >> n1 >> n2 >> n3 >> n4 >> n5;
		m = 6*n1 + 8*n2 + 10*n3 + 2*n4*n5;
		cout << m << endl;
	}
	return 0;

}