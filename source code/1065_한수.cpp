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

set<int> st;

void solve(int d, int n)
{
	st.insert(n);
	if ((n % 10) + d >= 0 && (n % 10) + d < 10 && (n * 10 + ((n % 10) + d)) <= 1000)
		solve(d, n * 10 + ((n % 10) + d));
}

int main(void)
{
	for (int i = -9; i < 10; i++)
		for (int j = 1; j < 10; j++)
			solve(i, j);
	
	int n, cnt = 0;
	scanf("%d", &n);

	set<int>::iterator itr = st.begin();
	while (itr != st.end() && *itr <= n)
	{
		cnt++;
		itr++;
	}
	cout << cnt << endl;

	return 0;
}