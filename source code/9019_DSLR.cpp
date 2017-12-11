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
#include <fstream>
#pragma warning(disable:4996)
using namespace std;

#define INF 987654321

int a, b;
vector<string> command;

int D(int n)
{
	return (2 * n) % 10000;
}

int S(int n)
{
	return (n == 0 ? 9999 : n - 1);
}

int L(int n)
{
	return (n % 1000) * 10 + (n / 1000);
}

int R(int n)
{
	return (n / 10) + (n % 10) * 1000;
}

string bfs()
{
	command = vector<string>(10000, "");
	queue<int> qu;
	qu.push(a);	

	while (!qu.empty())
	{
		int cur = qu.front();
		string com = command[cur];
		qu.pop();

		if (cur == b)
			return com;

		if (command[D(cur)] == "")
		{
			command[D(cur)] = com + "D";
			qu.push(D(cur));
		}

		if (command[S(cur)] == "")
		{
			command[S(cur)] = com + "S";
			qu.push(S(cur));
		}

		if (command[L(cur)] == "")
		{
			command[L(cur)] = com + "L";
			qu.push(L(cur));
		}

		if (command[R(cur)] == "")
		{
			command[R(cur)] = com + "R";
			qu.push(R(cur));
		}
	}
}

int main(void)
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &a, &b);
		cout << bfs() << endl;
	}

	return 0;
}