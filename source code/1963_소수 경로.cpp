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

vector<bool> primeArray;
int num[4];
int visited[10000];

void eratos(int n)
{
	if (n <= 1)
		return;

	primeArray = vector<bool>(n + 1, true);
	for (int i = 2; (i*i) <= n; i++)
		if (primeArray[i])
			for (int j = i*i; j <= n; j += i)
				primeArray[j] = false;
}

int solve(int op, int np)
{
	queue<pair<int, int> > qu;
	qu.push(make_pair(op, 0));

	while (!qu.empty())
	{
		pair<int, int> cur = qu.front();
		qu.pop();

		if (cur.first == np)
			return cur.second;

		int temp = cur.first, index = 3;
		while (index >= 0)
		{
			num[index--] = (temp % 10);
			temp /= 10;
		}

		for (int i = 0; i < 4; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				int t = num[i];
				num[i] = (num[i] + j) % 10;
				temp = num[3] + (num[2] * 10) + (num[1] * 100) + (num[0] * 1000);

				if (temp >= 1000 && primeArray[temp] && (visited[temp] == -1))
				{
					visited[temp] = 1;
					qu.push(make_pair(temp, cur.second + 1));
				}

				num[i] = t;
			}
		}
	}

	return -1;
}

int main(void)
{
	eratos(9999);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int op, np;
		scanf("%d %d", &op, &np);
		memset(visited, -1, sizeof(visited));

		int ans = solve(op, np);
		if (ans == -1)
			cout << "Impossible" << endl;
		else
			cout << ans << endl;
	}

	return 0;
}
