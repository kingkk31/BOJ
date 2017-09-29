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

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector<vector<int> > vt(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> vt[i][j];
	
	int k, a, b, c, d;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int total = 0;
		cin >> a >> b >> c >> d;
		
		for (int x = a - 1; x < c; x++)
			for (int y = b - 1; y < d; y++)
				total += vt[x][y];
		cout << total << endl;
	}

	return 0;
}