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

#define INF 987654321
int n, m;

void floyd(vector<vector<int> > &vt)
{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
		{
			if (vt[i][k] == INF)
				continue;

			for (int j = 0; j < n; j++)
				vt[i][j] = min(vt[i][j], vt[i][k] + vt[k][j]);
		}
}

void print(vector<vector<int> > vt)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (vt[i][j] == INF)
				printf("0 ");
			else
				printf("%d ", vt[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	cin >> n >> m;

	vector<vector<int> > vt(n, vector<int>(n, INF));

	for (int i = 0; i < n; i++)
		vt[i][i] = 0;
	
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vt[a - 1][b - 1] = min(vt[a - 1][b - 1], c);
	}

	floyd(vt);
	print(vt);

	return 0;
}