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
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	int t;
	cin >> t;

	for (int k = 0; k < t; k++) 
	{
		int n, m, cnt = 0;
		cin >> n >> m;

		for (int i = 1; i < n; i++)
		{
			for (int j = i+1; j < n; j++)
			{
				int up = i*i + j*j + m;
				int down = i*j;

				if (up%down == 0)
					cnt++;
			}
		}

		cout << cnt << endl;
	}
	return 0;
}
