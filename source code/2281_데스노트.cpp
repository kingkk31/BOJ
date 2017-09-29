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
#include <iterator>
#include <sstream>
#pragma warning(disable:4996)
using namespace std;

#define INF 987654321
int n, m, cache[1001][1001];
vector<int> vt;

//원고지의 인덱스는 1~m으로 생각
int solve(int pos, int nameIdx)
{
	if (nameIdx >= n)
		return 0;
	
	//열을 넘어간다면 개행을 하되 (맨 아래 점화식)
	if (pos >= m)
	{
		//커서가 m이면 맨 끝 빈칸에 커서 존재 (빈칸 한 칸)
		int add = (pos == m ? 1 : 0); 
		return solve(vt[nameIdx] + 1, nameIdx + 1) + add;
	}

	int &ret = cache[pos][nameIdx];
	if (ret != -1)
		return ret;
	ret = INF;

	//개행 시 공백 구하기
	ret = solve(vt[nameIdx] + 1, nameIdx + 1) + (m - pos + 1)*(m - pos + 1);
	
	//이어쓸 수 있다면 이어써보기
	if (pos + vt[nameIdx] <= m)
		ret = min(ret, solve(pos + vt[nameIdx] + 1, nameIdx + 1));
	return ret;
}

int main(void)
{
	scanf("%d %d", &n, &m);
	vt = vector<int>(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &vt[i]);
	memset(cache, -1, sizeof(cache));
	cout << solve(vt[0] + 1, 1) << endl;

	return 0;
}