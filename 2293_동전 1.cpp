#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <malloc.h>
#include <functional>
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;

	vector<int> coin;
	vector<int> cost(k+1, 0);
		
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		coin.push_back(num);
	}

	cost[0] = 1;

	for (int i = 0; i<n; i++)
		for (int j = coin[i]; j <= k; j++)
			cost[j] += cost[j-coin[i]];

	cout << cost[k] << endl;

	return 0;
}
