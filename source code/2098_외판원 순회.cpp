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

#define INF 987654321
int n;
int cache[17][1 << 17];
vector<vector<int> > dist;

int tsp(int pos, int visited)
{
	if (visited == (1 << n) - 1)
		return dist[pos][0];

	int &ret = cache[pos][visited];
	if (ret != -1) 
		return ret;
	ret = INF;
	
	for (int i = 0; i < n; i++) 
		if (dist[pos][i] > 0 && (visited & (1 << i)) == 0)
			ret = min(ret, dist[pos][i] + tsp(i, visited | (1 << i)));
	
	return ret;
}

int main(void)
{
	scanf("%d", &n);
	dist = vector<vector<int> >(n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &dist[i][j]);

	memset(cache, -1, sizeof(cache));
	printf("%d\n", tsp(0, 1));
	
	return 0;
}