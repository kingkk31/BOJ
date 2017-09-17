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

vector<unsigned long long> solve(vector<unsigned long long> vt, int n)
{
	vector<unsigned long long> temp(211, 0);
	int pos = 0;
	while (vt[pos] != 0)
	{
		for (int j = 0; j <= n; j++)
			temp[pos+j] += vt[pos];
		pos++;
	}
	return temp;
}

int main(void)
{
	int t;
	cin >> t;
	while (t--) 
	{
		int n, k;
		cin >> n >> k;
		vector<unsigned long long> vt(211, 0);
		vt[0] = 1;
		for (int i = 1; i <= n; i++)
			vt = solve(vt, i);
		printf("%llu\n", vt[k]);
	}

	return 0;
}