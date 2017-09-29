#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <malloc.h>
#include <functional>
#pragma warning(disable:4996)
using namespace std;

int N;
const int INF = -1;

int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool isRange(int y, int x)
{
	if (0 <= y&&y < N && 0 <= x&&x < N)
		return true;

	return false;
}

int main(void)
{	
	cin >> N;
	vector <vector<char> > vt(N,vector<char>(N));
	vector <vector<int> > mine(N, vector<int>(N,0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> vt[i][j];

			if (vt[i][j] != '.')
				mine[i][j] = INF;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (vt[i][j] != '.')
				continue;

			for (int k = 0; k < 8; k++)
			{
				int ny = i + dy[k];
				int nx = j + dx[k];
				
				if (isRange(ny, nx) && vt[ny][nx] != '.')
				{
					int num = (int)vt[ny][nx] - '0';
					mine[i][j] += num;
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (mine[i][j] == INF)
				cout << '*';
			else if (mine[i][j] >= 10)
				cout << 'M';
			else
				cout << mine[i][j];
		}
		cout << endl;
	}

	return 0;
}
