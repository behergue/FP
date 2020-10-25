#include <iostream>  
using namespace std;
void casoDePrueba()
{
	int num1, num2, a, cont = 0;
	cin >> num1;
	for (a = 0; a < num1; a++)
	{
		cin >> num2;
		if (num2 % 2 == 0)
		{
			cont++;
		}
	}
	cout << cont << endl;

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
