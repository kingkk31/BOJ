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
#include <sstream>
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	int n, shortest[21][21];
	scanf("%d", &n);

	bool bridge[21][21];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			bridge[i][j] = false;
			scanf("%d", &shortest[i][j]);
		}

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (i == j || i == k || k == j)
					continue;
			
				if (shortest[i][k] + shortest[k][j] < shortest[i][j])
				{
					printf("-1\n");
					return 0;
				}

				if (shortest[i][k] + shortest[k][j] == shortest[i][j])
					bridge[i][j] = true;
			}
	
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if(!bridge[i][j])
				ans += shortest[i][j];
	printf("%d\n", ans);

	return 0;
}