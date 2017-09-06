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

void solve(int n)
{
	int cnt = 0;
	for (int i = 1; ; i++)
	{
		int h = i;
		while (h > 0)
		{
			cnt++;
			if (cnt == n)
			{
				if (i % 2 == 1)
					printf("%d/%d\n", h, (i - h) + 1);
				else
					printf("%d/%d\n", (i - h) + 1, h);
				return;
			}
			h--;
		}
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	solve(n);	

	return 0;
}