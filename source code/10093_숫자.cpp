#include <iostream>
using namespace std;

int main(void)
{
	unsigned long long  a, b;
	cin >> a >> b;
	if (a == b)
	{
		cout << "0" << endl;
		cout << endl;
		return 0;
	}
	
	if (a > b)
	{
		unsigned long long temp;
		temp = a;
		a = b;
		b = temp;
	}
	cout << (b - a) - 1 << endl;
	if ((b - a) - 1 == 0)
	{
		cout << endl;
		return 0;
	}
	for (unsigned long long i = a + 1; i < b; i++)
	{
		cout <<i;
		if (i != b-1)
		{
			cout << " ";
		}
	}
	cout << endl;
	return 0;
}