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

	for (int a = 1; a <= n; a++)
	{
		for (int i = n - a; i > 0; i--)
			printf(" ");
		printf("*");
		if (a == 1)
		{
			printf("\n");
			continue;
		}
		for (int j = 0; j < 2 * (a - 1) - 1; j++)
			printf(" ");
		printf("*\n");
	}

	return 0;
}