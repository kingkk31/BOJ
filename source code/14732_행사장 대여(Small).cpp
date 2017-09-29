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
	int n, x1, y1, x2, y2, hall[501][501], cnt = 0;
	scanf("%d", &n);
	memset(hall, -1, sizeof(hall));
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int x = x1; x < x2; x++)
			for (int y = y1; y < y2; y++)
				if (hall[x][y] == -1)
				{
					hall[x][y] = 1;
					cnt++;
				}
	}
	cout << cnt << endl;
	
	return 0;
}