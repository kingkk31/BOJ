#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int cnt = 0;

	int a = 1;

	for (int i = 1; i <= n; i++)
	{
		a *= i;
		while (a % 10 == 0)
		{
			cnt++;
			a = a / 10;
		}
		a = a % 10;
	}

	cout << cnt << endl;

	return 0;
}