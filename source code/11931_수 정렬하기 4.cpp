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

int positive[1000001], negative[1000001];

int main(void)
{
	int n;
	cin >> n;

	memset(positive, -1, sizeof(positive));
	memset(negative, -1, sizeof(negative));

	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);

		if (num >= 0)
			positive[num]++;
		else
			negative[num*(-1)]++;
	}

	for (int i = 1000000; i >= 0; i--)
	{
		if (positive[i] != -1)
			printf("%d\n", i);
	}

	for (int i = 1; i < 1000001; i++)
	{
		if (negative[i] != -1)
			printf("%d\n", i*(-1));
	}
	
	return 0;
}