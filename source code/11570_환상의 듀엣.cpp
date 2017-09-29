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
int cache[2001][2001];
vector<int> vt;

int solve(int pos1, int pos2)
{
	if (pos1 == n || pos2 == n)
		return 0;

	int &ret = cache[pos1][pos2];
	if (ret != -1)
		return ret;
	ret = INF;

	int next = max(pos1, pos2) + 1;
	ret = min(ret, (pos1 ? abs(vt[pos1] - vt[next]) : 0) + solve(next, pos2));
	ret = min(ret, (pos2 ? abs(vt[pos2] - vt[next]) : 0) + solve(pos1, next));
	//다음을 향해 한칸 한칸 검사한다

	return ret;
}

int main(void)
{
	scanf("%d", &n);
	memset(cache, -1, sizeof(cache));
	
	vt = vector<int>(n + 1);
	vt[0] = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d", &vt[i]);
	
	cout << solve(0, 0) << endl;

	return 0;
}
