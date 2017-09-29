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
int cache[1001][1001];
string str;

int solve(int pos, char word, int k)
{
	if (pos == n - 1)
		return k*k;
	
	int &ret = cache[pos][k];
	if (ret != -1)
		return ret;
	ret = INF;

	char next_word;
	switch (word)
	{
	case 'B': next_word = 'O'; break;
	case 'O': next_word = 'J'; break;
	case 'J': next_word = 'B'; break;
	}

	for (int i = pos + 1; i < n; i++)
	{
		if (str[i] == next_word)
			ret = min(ret, k*k + solve(i, next_word, i - pos));
	}

	return ret;
}

int main(void)
{
	cin >> n >> str;
	memset(cache, -1, sizeof(cache));
	int power = solve(0, 'B', 0);
	if (power == INF)
		cout << -1 << endl;
	else
		cout << power << endl;
	
	return 0;
}