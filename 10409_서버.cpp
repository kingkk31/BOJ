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
	int n, t, sum = 0, num;
	scanf("%d %d", &n, &t);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		if (sum + num > t)
		{
			printf("%d\n", i);
			return 0;
		}
		sum += num;
	}
	printf("%d\n", n);

	return 0;
}