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
vector<vector<int> > via;

void floyd(vector<vector<int> > &vt)
{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (vt[i][j] > vt[i][k] + vt[k][j])
				{
					via[i][j] = k;
					vt[i][j] = vt[i][k] + vt[k][j];
				}
			}
}

void reconstruct(int i, int j, vector<int> &path)
{
	if (via[i][j] == -1)
	{
		if (i != j)
		{
			path.push_back(i);
			path.push_back(j);

		}
	}
	else
	{
		int w = via[i][j];
		reconstruct(i, w, path);
		path.pop_back();
		reconstruct(w, j, path);
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

void footPrint(vector<vector<int> > vt)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (vt[i][j] == 0 || vt[i][j] == INF)
			{
				printf("0\n");
				continue;
			}

			vector<int> path;
			reconstruct(i, j, path);

			printf("%d ", path.size());
			for (int k = 0; k < path.size(); k++)
				printf("%d ", path[k] + 1);
			printf("\n");
		}
}

int main(void)
{
	cin >> n >> m;

	vector<vector<int> > vt(n, vector<int>(n, INF));
	via = vector<vector<int> >(n, vector<int>(n,-1));

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
	footPrint(vt);	
	
	return 0;
}