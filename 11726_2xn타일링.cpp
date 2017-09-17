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
#include <functional>
using namespace std;

int cache[1001];

int solve(int w)
{
	if(w <= 1)
		return 1;

	int &ret = cache[w];
	if(ret != -1)
		return ret;
	ret = 0;

	ret = ((solve(w-2)%10007) + (solve(w-1)%10007)%10007);
	return ret;
}

int main(void)
{
	int n;
	cin >> n;
	memset(cache, -1, sizeof(cache));
	cout << solve(n)%10007 << endl;
	return 0;
}
