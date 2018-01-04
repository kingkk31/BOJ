#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int cnt2 = 0, cnt5 = 0;

	for (int i = 1; i <= n; i++)
	{
		int t = i, c2 = 0, c5 = 0;

		while (t % 5 == 0)
		{
			c5++;
			t /= 5;
		}

		while (t % 2 == 0)
		{
			c2++;
			t /= 2;
		}

		cnt2 += c2;
		cnt5 += c5;
	}

	cout << min(cnt2, cnt5) << endl;

	return 0;
}