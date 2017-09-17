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
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;
		scanf("%d %d", &m, &n);
		
		printf("1\n");
		if (m % 2 == 0)
		{
			for (int i = 0; i < m; i++)
			{
				if (i % 2 == 0)
					for (int j = 0; j < n; j++)
						printf("(%d,%d)\n", i, j);
				else
					for (int j = n - 1; j >= 0; j--)
						printf("(%d,%d)\n", i, j);
			}
		}
		else
		{
			for (int i = 0; i < n; i++)
				printf("(0,%d)\n", i);

			for (int i = 1; i < m; i++)
			{
				if (i % 2 == 0)
					for (int j = 1; j < n; j++)
						printf("(%d,%d)\n", i, j);
				else
					for (int j = n - 1; j > 0; j--)
						printf("(%d,%d)\n", i, j);
			}
					
			for (int i = m - 1; i > 0; i--)
				printf("(%d,0)\n", i);
		}
	}

	return 0;
}