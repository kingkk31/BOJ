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
	int n, k;
	scanf("%d %d", &n, &k);

	vector<int> vt(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &vt[i]);

	nth_element(vt.begin(), vt.begin() + k - 1, vt.end());
	printf("%d\n", vt[k - 1]);
	
	return 0;
}