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

int w, h;
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

bool isRange(int y, int x)
{
	if (0 <= y && y < h && 0 <= x && x < w)
		return true;
	return false;
}

int DFS(int y, int x, vector<vector<int> > &vt)
{
	vt[y][x] = 2;

	for (int i = 0; i < 8; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (isRange(ny, nx) && vt[ny][nx] == 1)
			DFS(ny, nx, vt);
	}

	return 1;
}

int main(void)
{
	while (1)
	{
		scanf("%d %d", &w, &h);

		if (w == 0 && h == 0)
			break;

		vector<vector<int> > vt(h, vector<int>(w));
		int cnt = 0;

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				scanf("%d", &vt[i][j]);
		
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if(vt[i][j] == 1)
					cnt += DFS(i,j,vt);
		
		printf("%d\n", cnt);
	}
	return 0;
}