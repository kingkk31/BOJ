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
	scanf("%d", &n);
	
	while (n--)
	{
		char str[1000003];
		scanf("%s", str);
		int len = strlen(str);

		stack<char> st, temp;
		for (int i = 0; i < len; i++)
		{
			if (str[i] == '<')
			{
				if (!st.empty())
				{
					temp.push(st.top());
					st.pop();
				}
			}
			else if (str[i] == '>')
			{
				if (!temp.empty())
				{
					st.push(temp.top());
					temp.pop();
				}
			}
			else if (str[i] == '-')
			{
				if (!st.empty())
					st.pop();
			}
			else
				st.push(str[i]);
		}

		while (!temp.empty())
		{
			st.push(temp.top());
			temp.pop();
		}

		char *result = new char[st.size()+1];
		int pos = st.size() - 1;
		result[st.size()] = '\0';
		while (!st.empty())
		{
			result[pos--] = st.top();
			st.pop();
		}		
		printf("%s\n", result);
	}

	return 0;
}