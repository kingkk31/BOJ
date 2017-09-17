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
	int n;
	cin >> n;
	vector<int> vt(n);
	
	for (int i = 0; i < n; i++)
		vt[i] = i + 1;
	
	do {
		for(int i=0;i<n;i++)
			printf("%d ", vt[i]);
		printf("\n");
	} while (next_permutation(vt.begin(), vt.end()));

	return 0;
}