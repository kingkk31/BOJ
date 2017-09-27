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
#include <iterator>
#include <sstream>
#pragma warning(disable:4996)
using namespace std;

#define INF 987654321

int main(void)
{
	int n, arr[100001] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		double score;
		scanf("%lf", &score);
		arr[(int)(score * 1000)]++;
	}

	int cnt = 0;
	for (int i = 0; i < 100001; i++)
	{
		while (arr[i] > 0)
		{
			if (cnt >= 7)
				break;
			cnt++;
			arr[i]--;
			printf("%.3lf\n", ((double)i) * 0.001);
		}
	}

	return 0;
}