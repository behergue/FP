#include <iostream> 
#include <string>
using namespace std;
typedef char palabra[30];

int main()
{
	palabra letra;
	int a = 0, b = 0;
	bool encontrado = false;
	letra[0] = cin.get();
	while ((encontrado == false) && (a < 30) && (letra[a] != '\n'))
	{
		a++;
		letra[a] = cin.get();
		if (letra[a] == letra[a - 1])
		{
			encontrado = true;
			b = (a - 1);
			cin.ignore(80, '\n');
		}
	}
	while ((letra[0] != 'X') && (letra[1] != 'X') && (letra[2] != 'X'))
	{
		if (encontrado == true)
		{
			cout << b << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
		encontrado = false;
		a = 0;
		letra[0] = cin.get();
		while ((encontrado == false) && (a < 30) && (letra[a] != '\n'))
		{
			a++;
			letra[a] = cin.get();
			if (letra[a] == letra[a - 1])
			{
				encontrado = true;
				b = a - 1;
				cin.ignore(80, '\n');
			}
		}
	}
	return 0;
}
									