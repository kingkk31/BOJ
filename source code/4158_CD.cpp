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
	int n, m;
	while (1)
	{
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0)
			break;

		int i, j = 0, num, cnt = 0;
		int arr[1000001];

		for (i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		arr[i] = 1000000001;
	
		for (i = 0; i < m; i++)
		{
			scanf("%d", &num);
			while(arr[j] < num)
				j++;
			
			if(arr[j] == num)
				cnt++;
		}

		printf("%d\n", cnt);
	}

	return 0;
}