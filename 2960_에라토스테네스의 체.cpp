#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <malloc.h>
#include <functional>
#include <time.h>
#include <cctype>
#pragma warning(disable:4996)
using namespace std;

void eratos(int n, int k)
{
	int cnt = 0;

	vector<bool> primeArray(n + 1, true);
	for (int i = 2; i <= n; i++)
		if (primeArray[i])
		{
			primeArray[i] = false;
			cnt++;
			if (cnt == k)
			{
				cout << i << endl;
				return;
			}
			for (int j = i*i; j <= n; j += i)
			{
				if (primeArray[j])
				{
					primeArray[j] = false;
					cnt++;
					if (cnt == k)
					{
						cout << j << endl;
						return;
					}
				}
			}
		}
}

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);
	eratos(n, k);

	return 0;
}