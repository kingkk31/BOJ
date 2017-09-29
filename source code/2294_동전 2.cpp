#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <stack>
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

const int INF = 987654321;

int main(void)
{
	int n, k;
	cin >> n >> k;

	vector<int> coin;
	vector<int> cost(k + 1, INF);

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		coin.push_back(num);
	}

	cost[0] = 1;

	for (int i = 0; i<n; i++)
		for (int j = coin[i]; j <= k; j++)
			cost[j] = min(cost[j], cost[j - coin[i]] + 1);

    if(cost[k] == INF)
        cout<<-1<<endl;
    else
	    cout << cost[k] - 1 << endl;

	return 0;
}