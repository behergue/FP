#include <iostream>  
#include <ctype.h> 
#include <string>
using namespace std;    
void casoDePrueba()
{
	int i;
	string palabra;
	cin >> palabra;
	for (i = 0; palabra[i]; i++)
	{
		palabra[i] = tolower(palabra[i]);
	}
	cout << palabra << endl;

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
