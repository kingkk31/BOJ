#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	int n,m,i,num;
	scanf("%d", &n);

	int *vt = new int[n];
	
	for (i = 0; i < n; i++)
		scanf("%d", vt+i);

	sort(vt, vt + n);

	scanf("%d", &m);

	for (i = 0; i < m; i++)
	{
		scanf("%d", &num);
		
		printf("%d ", binary_search(vt, vt + n, num));
	}
	printf("\n");

	return 0;
}
