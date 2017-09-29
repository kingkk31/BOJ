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

struct absSet {
	bool operator()(int left, int right)
	{
		if (abs(left) < abs(right))
			return true;
		else if (abs(left) == abs(right))
			return left < right;
		else
			return false;
	}
};

int main(void)
{
	multiset<int, absSet> st;
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int x;
		scanf("%d", &x);

		if (x == 0)
		{
			if (st.empty())
				printf("0\n");
			else
			{
				printf("%d\n", *(st.begin()));
				st.erase(st.begin());
			}
		}
		else
			st.insert(x);
	}

	return 0;
}