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
	int n, direct = 0, cnt = 1;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (c == 1)
			direct = (direct + 1) % 2;
		
		cnt = (cnt / a) * b;
	}

	cout << direct << " " << cnt << endl;

	return 0;
}