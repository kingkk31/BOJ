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

void floyd(int n, vector<vector<int> > &vt)
{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (vt[i][j] == 1)
					continue;
				if (vt[i][k] == 1 && vt[k][j] == 1)
					vt[i][j] = 1;
			}
}


int main(void)
{
	int n;
	cin >> n;

	vector<vector<int> > vt(n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &vt[i][j]);

	floyd(n, vt);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", vt[i][j]);
		printf("\n");
	}
	return 0;
}
