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
#include <sstream>
#pragma warning(disable:4996)
using namespace std;

void solve(int &a, int &b, char flag)
{
	if (flag == 'a' || flag == 'b')
	{
		if (b <= a)
			printf("Impossible.\n");
		else
		{
			double c = sqrt((b*b) - (a*a));
			printf("%c = %0.3lf\n", flag, c);
		}
	}
	else //빗변
	{
		double c = sqrt((a*a) + (b*b));
		printf("%c = %0.3lf\n", flag, c);
	}
}

int main(void)
{
	int arr[3];
	int cnt = 0;
	while (true) 
	{
		cnt++;
		if (cnt != 1)
			printf("\n");

		scanf("%d %d %d", arr, arr+1, arr+2);
		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
			break;
		
		printf("Triangle #%d\n", cnt);
		if (arr[0] == -1)
			solve(arr[1], arr[2], 'a');
		else if (arr[1] == -1)
			solve(arr[0], arr[2], 'b');
		else
			solve(arr[0], arr[1], 'c');
	}

	return 0;
}