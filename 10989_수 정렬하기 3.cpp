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

	int arr[10001] = { 0 };

	while (n--)
	{
		int num;
		scanf("%d", &num);
		arr[num]++;
	}

	for (int i = 1; i < 10001; i++)
		for (int j = arr[i]; j > 0; j--)
			printf("%d\n", i);

	return 0;
}

