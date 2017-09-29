#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int N;
int cache[101][10];

int solve(int len, int num)
{
	if (len == N)
		return 1;

	int &ret = cache[len][num];

	if (ret != -1)
		return ret;

	ret = 0;

	if (num + 1 < 10)
		ret += solve(len + 1, num + 1);

	if (num - 1 >= 0)
		ret += solve(len + 1, num - 1);

	ret %= 1000000000;

	return ret;
 }

int main()
{
	cin >> N;

 	memset(cache, -1, sizeof(cache));
	
 	int cnt = 0;

	for (int i = 1; i < 10; i++)
	{
		cnt += solve(1, i);
		cnt %= 1000000000;
 	}

	cout << cnt << endl;

 	return 0;
}