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
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	while (1)
	{
		double a, b;
		scanf("%lf %lf", &a, &b);

		if (a == 0 && b == 0)
			break;

		double r = b / a;
		double V = sqrt(1 - (r*r));
		printf("%0.3lf\n", V);
	}
	
	return 0;
}