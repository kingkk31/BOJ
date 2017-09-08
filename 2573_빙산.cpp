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

#define pp pair<int,int>
int n,m;
int dy[4] = {-1, 0, 0, 1};
int dx[4] = { 0, -1, 1, 0 };

bool isRange(int y, int x)
{
	if (0 <= y && y < n && 0 <= x && x < m)
		return true;
	return false;
}

bool BFS(vector<vector<int> > vt, int cnt)
{
	queue<pp> qu;
	bool ch = false;
	int y, x, temp = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			if (vt[i][j] != 0)
			{
				y = i;
				x = j;
				ch = true;
				break;
			}
		if (ch)
			break;
	}

	qu.push(make_pair(y, x));
	vt[y][x] = 0;
	temp++;

	while (!qu.empty())
	{
		int py = qu.front().first;
		int px = qu.front().second;
		qu.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int ny = py + dy[i];
			int nx = px + dx[i];

			if (isRange(ny, nx) && vt[ny][nx] != 0)
			{
				vt[ny][nx] = 0;
				temp++;
				qu.push(make_pair(ny, nx));
			}
		}
	}

	if (cnt == temp)
		return false;
	else
		return true;	
}

int solve(vector<vector<int> > &vt, vector<vector<bool> > &vt2, int &cnt)
{
	vector<pp> temp;
	
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
		{
			if (!vt2[y][x])
				continue;

			for (int j = 0; j < 4; j++)
			{
				int ny = y + dy[j], nx = x + dx[j];
				if (isRange(ny, nx) && !vt2[ny][nx])
					vt[y][x]--;
			}

			if (vt[y][x] <= 0)
			{
				vt[y][x] = 0;
				temp.push_back(make_pair(y, x));
			}
		}

	for (int i = 0; i < temp.size(); i++)
	{
		int y = temp[i].first, x = temp[i].second;
		vt2[y][x] = false;
		cnt--;
	}

	return 1;
}

int main(void)
{
	cin >> n >> m;
	vector<vector<int> > vt(n, vector<int>(m));
	vector<vector<bool> > vt2(n, vector<bool>(m, false));
	int cnt = 0, year = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &vt[i][j]);
			if (vt[i][j] > 0)
			{
				vt2[i][j] = true;
				cnt++;
			}
		}

	while (1)
	{
		year += solve(vt, vt2, cnt);
		
		if (cnt == 0)
			break;
		
		if (BFS(vt, cnt))
		{
			cout << year << endl;
			return 0;
		}
	}

	cout << 0 << endl;
	
	return 0;
}