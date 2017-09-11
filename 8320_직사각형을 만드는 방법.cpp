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
	int n, cnt = 0;
	cin >> n;
	
	for (int i = 1; (i*i) <= n; i++)
		for (int j = i; i*j <= n; j++)
			cnt++;
	
	cout << cnt << endl;

	return 0;
}