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

int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };
int n;

bool isRange(int y, int x)
{
	if (0 <= y && y < n && 0 <= x && x < n)
		return true;
	return false;
}

int solve(int y, int x, vector<string> vt)
{
	int beside[4] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		while (isRange(ny, nx) && (vt[y][x] == vt[ny][nx]))
		{
			beside[i]++;
			ny += dy[i];
			nx += dx[i];
		}
	}

	return ((beside[0] + beside[3]) > (beside[1] + beside[2]) ? (beside[0] + beside[3]) : (beside[1] + beside[2])) + 1;
}

int main(void)
{
	int candy = 0;
	cin >> n;
	
	vector<string> vt(n);
	for (int i = 0; i < n; i++)
		cin >> vt[i];

	for (int i = 0; i < (n - 1); i++)
	{
		for (int j = 0; j < n; j++)
		{
			swap(vt[i][j], vt[i + 1][j]);
			candy = max(candy, max(solve(i,j, vt), solve(i+1, j, vt)));
			swap(vt[i][j], vt[i + 1][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (n - 1); j++)
		{
			swap(vt[i][j], vt[i][j + 1]);
			candy = max(candy, max(solve(i, j, vt), solve(i, j + 1, vt)));
			swap(vt[i][j], vt[i][j + 1]);
		}
	}

	cout << candy << endl;

    return 0;
}