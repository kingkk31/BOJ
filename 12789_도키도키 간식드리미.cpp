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
	int n, pre = 0;
	cin >> n;

	queue<int> qu;
	stack<int> st;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		qu.push(num);
	}

	while (!qu.empty())
	{
		if (!st.empty() && st.top() == pre + 1)
		{
			pre = st.top();
			st.pop();
		}
		else if (qu.front() == pre + 1)
		{
			pre = qu.front();
			qu.pop();
		}
		else
		{
			st.push(qu.front());
			qu.pop();
		}				
	}

	while (!st.empty())
	{
		if (st.top() != pre + 1)
			break;

		pre = st.top();
		st.pop();
	}

	if (st.empty())
		cout << "Nice" << endl;
	else
		cout << "Sad" << endl;

	return 0;
}