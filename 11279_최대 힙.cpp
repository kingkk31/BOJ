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

#define INF 987654321

int main(void)
{
	int n, num;
	scanf("%d", &n);
	
	multiset<int> st;
	while (n--)
	{
		scanf("%d", &num);
		if (num == 0)
		{
			if (st.empty())
				printf("0\n");
			else
			{
				printf("%d\n", *(--st.end()));
				st.erase(--st.end());
			}
		}
		else
			st.insert(num);
	}

	return 0;
}