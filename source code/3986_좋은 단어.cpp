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
	int t, cnt = 0;
	scanf("%d", &t);
	while (t--)
	{
		stack<char> st;
		string str;
		cin >> str;

		if (str.length() % 2 != 0)
			continue;
		
		for (int i = 0; i < str.length(); i++)
		{
			if (st.empty() || st.top() != str[i])
				st.push(str[i]);
			else
				st.pop();
		}

		if (st.size() == 0)
			cnt++;
	}
	cout << cnt << endl;

	return 0;
}