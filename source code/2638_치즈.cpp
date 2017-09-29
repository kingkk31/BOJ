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
#pragma warning(disable:4996)
using namespace std;

int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };
int n, m, cheeze;

bool isRange(int y, int x)
{
	if (0 <= y && y < n && 0 <= x && x < m)
		return true;
	return false;
}

void dfs(vector<vector<int> > &vt, int y, int x)
{
	vt[y][x] = 2;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (isRange(ny, nx) && vt[ny][nx] == 0)
			dfs(vt, ny, nx);
	}
}

vector<vector<int> > solve(vector<vector<int> > vt)
{
	vector<pair<int, int> > temp, temp2;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		if (vt[i][j] == 0)
		{
			for (int a = 0; a < 4; a++)
			{
				int ny = i + dy[a];
				int nx = j + dx[a];
				if (isRange(ny, nx) && vt[ny][nx] == 2)
					dfs(vt, i, j);
			}
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (vt[i][j] == 2)
				continue;
			else if (vt[i][j] == 1) 
			{
				int ch = 0;
				for (int a = 0; a < 4; a++)
				{
					if (ch >= 2)
						break;
					int ny = i + dy[a];
					int nx = j + dx[a];
					if (isRange(ny, nx) && vt[ny][nx] == 2)
						ch++;
				}
				if (ch >= 2)
					temp.push_back(make_pair(i, j));
			}
				
		}
	
	for (int i = 0; i < temp.size(); i++)
	{
		vt[temp[i].first][temp[i].second] = 2; //없어지는 치즈
		cheeze--;
	}
	vector<vector<int> > vt2 = vt;
	return vt2;
}

int main(void)
{
	cin >> n >> m;

	vector<vector<int> > vt(n, vector<int>(m));
	int cnt = 0;
	cheeze = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &vt[i][j]);
			if (vt[i][j] == 1)
				cheeze++;
		}
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (0 < i && i < n - 1 && 0 < j && j < m - 1)
				continue;
			if (vt[i][j] == 0)
				dfs(vt, i, j);
		}//바깥 공기

	while (true)
	{
		cnt++;
		vt = solve(vt);
		
		if (cheeze == 0)
			break;
	}

	cout << cnt << endl;

	return 0;
}