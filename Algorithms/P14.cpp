#include <iostream>  
using namespace std;

int main()
{
	int num, i, suma;
	do
	{
		suma = 1;
		cin >> num;

		for (i = 2; suma + i <= num; ++i)
		{
			suma = suma + i;
		}
		if (num == suma)
		{
			cout << num << endl;
		}
	} while (num != 0);
		
	return 0;
}
