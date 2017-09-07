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

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int n, m, maxi;
vector<string> vt;
vector<bool> check;

bool isRange(int y, int x)
{
	if (0 <= y && y < n && 0 <= x && x < m)
		return true;
	return false;
}

void solve(int y, int x, int &cnt)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (isRange(ny, nx) && !check[(vt[ny][nx] - 'A')])
		{
			cnt++;
			check[(vt[ny][nx] - 'A')] = true;
			maxi = max(maxi, cnt);
			solve(ny, nx, cnt);
			check[(vt[ny][nx] - 'A')] = false;
			cnt--;
		}
	}	
}

int main(void)
{
	cin >> n >> m;
	vt = vector<string>(n);
	
	for (int i = 0; i < n; i++)
		cin >> vt[i];
	
	check = vector<bool>(26, false);

	int cnt = 1;
	maxi = 1;
	check[(vt[0][0] - 'A')] = true;
	solve(0, 0, cnt);

	cout << maxi << endl;

	return 0;
}