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
	stack<char> st;
	int cnt = 0;
	string str;
	cin >> str;
	
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ')')
		{
			if (st.empty())
				cnt++;
			else
				st.pop();
		}
		else
			st.push(str[i]);
	}
	cnt += st.size();
	cout << cnt << endl;	

	return 0;
}