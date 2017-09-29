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
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	int n, m;
	scanf("%d", &n);

	map<int, int> container;

	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		container[num]++;
	}

	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int num;
		scanf("%d", &num);
		printf("%d ", container[num]);
	}

	return 0;
}

