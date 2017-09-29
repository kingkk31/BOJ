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
	int n, pos = 0, cnt = 1;
	scanf("%d", &n);
	vector<char> vt;
	stack<int> st;
	vector<int> str(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &str[i]);

	while (cnt < n + 1)
	{
		if (st.empty() || st.top() != str[pos])
		{
			st.push(cnt++);
			vt.push_back('+');
		}
		else
		{
			pos++;
			st.pop();
			vt.push_back('-');
		}
	}

	while (!st.empty())
	{
		if (st.top() != str[pos])
		{
			cout << "NO" << endl;
			return 0;
		}
		else
		{
			pos++;
			st.pop();
			vt.push_back('-');
		}
	}

	for (int i = 0; i < vt.size(); i++)
		printf("%c\n", vt[i]);

	return 0;
}