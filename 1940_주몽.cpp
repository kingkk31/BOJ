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
	int n, m, cnt = 0;
	scanf("%d %d", &n, &m);

	int *arr = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
		if (binary_search(arr, arr + n, m - arr[i]))
			cnt++;
	
	printf("%d\n", cnt / 2);
	delete(arr);

	return 0;
}