#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <assert.h>
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int m, n, x, y, k=-1;
		cin >> m >> n >> x >> y;

		int a = 0;

		while (x + a * m <= m * n)
		{
			if (((x + a * m) % n == y) || ((x + a * m) % n == 0 && n == y))
			{
				k = a * m + x;
				break;
			}

			a++;
		}

		cout << k << endl;
	}

	return 0;
}