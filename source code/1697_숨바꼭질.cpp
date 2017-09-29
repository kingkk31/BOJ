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

#define INF 987654321

bool isRange(int n)
{
	if (0 <= n && n <= 100000)
		return true;
	return false;
}

void BFS(int a, vector<int> &field)
{
	queue<int> qu;
	qu.push(a);
	field[a] = 0;

	while (!qu.empty())
	{
		int pos = qu.front();
		qu.pop();

		for (int i = 0; i < 3; i++)
		{
			int next;
			switch (i)
			{
			case 0: next = pos + 1;	break;
			case 1: next = pos - 1; break;
			case 2: next = pos * 2; break;
			}

			if (isRange(next) && field[next] > field[pos] + 1)
			{
				field[next] = field[pos] + 1;
				qu.push(next);
			}
		}
	}
}

int main(void)
{
	int a, b;
	cin >> a >> b;
	vector<int> vt(100001, INF);
	BFS(a, vt);
	cout << vt[b] << endl;
	return 0;
}