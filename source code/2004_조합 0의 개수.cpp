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
	int n, m, temp, top2 = 0, top5 = 0, bottom2 = 0, bottom5 = 0;
	cin >> n >> m;

	temp = n - m;
	if (m > temp)
		swap(m, temp);

	for (int i = 1; pow(2.0, i) <= n; i++)
		top2 += n / pow(2.0, i);
	for (int i = 1; pow(5.0, i) <= n; i++)
		top5 += n / pow(5.0, i);
	
	for (int i = 1; pow(2.0, i) <= m; i++)
		bottom2 += m / pow(2.0, i);
	for (int i = 1; pow(5.0, i) <= m; i++)
		bottom5 += m / pow(5.0, i);

	for (int i = 1; pow(2.0, i) <= temp; i++)
		bottom2 += temp / pow(2.0, i);
	for (int i = 1; pow(5.0, i) <= temp; i++)
		bottom5 += temp / pow(5.0, i);

	printf("%d\n", top2 - bottom2 < top5 - bottom5 ? top2 - bottom2 : top5 - bottom5);

	return 0;
}