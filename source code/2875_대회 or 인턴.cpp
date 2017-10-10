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
	int n, m, k, team = 0;
	scanf("%d %d %d", &n, &m, &k);
	
	while (n >= 2 && m >= 1)
	{
		n -= 2; m -= 1;
		team++;
	}
	
	k = k - n - m;
	while (k > 0)
	{
		k -= 3;
		team--;
	}
	cout << team << endl;

	return 0;
}