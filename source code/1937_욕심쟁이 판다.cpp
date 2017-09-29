#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

int n;
vector<vector<int> > vt;
int cache[501][501];
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};

bool isRange(int y, int x)
{
	if(0 <= y && y < n && 0 <= x && x < n)
		return true;
	return false;
}

int solve(int y, int x)
{
	int &ret = cache[y][x];
	if(ret != -1)
		return ret;
	ret = 0;
	
	for(int i=0;i<4;i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(isRange(ny, nx) && vt[y][x] < vt[ny][nx])
			ret = max(ret, solve(ny, nx) + 1);
	}
	
	return ret;
}

int main(void)
{
	scanf("%d", &n);
	vt = vector<vector<int> >(n, vector<int>(n));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d", &vt[i][j]);
			
	int maxi = 0;
	memset(cache, -1, sizeof(cache));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			maxi = max(maxi, solve(i, j) + 1);
	cout<<maxi<<endl;
}