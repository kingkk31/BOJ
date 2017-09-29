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
	int n;
	cin >> n;

	for (int j = 0; j < n; j++)
	{
		if (j % 2 == 0)
		{
			for (int i = 0; i < 2 * n; i++)
			{
				if (i % 2 == 0)
					printf("*");
				else
					printf(" ");
			}
		}
		else
		{
			for (int i = 0; i < 2 * n; i++)
			{
				if (i % 2 == 0)
					printf(" ");
				else
					printf("*");
			}
		}
		printf("\n");
	}
	
	return 0;
}