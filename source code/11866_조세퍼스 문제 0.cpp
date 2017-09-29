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
	int n, m, cnt;
	scanf("%d %d", &n, &m);
	
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = -1;
	cnt = 0;
	
	int pos = -1;
	printf("<");
	while (cnt != n)
	{
		int i = 0;
		while (i < m)
		{
			pos = (pos + 1) % n;
			if (arr[pos] == -1)
				i++;
		}

		arr[pos] = 1;
		printf("%d", pos + 1);
		if (cnt != n - 1)
			printf(", ");
		cnt++;
	}
	printf(">\n");

	return 0;
}