#include <stdio.h>
#include <iostream>
using namespace std;


int main()
{
	unsigned int numCasos, i;
	int n, n1, n2, m;
	cin >> n;
	numCasos = n;

	for (i = 0; i < numCasos; ++i)
	{
		cin >> n1 >> n2;
		m = 0;
		while (n1 <= n2)
		{
			m = m + n1;
			n1++;
		}
		cout << m << endl;
	}
	return 0;

}
