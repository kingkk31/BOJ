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
	int n, num, cnt = 0, maxi = 0;
	int backet[100001] = { 0 };
	scanf("%d", &n);
	
	for (int i = 0; i < n * 2; i++)
	{
		scanf("%d", &num);
		if (backet[num] == 1)
			cnt--;
		else
		{
			backet[num] = 1;
			cnt++;
		}
		maxi = max(maxi, cnt);
	}
	cout << maxi << endl;

	return 0;
}