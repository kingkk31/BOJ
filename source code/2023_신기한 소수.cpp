#include <iostream>
#include <math.h>

using namespace std;

int N;

void check1(int n)
{
	if (n > 9)
	{
		if (n % 2 == 0)
			return;
	}
	
	for (int i = 3; i <= sqrt((double)n); i += 2)
	{
		if (n%i == 0)
		{
			return;
		}
	}

	if (n >= pow((double)10, N - 1) && n < pow((double)10, N))
	{
		cout << n << endl;
		return;
	}

	for (int j = 0; j < 10; j++)
	{
		check1((n * 10)+j);
	}
}

int main(void)
{
	cin >> N;
	check1(2);
	check1(3);
	check1(5);
	check1(7);
	
	return 0;
}