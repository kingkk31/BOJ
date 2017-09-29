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
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		double total = 0, gpa = 0;
		for (int j = 0; j < n; j++)
		{
			double a, b;
			scanf("%lf %lf", &a, &b);
			total += a;
			gpa += (a*b);
		}
		
		printf("%d %0.1lf\n", (int)total, gpa / total);
	}	
	
	return 0;
}