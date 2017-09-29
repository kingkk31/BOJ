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

int main(void)
{
	int n;
	cin >> n;

	list<int> qu;
	for (int i = 0; i < n; i++)
	{
		string query;
		cin >> query;

		if (query == "push")
		{
			int num;
			cin >> num;
			qu.push_back(num);
		}
		else if (query == "pop")
		{
			if (qu.empty())
				cout << -1 << endl;
			else
			{
				cout << *(qu.begin()) << endl;
				qu.pop_front();
			}
		}
		else if (query == "size")
			cout << qu.size() << endl;
		else if (query == "empty")
			if (qu.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		else if (query == "front")
		{
			if (qu.empty())
				cout << -1 << endl;
			else
				cout << *(qu.begin()) << endl;
		}
		else
		{
			if (qu.empty())
				cout << -1 << endl;
			else
				cout << *(--qu.end()) << endl;
		}
	}

	return 0;
}